#include "SDCCralloc.hpp"
#include "SDCCsalloc.hpp"

extern "C"
{
  #include "z80.h"
  float dryZ80iCode (iCode * ic);
  bool z80_assignment_optimal;
  bool should_omit_frame_ptr;
}

#define REG_A 0
#define REG_C 1
#define REG_B 2
#define REG_E 3
#define REG_D 4
#define REG_L 5
#define REG_H 6
#define REG_IYL 7
#define REG_IYH 8


void getIndex(vector<var_t> v, int K) 
{ 
    auto it = find(v.begin(), v.end(), K); 
  
    // If element was found 
    if (it != v.end())  
    { 
      
        // calculating the index 
        // of K 
        int index = it - v.begin(); 
        cout << index << endl; 
    } 
    else { 
        // If the element is not 
        // present in the vector 
        cout << "-1" << endl; 
    } 
} 

template <class I_t>
float default_operand_cost(const operand *o, const i_assignment_ps &a, const cfg_node &node, const I_t &I)
{
  float c = 0.0f;

  operand_map_t::const_iterator oi, oi_end;

  var_t byteregs[4];    // Todo: Change this when sdcc supports variables larger than 4 bytes in registers.
  unsigned short int size;

  if(o && IS_SYMOP(o))
    {
      boost::tie(oi, oi_end) = node.operands.equal_range(OP_SYMBOL_CONST(o)->key);
      if(oi != oi_end)
        {
          var_t v = oi->second;

          // In registers.
          if(std::binary_search(a.registers_begin.begin(), a.registers_begin.end(), v))
            {
              c += 1.0f;
              byteregs[I[v].byte] = getIndex(a.registers_begin,v);
              size = 1;

              while(++oi != oi_end)
                {
                  v = oi->second;
                  c += (std::binary_search(a.registers_begin.begin(),a.registers_begin.end(), v) ? 1.0f : std::numeric_limits<float>::infinity());
                  byteregs[I[v].byte] = getIndex(a.registers_begin,v);
                  size++;
                }

              // Penalty for not placing 2- and 4-byte variables in register pairs
              // Todo: Extend this once the register allocator can use registers other than bc, de:
              if ((size == 2 || size == 4) &&
                  (byteregs[1] != byteregs[0] + 1 || (byteregs[0] != REG_C && byteregs[0] != REG_E && byteregs[0] != REG_L)))
                c += 2.0f;
              if (size == 4 &&
                  (byteregs[3] != byteregs[2] + 1 || (byteregs[2] != REG_C && byteregs[2] != REG_E && byteregs[0] != REG_L)))
                c += 2.0f;

              // Code generator cannot handle variables only partially in A.
              if(size > 1)
                for(unsigned short int i = 0; i < size; i++)
                  if(byteregs[i] == REG_A)
                    c += std::numeric_limits<float>::infinity();

              if(byteregs[0] == REG_A)
                c -= 0.4f;
              else if(byteregs[0] == REG_L)
                c -= 0.1f;
              else if((OPTRALLOC_IY && byteregs[0] == REG_IYL) || byteregs[0] == REG_IYH)
                c += 0.1f;
            }
          // Spilt.
          else
            {
              c += OP_SYMBOL_CONST(o)->remat ? 1.5f : 4.0f;
              while(++oi != oi_end)
                {
                  v = oi->second;
                  c += (!std::binary_search(a.registers_begin.begin(),a.registers_begin.end(), v) ? 4.0f : std::numeric_limits<float>::infinity());
                }
            }
        }
    }

  return(c);
}

// Check that the operand is either fully in registers or fully in memory.
template < class I_t>
static bool operand_sane(const operand *o, const i_assignment_ps &a, const cfg_node &node, const I_t &I)
{
  if(!o || !IS_SYMOP(o))
    return(true);
 
  operand_map_t::const_iterator oi, oi_end;
  boost::tie(oi, oi_end) = node.operands.equal_range(OP_SYMBOL_CONST(o)->key);
  
  if(oi == oi_end)
    return(true);
  
  // In registers.
  if(std::binary_search(a.registers_begin.begin(), a.registers_begin.end(), oi->second))
    {
      while(++oi != oi_end)
        if(!std::binary_search(a.registers_begin.begin(), a.registers_begin.end(), oi->second))
          return(false);
    }
  else
    {
       while(++oi != oi_end)
        if(std::binary_search(a.registers_begin.begin(), a.registers_begin.end(), oi->second))
          return(false);
    }
 
  return(true);
}



template <class G_t, class I_t>
static float default_instruction_cost(const i_assignment_ps &a, const cfg_node &node, const I_t &I)
{
  float c = 0.0f;

  const iCode *ic = node.ic;

  c += default_operand_cost(IC_RESULT(ic), a, node, I);
  c += default_operand_cost(IC_LEFT(ic), a, node, I);
  c += default_operand_cost(IC_RIGHT(ic), a, node, I);

  return(c);
}


template <class G_t, class I_t>
static bool inst_sane(const assignment &a,const cfg_node &node, const I_t &I)
{
  const iCode *ic = node.ic;

  // for a sequence of built-in SENDs, all of the SENDs must be sane
  //if (ic->op == SEND && ic->builtinSEND && ic->next->op == SEND && !inst_sane(a, *(adjacent_vertices(i, G).first), G, I))
  //  return(false);
  //todo : how to check sequence of built-in SENDs?
  if (ic->op == SEND && ic->builtinSEND && ic->next->op == SEND )
    return(false);

  return(operand_sane(IC_RESULT(ic), a, i, G, I) && operand_sane(IC_LEFT(ic), a, i, G, I) && operand_sane(IC_RIGHT(ic), a, i, G, I));
}

