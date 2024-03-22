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


typedef std::vector<var_t> f;

//assignment for one instuction
struct i_assignment_ps{
   f registers_begin;
   f registers_end;
   varset_t begin_v; //beginning variable
   varset_t end_v; //ending variable

   cfg_node *node; //the corresponding node(with ic) in the cfg
   float cost; //cost of the assignment

   i_assignment_ps(){
      for(int i=0; i<MAX_NUM_REGS; i++){
         registers_begin[i]=-1;
         registers_end[i]=-1;
      }
      node = NULL;
   }

   bool equal_series(i_assignment_ps *a){
      for(int i=0; i<MAX_NUM_REGS; i++){
         if(registers_end[i] != a->registers_begin[i]){
            return false;
         }
      }
      return true;
   }

   bool equal(i_assignment_ps *a){
      for(int i=0; i<MAX_NUM_REGS; i++){
         if(registers_end[i] != a->registers_end[i] || registers_begin[i] != a->registers_begin[i]){
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
   f begin; //beginning register
   f end; //ending register
   varset_t begin_v; //beginning variable
   varset_t end_v; //ending variable
};

typedef std::vector<assignment_ps> assignment_ps_list;


//we need to see if we can get the cost of each instruction directly from this function
//I hope it is not hard, but I am not sure.
//static float instruction_cost(i_assignment_ps &a);

typedef std::map<std::pair<f,f>,assignment_ps> assignment_ps_map;

void calcSubset(f& A, std::vector<f >& res,
                f& subset, int index)
{
    // Add the current subset to the result list
    res.push_back(subset);
 
    // Generate subsets by recursively including and
    // excluding elements
    for (int i = index; i < A.size(); i++) {
        // Include the current element in the subset
        subset.push_back(A[i]);
 
        // Recursively generate subsets with the current
        // element included
        calcSubset(A, res, subset, i + 1);
 
        // Exclude the current element from the subset
        // (backtracking)
        subset.pop_back();
    }
}

static std::vector<f> generate_permutation(f variables){
   std::vector<f> results;
   results.push_back(variables);
   while (std::next_permutation(variables.begin(), variables.end())){
      results.push_back(variables);
   }
   
   return results;
}
 
std::vector<f > subsets(f& A)
{
   f subset;
    std::vector<f > res;
    int index = 0;
    calcSubset(A, res, subset, index);
    return res;
}

static std::vector<f> generate_possibility(f variables){
   std::vector<f> results;
   std::vector<f> sub_set=subsets(variables);
   for(auto sub:sub_set){
      if(sub.size()<=MAX_NUM_REGS){
        f v;
        for(int i=0; i<MAX_NUM_REGS;i++){
          v.push_back(-1);
        }
        int len=sub.size();
        for(int i=0;i<len;i++){
          v[MAX_NUM_REGS-len+i]=sub[i];
        }
        cout<<"current sub:"<<endl;
        for(auto i:v){
          cout<<i<<" ";
        }
        cout<<endl;
        vector<f> p=generate_permutation(v);
        cout<<"current p:"<<endl;
        for(auto i:p){
          for(auto j:i){
            cout<<j<<" ";
          }
          cout<<endl;
        }
        cout<<endl;
        results.reserve(results.size() + distance(p.begin(),p.end()));
        results.insert(results.end(),p.begin(),p.end());
      }
   }
   return results;
}

//---------todo: modified from here----------------
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

