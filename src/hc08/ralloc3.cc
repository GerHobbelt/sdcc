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




static void write_into_csv(float c, int i, int time){
  std::ofstream outputFile("optimalCost.csv", std::ios_base::app);
   if (outputFile.is_open()) {  // Check if the file was successfully opened
    // Write some text into the file
    outputFile << std::string(dstFileName)<<","<< c << "," << time << "," << i << "\n";  // Write a line of text to the file
    // Close the file
    outputFile.close();  // Close the file after writing

    std::cout << "Text has been written to the file." << std::endl;  // Display a success message
  } else {
    std::cout << "Failed to create the file." << std::endl;  // Display an error message if file creation failed
  }


}

static void write_into_csv( int i, int time){
  std::ofstream outputFile("optimalc_time.csv", std::ios_base::app);
   if (outputFile.is_open()) {  // Check if the file was successfully opened
    // Write some text into the file
    outputFile << std::string(dstFileName)<<","<< time << "," << i << "\n";  // Write a line of text to the file
    // Close the file
    outputFile.close();  // Close the file after writing

    std::cout << "Text has been written to the file." << std::endl;  // Display a success message
  } else {
    std::cout << "Failed to create the file." << std::endl;  // Display an error message if file creation failed
  }
}


template <class I_t>
static float assign_operand_for_cost_easy(operand *o, const i_assignment_ps &ia,  cfg_node &node, const I_t &I,float c)
{
  if(!o || !IS_SYMOP(o))
    return c;
  symbol *sym = OP_SYMBOL(o);
  operand_map_t::const_iterator oi, oi_end;
//  std::cout<<"o is: "<<OP_SYMBOL_CONST(o)->key<<std::endl;
  for(boost::tie(oi, oi_end) = node.operands.equal_range(OP_SYMBOL_CONST(o)->key); oi != oi_end; ++oi)
    {
      var_t v = oi->second;
   if(ia.global_regs[v]>=0)
        { 
          c=c+1;
        }
      else
        {
          //std::cout<<std::endl;
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
      c=c+assign_operand_for_cost_easy(IC_RIGHT(ic), ia, node, I,c);
      c=c+assign_operand_for_cost_easy(IC_RESULT(ic), ia, node, I,c);
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
  float c=0;

  wassert (TARGET_IS_HC08 || TARGET_IS_S08);
  if(ic->generated)
    return(0.0f);
    
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
static void initial_basic_block(ps_cfg_t &ps_cfg, const I_t &I)
{
   if (ps_cfg.assignments.size() == 0){
      if(ps_cfg.left==-1 || ps_cfg.right==-1){
        // std::cout<<"1"<<std::endl;
         initlize_assignment_ps_list(ps_cfg, I);
         return;
      }
      if (ps_cfg_map[ps_cfg.left].assignments.size() == 0){
       //  std::cout<<"2"<<std::endl;
         initial_basic_block(ps_cfg_map[ps_cfg.left], I);
      }
      if (ps_cfg_map[ps_cfg.right].assignments.size() == 0){
       //  std::cout<<"3"<<std::endl;
         initial_basic_block(ps_cfg_map[ps_cfg.right], I);
      }
}}


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
  initial_basic_block(root,I2);
  //std::cout<<"initial basic block"<<std::endl;
  auto start = std::chrono::high_resolution_clock::now();

  generate_spcfg(root);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast< std::chrono::microseconds>(stop - start);

 //std::cout<<"fi;; spcfg with assignments"<<std::endl;
  const assignment_ps &winner = get_optimal(root);



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

 write_into_csv(winner.s,1,duration.count());

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
  //initial_after(control_flow_graph);

  //std::cout<<"cfg created"<<std::endl;
  ps_cfg_t root;
  boost::graph_traits<cfg_t>::vertex_iterator vi, vi_end;
  boost::tie(vi, vi_end) = boost::vertices(control_flow_graph);
  root=init_ps_cfg(control_flow_graph,*vi,*(vi_end-1),-1,-1);
  //std::cout<<"root created"<<std::endl;
  convert_cfg_to_spcfg(root);

 // std::cout<<"spcfg created"<<std::endl;
  float cost= get_ps_optimal_cst(root,conflict_graph);
  //std::cout<<"get cost"<<std::endl;


  return  cost;
}

