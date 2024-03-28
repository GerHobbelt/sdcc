#define TD_SALLOC
#define CH_SALLOC

#include "SDCCralloc.hpp"
#include "SDCCralloc2.hpp"

extern "C"
{
  #include "ralloc.h"
  #include "gen.h"
  float dryhc08iCode (iCode *ic);
  //bool hc08_assignment_optimal;
}

#define REG_A 0
#define REG_X 1
#define REG_H 2

static int getIndex(std::vector<short int> v, short int K) 
{ 
    auto it = find(v.begin(), v.end(), K); 
  
    // If element was found 
    if (it != v.end())  
    { 
      
        // calculating the index 
        // of K 
        int index = it - v.begin(); 
        return index;
    } 
    else { 
        // If the element is not 
        // present in the vector 
        return -1;
    } 
} 

template <class I_t>
static void add_operand_conflicts_in_node(const cfg_node &n, I_t &I)
{
  const iCode *ic = n.ic;
  
  const operand *result = IC_RESULT(ic);
  const operand *left = IC_LEFT(ic);
  const operand *right = IC_RIGHT(ic);
	
  if(!result || !IS_SYMOP(result))
    return;
    
  // Todo: Identify more operations that code generation can always handle and exclude them (as done for the z80-like ports).
  if (ic->op == '=')
    return;

  operand_map_t::const_iterator oir, oir_end, oirs; 
  boost::tie(oir, oir_end) = n.operands.equal_range(OP_SYMBOL_CONST(result)->key);
  if(oir == oir_end)
    return;
    
  operand_map_t::const_iterator oio, oio_end;
  
  if(left && IS_SYMOP(left))
    for(boost::tie(oio, oio_end) = n.operands.equal_range(OP_SYMBOL_CONST(left)->key); oio != oio_end; ++oio)
      for(oirs = oir; oirs != oir_end; ++oirs)
        {
          var_t rvar = oirs->second;
          var_t ovar = oio->second;
          if(I[rvar].byte < I[ovar].byte)
            boost::add_edge(rvar, ovar, I);
        }
        
  if(right && IS_SYMOP(right))
    for(boost::tie(oio, oio_end) = n.operands.equal_range(OP_SYMBOL_CONST(right)->key); oio != oio_end; ++oio)
      for(oirs = oir; oirs != oir_end; ++oirs)
        {
          var_t rvar = oirs->second;
          var_t ovar = oio->second;
          if(I[rvar].byte < I[ovar].byte)
            boost::add_edge(rvar, ovar, I);
        }
}

// Return true, iff the operand is placed (partially) in r.
static bool operand_in_reg(const operand *o, reg_t r, const i_assignment_ps &ia, const cfg_node &node)
{
  if(!o || !IS_SYMOP(o))
    return(false);

  if(r >= port->num_regs)
    return(false);

  operand_map_t::const_iterator oi, oi_end;
  for(boost::tie(oi, oi_end) = node.operands.equal_range(OP_SYMBOL_CONST(o)->key); oi != oi_end; ++oi)
    if(oi->second == ia.registers_begin[r] || oi->second == ia.registers_end[r])
      return(true);

  return(false);
}

template <class I_t>
static bool operand_is_ax(const operand *o, const i_assignment_ps &ia, const cfg_node &node, const I_t &I)
{  
  if(!o || !IS_SYMOP(o))
    return(false);
 
  operand_map_t::const_iterator oi, oi2, oi_end;
  boost::tie(oi, oi_end) = node.operands.equal_range(OP_SYMBOL_CONST(o)->key);
  
  if(oi == oi_end)
    return(false);

  oi2 = oi;
  oi2++;
  if (oi2 == oi_end)
    return(false);
  
  // Register combinations code generation cannot handle yet (AX, AH, XH, HA).
  if(std::binary_search(node.alive.begin(), node.alive.end(), oi->second) && std::binary_search(node.alive.begin(), node.alive.end(), oi2->second))
    {
      const reg_t l = getIndex(ia.registers_begin, oi->second);
      const reg_t h = getIndex(ia.registers_begin, oi2->second);
      if(l == REG_X && h == REG_A)
        return(true);
    }

  return(false);
}

template <class I_t>
static bool XAinst_ok( const i_assignment_ps &ia ,const cfg_node &node, const I_t &I)
{
  const iCode *ic = node.ic;

  // Instructions that can handle anything.
  if(ic->op == '!' ||
    ic->op == '~' ||
    ic->op == UNARYMINUS ||
    ic->op == CALL ||
    ic->op == PCALL ||
    ic->op == FUNCTION ||
    ic->op == ENDFUNCTION ||
    ic->op == RETURN ||
    ic->op == LABEL ||
    ic->op == GOTO ||
    ic->op == IFX ||
    ic->op == '+' ||
    ic->op == '-' ||
    ic->op == '*' ||
    ic->op == '/' ||
    ic->op == '%' ||
    ic->op == '<' || ic->op == '>' || ic->op == LE_OP || ic->op == GE_OP ||
    ic->op == NE_OP || ic->op == EQ_OP ||
    ic->op == AND_OP ||
    ic->op == OR_OP ||
    ic->op == '^' ||
    ic->op == '|' ||
    ic->op == BITWISEAND ||
    ic->op == GETABIT ||
    ic->op == GETBYTE ||
    ic->op == GETWORD ||
    ic->op == LEFT_OP ||
    ic->op == RIGHT_OP ||
    ic->op == '=' ||  /* both regular assignment and POINTER_SET safe */
    ic->op == GET_VALUE_AT_ADDRESS ||
    ic->op == ADDRESS_OF ||
    ic->op == CAST ||
    ic->op == DUMMY_READ_VOLATILE ||
    ic->op == SWAP)
    return(true);

  if(ic->op == IFX && ic->generated)
    return(true);

  //const i_assignment_t &ia = a.i_assignment;

  bool unused_A = (ia.registers_begin[REG_A] < 0);
  bool unused_H = (ia.registers_begin[REG_H] < 0);
  bool unused_X = (ia.registers_begin[REG_X] < 0);

  if(unused_X && unused_A && unused_H)
    return(true);

#if 0
  std::cout << "XAinst_ok: at (" << i << ", " << ic->key << ")\nX = (" << ia.registers[REG_X][0] << ", " << ia.registers[REG_X][1] << "), A = (" << ia.registers[REG_A][0] << ", " << ia.registers[REG_A][1] << ")inst " << i << ", " << ic->key << "\n";
#endif

  const operand *left = IC_LEFT(ic);
  const operand *right = IC_RIGHT(ic);
  const operand *result = IC_RESULT(ic);

  bool result_in_A = operand_in_reg(result, REG_A, ia, node) && !(ic->op == '=' && POINTER_SET(ic));
  bool result_in_H = operand_in_reg(result, REG_H, ia, node) && !(ic->op == '=' && POINTER_SET(ic));
  bool result_in_X = operand_in_reg(result, REG_X, ia, node) && !(ic->op == '=' && POINTER_SET(ic));
  bool left_in_A = operand_in_reg(result, REG_A, ia, node);
  bool left_in_X = operand_in_reg(result, REG_X, ia, node);

  const cfg_dying_t &dying = node.dying;

  bool dying_A = result_in_A || dying.find(ia.registers_end[REG_A]) != dying.end() || dying.find(ia.registers_begin[REG_A]) != dying.end();
  bool dying_H = result_in_H || dying.find(ia.registers_end[REG_H]) != dying.end() || dying.find(ia.registers_begin[REG_H]) != dying.end();
  bool dying_X = result_in_X || dying.find(ia.registers_end[REG_X]) != dying.end() || dying.find(ia.registers_begin[REG_X]) != dying.end();

  bool result_only_XA = (result_in_X || unused_X || dying_X) && (result_in_A || unused_A || dying_A);

  if(ic->op == JUMPTABLE && (unused_A || dying_A))
    return(true);

  if(ic->op == IPUSH && (unused_A || dying_A || left_in_A || operand_in_reg(left, REG_H, ia, node) || left_in_X))
    return(true);

  if(ic->op == RECEIVE && (!ic->next || !(ic->next->op == RECEIVE) || !result_in_X || getSize(operandType(result)) >= 2))
    return(true);

  if(ic->op == SEND && ic->next && ic->next->op == SEND && ic->next->next && ic->next->next->op == SEND)
    return(true);

  if(ic->op == SEND && ic->next && ic->next->op == SEND && (unused_X || dying_X))
    return(true);

  if(ic->op == SEND && (unused_X || dying_X) && (unused_A || dying_A))
    return(true);

  if(ic->op == SEND && ic->next && (ic->next->op == CALL || ic->next->op == PCALL)) // Might mess up A and X, but these would have been saved before if surviving, and will not be needed again before the call.
    return(true);

  if((ic->op == CRITICAL || ic->op == ENDCRITICAL) && (unused_A || dying_A))
    return(true);

  return(false);
}

template <class I_t>
static bool AXinst_ok(const i_assignment_ps &ia, const cfg_node &node, const I_t &I)
{
  const iCode *ic = node.ic;

  if(ic->op == '!' ||
    ic->op == '~' ||
    ic->op == IPUSH ||
    ic->op == CALL ||
    ic->op == FUNCTION ||
    ic->op == ENDFUNCTION ||
    ic->op == RETURN ||
    ic->op == LABEL ||
    ic->op == GOTO ||
    ic->op == '+' ||
    ic->op == '-' ||
    ic->op == NE_OP || ic->op == EQ_OP ||
    ic->op == '^' ||
    ic->op == '|' ||
    ic->op == BITWISEAND ||
    ic->op == GETABIT ||
    ic->op == GETBYTE ||
    ic->op == GETWORD ||
    /*ic->op == LEFT_OP ||
    ic->op == RIGHT_OP ||*/
    ic->op == GET_VALUE_AT_ADDRESS ||
    ic->op == '=' ||
    ic->op == ADDRESS_OF ||
    ic->op == RECEIVE ||
    ic->op == SEND ||
    ic->op == DUMMY_READ_VOLATILE ||
    ic->op == CRITICAL ||
    ic->op == ENDCRITICAL ||
    ic->op == SWAP)
    return(true);

  bool unused_A = (ia.registers_end[REG_A] < 0);
  bool unused_X = (ia.registers_end[REG_A] < 0);

  if (unused_A || unused_X)
    return(true);

  const operand *left = IC_LEFT(ic);
  const operand *right = IC_RIGHT(ic);
  const operand *result = IC_RESULT(ic);

  bool result_in_A = operand_in_reg(result, REG_A, ia, node) && !(ic->op == '=' && POINTER_SET(ic));
  bool result_in_X = operand_in_reg(result, REG_X, ia, node) && !(ic->op == '=' && POINTER_SET(ic));
  bool left_in_A = operand_in_reg(result, REG_A, ia, node);
  bool left_in_X = operand_in_reg(result, REG_X, ia, node);
  bool right_in_A = operand_in_reg(result, REG_A, ia, node);
  bool right_in_X = operand_in_reg(result, REG_X, ia, node);

  bool result_is_ax = operand_is_ax (result, ia, node,I);
  bool left_is_ax = operand_is_ax (left, ia, node,I);
  bool right_is_ax = operand_is_ax (right, ia, node,I);

  if (!result_is_ax && !left_is_ax && !right_is_ax)
    return(true);

  return(false);
}

template <class I_t>
static void set_surviving_regs(const i_assignment_ps &ia, cfg_node &node, const I_t &I)
{
  iCode *ic = node.ic;
  
  bitVectClear(ic->rMask);
  bitVectClear(ic->rSurv);
  
  cfg_alive_t::const_iterator v, v_end;
  for (v = node.alive.begin(), v_end = node.alive.end(); v != v_end; ++v)
    {
      if(getIndex(ia.registers_begin,*v) < 0)
        continue;
      ic->rMask = bitVectSetBit(ic->rMask, getIndex(ia.registers_begin,*v));
      if(node.dying.find(*v) == node.dying.end())
        if(!((IC_RESULT(ic) && !POINTER_SET(ic)) && IS_SYMOP(IC_RESULT(ic)) && OP_SYMBOL_CONST(IC_RESULT(ic))->key == I[*v].v))
          ic->rSurv = bitVectSetBit(ic->rSurv, getIndex(ia.registers_begin,*v));
    }
}

template <class I_t>
static void assign_operand_for_cost(operand *o, const i_assignment_ps &ia,  cfg_node &node, const I_t &I)
{
  if(!o || !IS_SYMOP(o))
    return;
  symbol *sym = OP_SYMBOL(o);
  operand_map_t::const_iterator oi, oi_end;
  for(boost::tie(oi, oi_end) = node.operands.equal_range(OP_SYMBOL_CONST(o)->key); oi != oi_end; ++oi)
    {
      var_t v = oi->second;
      if(getIndex(ia.registers_begin,v) >= 0)
        { 
          sym->regs[I[v].byte] = regshc08 + getIndex(ia.registers_begin,v);   
          sym->isspilt = false;
          sym->nRegs = I[v].size;
          sym->accuse = 0;
        }
      else
        {
          for(int i = 0; i < I[v].size; i++)
            sym->regs[i] = 0;
          sym->accuse = 0;
          sym->nRegs = I[v].size;
          sym->isspilt = true;
        }
    }
}

template < class I_t>
static void assign_operands_for_cost(const i_assignment_ps &ia,  cfg_node &node, const I_t &I)
{
  const iCode *ic = node.ic;
  
  if(ic->op == IFX)
    assign_operand_for_cost(IC_COND(ic), ia, node,I);
  else if(ic->op == JUMPTABLE)
    assign_operand_for_cost(IC_JTCOND(ic), ia, node, I);
  else
    {
      assign_operand_for_cost(IC_LEFT(ic), ia, node, I);
      assign_operand_for_cost(IC_RIGHT(ic), ia, node, I);
      assign_operand_for_cost(IC_RESULT(ic), ia, node, I);
    }
    
    //TOFIX: This is a hack to handle the case where the result of a SEND is used in the next instruction.
  //if(ic->op == SEND && ic->builtinSEND)
   // {
   //   assign_operands_for_cost(ia, *(adjacent_vertices(i, G).first), G, I);
   // }
}

// Check that the operand is either fully in registers or fully in memory.
template <class I_t>
static bool operand_sane(const operand *o, const i_assignment_ps &ia, cfg_node &node, const I_t &I)
{
  if(!o || !IS_SYMOP(o))
    return(true);
 
  operand_map_t::const_iterator oi, oi2, oi_end;
  boost::tie(oi, oi_end) = node.operands.equal_range(OP_SYMBOL_CONST(o)->key);
  
  if(oi == oi_end)
    return(true);

  // Go to the second byte. If the operand is only a single byte, it cannot be
  // an unsupported register combination or split between register and memory.
  oi2 = oi;
  oi2++;
  if (oi2 == oi_end)
    return(true);
  
  // Register combinations code generation cannot handle yet (AH, XH, HA).
  if(std::binary_search(node.alive.begin(),node.alive.end(), oi->second) && std::binary_search(node.alive.begin(), node.alive.end(), oi2->second))
    {
      const reg_t l = getIndex(ia.registers_begin, oi->second);
      const reg_t h = getIndex(ia.registers_begin, oi2->second);
      if(l == REG_A && h == REG_H || l == REG_H)
        return(false);
    }
  
  // In registers.
  if(std::binary_search(node.alive.begin(), node.alive.end(), oi->second))
    {
      while(++oi != oi_end)
        if(!std::binary_search(node.alive.begin(), node.alive.end(), oi->second))
          return(false);
    }
  else
    {
       while(++oi != oi_end)
        if(std::binary_search(node.alive.begin(), node.alive.end(), oi->second))
          return(false);
    }
 
  return(true);
}

template <class I_t>
static bool inst_sane(const i_assignment_ps &ia,cfg_node &node, const I_t &I)
{
  const iCode *ic = node.ic;

  return(operand_sane(IC_RESULT(ic), ia, node, I) && operand_sane(IC_LEFT(ic), ia, node, I) && operand_sane(IC_RIGHT(ic), ia, node, I));
}

// Cost function.
template <class I_t>
static float instruction_cost(const i_assignment_ps &ia,cfg_node &node, const I_t &I)
{
  iCode *ic = node.ic;
  float c;

  wassert (TARGET_IS_HC08 || TARGET_IS_S08);

  if(!inst_sane(ia, node, I))
    return(std::numeric_limits<float>::infinity());

#if 0
  std::cout << "Calculating at cost at ic " << ic->key << " for: ";
  for(unsigned int i = 0; i < boost::num_vertices(I); i++)
  {
  	std::cout << "(" << i << ", " << int(a.global[i]) << ") ";
  }
  std::cout << "\n";
  std::cout.flush();
#endif

  if(ic->generated)
    return(0.0f);
  std::cout<<"begin to check ic"<<std::endl;
  if(!XAinst_ok(ia, node, I))
    return(std::numeric_limits<float>::infinity());

  if(!AXinst_ok(ia, node, I))
    return(std::numeric_limits<float>::infinity());
  std::cout<<"ic is: "<<ic->op<< std::endl;
  switch(ic->op)
    {
    // Register assignment doesn't matter for these:
    case FUNCTION:
    case ENDFUNCTION:
    case LABEL:
    case GOTO:
    case INLINEASM:
      std::cout<<"return 0"<<std::endl;
      return(0.0f);
    case '!':
    case '~':
    case UNARYMINUS:
    case '+':
    case '-':
    case '^':
    case '|':
    case BITWISEAND:
    case IPUSH:
    //case IPOP:
    case CALL:
    case PCALL:
    case RETURN:
    case '*':
    case '/':
    case '%':
    case '>':
    case '<':
    case LE_OP:
    case GE_OP:
    case EQ_OP:
    case NE_OP:
    case AND_OP:
    case OR_OP:
    case GETABIT:
    case GETBYTE:
    case GETWORD:
    case LEFT_OP:
    case RIGHT_OP:
    case GET_VALUE_AT_ADDRESS:
    case '=':
    case IFX:
    case ADDRESS_OF:
    case JUMPTABLE:
    case CAST:
    case RECEIVE:
    case DUMMY_READ_VOLATILE:
    case CRITICAL:
    case ENDCRITICAL:
    case SWAP:
      std::cout<<"assign operands for cost"<<std::endl;
      assign_operands_for_cost(ia, node, I);
      std::cout<<"set surviving regs"<<std::endl;
      set_surviving_regs(ia, node, I);
      std::cout<<"get cost"<<std::endl;

      c = dryhc08iCode(ic);
      std::cout<<"c is: "<<c<<std::endl;
      ic->generated = false;
      return(c);
      
    default:
      std::cout<<"default"<<std::endl;
      return(0.0f);
    }
}


template <class I_t>
static float assign_operand_for_cost_easy(operand *o, const i_assignment_ps &ia,  cfg_node &node, const I_t &I,float c)
{
  if(!o || !IS_SYMOP(o))
    return c;
  symbol *sym = OP_SYMBOL(o);
  operand_map_t::const_iterator oi, oi_end;
  for(boost::tie(oi, oi_end) = node.operands.equal_range(OP_SYMBOL_CONST(o)->key); oi != oi_end; ++oi)
    {
      var_t v = oi->second;
      if(getIndex(ia.registers_begin,v) >= 0)
        { 
          c=c+1;
        }
      else
        {
          std::cout<<"v is: "<<v<<std::endl;
          std::cout<<"f is: ";
          for(auto a in ia.registers_begin)
          {
            std::cout<<*a<<",";
          }
          std::cout<<std::endl;
          c=c+4;
        }
    }
    return c;
}

template < class I_t>
static float assign_operands_for_cost_easy(const i_assignment_ps &ia,  cfg_node &node, const I_t &I, float c)
{
  const iCode *ic = node.ic;
  
  if(ic->op == IFX)
    c=assign_operand_for_cost_easy(IC_COND(ic), ia, node,I,c);
  else if(ic->op == JUMPTABLE)
    c=assign_operand_for_cost_easy(IC_JTCOND(ic), ia, node, I,c);
  else
    {
      c=assign_operand_for_cost_easy(IC_LEFT(ic), ia, node, I,c);
      c=assign_operand_for_cost_easy(IC_RIGHT(ic), ia, node, I,c);
      c=assign_operand_for_cost_easy(IC_RESULT(ic), ia, node, I,c);
    }
    return c;
    //TOFIX: This is a hack to handle the case where the result of a SEND is used in the next instruction.
  //if(ic->op == SEND && ic->builtinSEND)
   // {
   //   assign_operands_for_cost(ia, *(adjacent_vertices(i, G).first), G, I);
   // }
}



// Easy Cost function.
template <class I_t>
static float instruction_cost_easy(const i_assignment_ps &ia,cfg_node &node, const I_t &I)
{
  iCode *ic = node.ic;
  float c;

  wassert (TARGET_IS_HC08 || TARGET_IS_S08);

  if(!inst_sane(ia, node, I))
    return(std::numeric_limits<float>::infinity());

#if 0
  std::cout << "Calculating at cost at ic " << ic->key << " for: ";
  for(unsigned int i = 0; i < boost::num_vertices(I); i++)
  {
  	std::cout << "(" << i << ", " << int(a.global[i]) << ") ";
  }
  std::cout << "\n";
  std::cout.flush();
#endif

  if(ic->generated)
    return(0.0f);
  //std::cout<<"begin to check ic"<<std::endl;
  if(!XAinst_ok(ia, node, I))
    return(std::numeric_limits<float>::infinity());

  if(!AXinst_ok(ia, node, I))
    return(std::numeric_limits<float>::infinity());
  //std::cout<<"ic is: "<<ic->op<< std::endl;

  switch(ic->op)
    {
    // Register assignment doesn't matter for these:
    case FUNCTION:
    case ENDFUNCTION:
    case LABEL:
    case GOTO:
    case INLINEASM:
      return(0.0f);
    case '!':
    case '~':
    case UNARYMINUS:
    case '+':
    case '-':
    case '^':
    case '|':
    case BITWISEAND:
    case IPUSH:
    //case IPOP:
    case CALL:
    case PCALL:
    case RETURN:
    case '*':
    case '/':
    case '%':
    case '>':
    case '<':
    case LE_OP:
    case GE_OP:
    case EQ_OP:
    case NE_OP:
    case AND_OP:
    case OR_OP:
    case GETABIT:
    case GETBYTE:
    case GETWORD:
    case LEFT_OP:
    case RIGHT_OP:
    case GET_VALUE_AT_ADDRESS:
    case '=':
    case IFX:
    case ADDRESS_OF:
    case JUMPTABLE:
    case CAST:
    case RECEIVE:
    case SEND:
    case DUMMY_READ_VOLATILE:
    case CRITICAL:
    case ENDCRITICAL:
    case SWAP:
      c=assign_operands_for_cost_easy(ia,node, I,c); 
      return(c);
    default:
      return(0.0f);
    }
}



// Code for another ic is generated when generating this one. Mark the other as generated.
static void extra_ic_generated(iCode *ic)
{
  if(ic->op == '>' || ic->op == '<' || ic->op == LE_OP || ic->op == GE_OP || ic->op == EQ_OP || ic->op == NE_OP || ic->op == '^' || ic->op == '|' || ic->op == BITWISEAND)
    {
      iCode *ifx;
      if (ifx = ifxForOp (IC_RESULT (ic), ic))
        {
          OP_SYMBOL (IC_RESULT (ic))->for_newralloc = false;
          OP_SYMBOL (IC_RESULT (ic))->regType = REG_CND;
          ifx->generated = true;
        }
    }
  if(ic->op == '-' && IS_VALOP (IC_RIGHT (ic)) && operandLitValue (IC_RIGHT (ic)) == 1 && getSize(operandType(IC_RESULT (ic))) == 1 && !isOperandInFarSpace (IC_RESULT (ic)) && isOperandEqual (IC_RESULT (ic), IC_LEFT (ic)))
    {
      iCode *ifx;
      if (ifx = ifxForOp (IC_RESULT (ic), ic))
        {
          OP_SYMBOL (IC_RESULT (ic))->for_newralloc = false;
          OP_SYMBOL (IC_RESULT (ic))->regType = REG_CND;
          ifx->generated = true;
        }
    }
  if(ic->op == GET_VALUE_AT_ADDRESS)
    {
      iCode *inc;
      if (inc = hasInchc08 (IC_LEFT (ic), ic,  getSize (operandType (IC_RIGHT (ic)))))
         inc->generated = true;
    }
}

template <class I_t>
static float get_ps_optimal_cst(ps_cfg_t &root, const I_t &I)
{
  bool assignment_optimal;

  con2_t I2(boost::num_vertices(I));
  for(unsigned int i = 0; i < boost::num_vertices(I); i++)
    {
      I2[i].v = I[i].v;
      I2[i].byte = I[i].byte;
      I2[i].size = I[i].size;
      I2[i].name = I[i].name;
    }
  typename boost::graph_traits<I_t>::edge_iterator e, e_end;
  for(boost::tie(e, e_end) = boost::edges(I); e != e_end; ++e)
    add_edge(boost::source(*e, I), boost::target(*e, I), I2);

 // std::cout<<"I2 created"<<std::endl;

  generate_spcfg(root,I2);
  
 //std::cout<<"fi;; spcfg with assignments"<<std::endl;
  const assignment_ps &winner = get_optimal(root,I2);

#ifdef DEBUG_RALLOC_DEC
  std::cout << "Winner: ";
  for(unsigned int i = 0; i < boost::num_vertices(I); i++)
  {
  	std::cout << "(" << i << ", " << int(winner.global[i]) << ") ";
  }
  std::cout << "\n";
  std::cout << "Cost: " << winner.s << "\n";
  std::cout.flush();
#endif



  return(winner.s);
}

float hc08_ralloc3_cc(ebbIndex *ebbi)
{

#ifdef DEBUG_RALLOC_DEC
  std::cout << "Processing " << currFunc->name << " from " << dstFileName << "\n"; std::cout.flush();
#endif

  cfg_t control_flow_graph;

  con_t conflict_graph;

  iCode *ic = create_cfg(control_flow_graph, conflict_graph, ebbi);
  initial_after(control_flow_graph);

  if(options.dump_graphs)
    dump_cfg(control_flow_graph);

  //std::cout<<"cfg created"<<std::endl;
  ps_cfg_t root;
  boost::graph_traits<cfg_t>::vertex_iterator vi, vi_end;
  boost::tie(vi, vi_end) = boost::vertices(control_flow_graph);
  root=init_ps_cfg(control_flow_graph,*vi,*(vi_end-1),-1,-1);
  convert_cfg_to_spcfg(root);

  //std::cout<<"spcfg created"<<std::endl;
  float cost= get_ps_optimal_cst(root,conflict_graph);
  //std::cout<<"get cost"<<std::endl;

   std::ofstream outputFile("optimalCost2.txt");
   if (outputFile.is_open()) {  // Check if the file was successfully opened
    // Write some text into the file
    outputFile << "2.our's optimal cost: "<<cost<<"\n";  // Write a line of text to the file
   
    // Close the file
    outputFile.close();  // Close the file after writing

    std::cout << "Text has been written to the file." << std::endl;  // Display a success message
  } else {
    std::cout << "Failed to create the file." << std::endl;  // Display an error message if file creation failed
  }

  return  cost;
}

