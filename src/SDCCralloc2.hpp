// To use this from a port do the following:
//
// 1) Supply a cost function
// template <class G_t, class I_t>
// float instruction_cost(const assignment &a, unsigned short int i, const G_t &G, const I_t &I);
// Which can range from
// simple, e.g. cost 1 for each byte accessed in a register, cost 4 for each byte accessed in memory
// to
// quite involved, e.g. the number of bytes of code the code generator would generate.
//
// 2) Call
// create_cfg(), convert_cfg_to_spcfg()


#include <boost/version.hpp>
#if BOOST_VERSION == 106000
   #include <boost/type_traits/ice.hpp>
#endif

#include <boost/graph/graphviz.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/container/flat_map.hpp>

#include "common.h"

extern "C"
{
#include "SDCCbtree.h"
}

// Integer constant upper bound on port->num_regs
#define MAX_NUM_REGS 9

//assignment for one instuction
struct i_assignment_ps{
   var_t registers[MAX_NUM_REGS][2]; //[0] is the register when begining the instruction, [1] is the register when ending the instruction
   cfg_node *node; //the corresponding node(with ic) in the cfg
   float cost; //cost of the assignment

   i_assignment_ps(){
      for(int i=0; i<MAX_NUM_REGS; i++){
         registers[i][0] = registers[i][1] = -1;
      }
      node = NULL;
   }

   bool equal_series(i_assignment_ps *a){
      for(int i=0; i<MAX_NUM_REGS; i++){
         if(registers[i][1] != a->registers[i][0]){
            return false;
         }
      }
      return true;
   }

   bool equal(i_assignment_ps *a){
      for(int i=0; i<MAX_NUM_REGS; i++){
         if(registers[i][0] != a->registers[i][0] || registers[i][1] != a->registers[i][1]){
            return false;
         }
      }
      return true;
   }
};

//assignment for graph
struct assignment_ps{
   float s; //cost
   std::vector<i_assignment_ps> insts; //assignments for each instruction
   i_assignment_t begin; //beginning register
   i_assignment_t end; //ending register
};

typedef std::vector<assignment_ps> assignment_ps_list;


//we need to see if we can get the cost of each instruction directly from this function
//I hope it is not hard, but I am not sure.
//static float instruction_cost(i_assignment_ps &a);

typedef std::map<std::pair<i_assignment_ps,i_assignment_ps>,assignment_ps> assignment_ps_map;

//this function is used to combine two assignment_ps_list while series merge
staic combine_assignment_ps_list_series(assignment_ps_list *a, assignment_ps_list *b){
   assignment_ps_list c;
   assignment_ps_map m;
   for(int i=0; i<a->size(); i++){
      for(int j=0; j<b->size(); j++){
         assignment_ps aa= &a->at(i);
         assignment_ps ab= &b->at(j);
         if(aa.end.equal_series(ab.begin)){
            assignment_ps ac;
            assignment_ps cc= m[std::pair<i_assignment_ps,i_assignment_ps>(aa.begin,ab.end)];)
            ac.s = aa.s + ab.s;
            ac.insts = aa.insts;
            ac.insts.expand(ab.insts);
            if(cc==NULL || cc.s > ac.s){
               m[std::pair<i_assignment_ps,i_assignment_ps>(aa.begin,ab.end)] = ac;
            }
            //c.push_back(ac);
         }
      }
   }
   for(assignment_ps_map::iterator it = m.begin(); it != m.end(); it++){
      c.push_back(it->second);
   }
   return c;
}

static combine_assignment_ps_list_parallel(assignment_ps_list *a, assignment_ps_list *b){
   assignment_ps_list c;
   assignment_ps_map m;
   for(int i=0; i<a->size(); i++){
      for(int j=0; j<b->size(); j++){
         assignment_ps aa= &a->at(i);
         assignment_ps ab= &b->at(j);
         if(aa.end.equal(ab.end) && aa.begin.equal(ab.begin)){
            assignment_ps ac;
            assignment_ps cc= m[std::pair<i_assignment_ps,i_assignment_ps>(aa.begin,ab.end)];)
            ac.s = aa.s + ab.s - aa.end.cost- ab.begin.cost;
            ac.insts = aa.insts;
            ac.insts.expand(ab.insts);
            //c.push_back(ac);
            if(cc==NULL || cc.s > ac.s){
               m[std::pair<i_assignment_ps,i_assignment_ps>(aa.begin,ab.end)] = ac;
            }
         }
      }
   }
   for(assignment_ps_map::iterator it = m.begin(); it != m.end(); it++){
      c.push_back(it->second);
   }
   return c;
}

static combine_assignment_ps_list_loop(assignment_ps_list *a, assignment_ps_list *b){
   assignment_ps_list c;
   assignment_ps_map m;
   for(int i=0; i<a->size(); i++){
      for(int j=0; j<b->size(); j++){
         assignment_ps aa= &a->at(i);
         assignment_ps ab= &b->at(j);
         if(aa.end.equal_series(ab.begin)&& aa.begin.equal_series(ab.end)){
            assignment_ps ac;
            assignment_ps cc= m[std::pair<i_assignment_ps,i_assignment_ps>(aa.begin,aa.end)];
            ac.s = aa.s + ab.s;
            ac.insts = aa.insts;
            ac.insts.expand(ab.insts);
            //c.push_back(ac);
            if(cc==NULL || cc.s > ac.s){
               m[std::pair<i_assignment_ps,i_assignment_ps>(aa.begin,aa.end)] = ac;
            }
         }
      }
   }
   for(assignment_ps_map::iterator it = m.begin(); it != m.end(); it++){
      c.push_back(it->second);
   }
   return c;
}

static void initlize_assignment_ps_list(ps_cfg_t &a){


}

static void generate_spcfg(ps_cfg_t &ps_cfg){
   if (ps_cfg.assignments.size() == 0){
      if(ps_cfg.left==-1 && ps_cfg.right==-1){
         init_assignment_ps_list(&ps_cfg);
         return;
      }
      if (ps_cfg_map[ps_cfg.left].assgnments.size() == 0){
         generate_spcfg(ps_cfg_map[ps_cfg.left]);
      }
      if (ps_cfg_map[ps_cfg.right].assgnments.size() == 0){
         generate_spcfg(ps_cfg_map[ps_cfg.right]);
      }
      switch (ps_cfg.type){
         case 1:
            ps_cfg.assignments = combine_assignment_ps_list_series(&ps_cfg_map[ps_cfg.left].assignments, &ps_cfg_map[ps_cfg.right].assignments);
            break;
         case 2:
            ps_cfg.assignments = combine_assignment_ps_list_parallel(&ps_cfg_map[ps_cfg.left].assignments, &ps_cfg_map[ps_cfg.right].assignments);
            break;
         case 3:
            ps_cfg.assignments = combine_assignment_ps_list_loop(&ps_cfg_map[ps_cfg.left].assignments, &ps_cfg_map[ps_cfg.right].assignments);
            break;
         default:
            break;
      }
      return;
   }
}

