// To use this from a port do the following:
//
// 1) Supply a cost function
// template <class G_t, class I_t>
// float instruction_cost(const assignment &a, unsigned short int i, const G_t &G, const I_t &I);
// Which can range from
// simple, e.g. cost 1 for each byte accessed in a register, cost 4 for each byte accessed in memory
// to
// quite involved, e.g. the number of bytes of code the code generator would generate.
//1)create a cost function 
// float instruction_cost(const i_assignment_ps &a)
//
// 2) Call
// create_cfg(), convert_cfg_to_spcfg() and generate_spcfg() in that order


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


//we need to see if we can get the cost of each instruction directly from this function
//I hope it is not hard, but I am not sure.
//static float instruction_cost(i_assignment_ps &a);

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
        //cout<<"current sub:"<<endl;
        //for(auto i:v){
        //  cout<<i<<" ";
        //}
        //cout<<endl;
        std::vector<f> p=generate_permutation(v);
        //cout<<"current p:"<<endl;
        //for(auto i:p){
        //  for(auto j:i){
        //    cout<<j<<" ";
        //  }
        //  cout<<endl;
        //}
        //cout<<endl;
        results.reserve(results.size() + distance(p.begin(),p.end()));
        results.insert(results.end(),p.begin(),p.end());
      }
   }
   return results;
}

//this function is used to combine two assignment_ps_list while series merge
static assignment_ps_map combine_assignment_ps_list_series(ps_cfg_t a, ps_cfg_t b){
   assignment_ps_map c;
   assignment_ps_map a_map=a.assignments;
   assignment_ps_map b_map=b.assignments;
   std::vector<f> begin=generate_possibility(a.begin_v);
   std::vector<f> mid=generate_possibility(a.end_v);
   std::vector<f> end=generate_possibility(b.end_v);
   for(auto i:begin){
      for(auto j:mid){
         for(auto k:end){
            assignment_ps aa=a_map[std::pair<f,f>(i,j)];
            assignment_ps ab=b_map[std::pair<f,f>(j,k)];
            assignment_ps ac;
            ac.s = aa.s + ab.s;
            ac.begin_i = aa.begin_i;
            ac.end_i = ab.end_i;
            ac.insts.reserve(aa.insts.size() + ab.insts.size());
            ac.insts.insert(ac.insts.end(),aa.insts.begin(),aa.insts.end());
            ac.insts.insert(ac.insts.end(),ab.insts.begin(),ab.insts.end());
            if(c[std::pair<f,f>(i,k)].s > ac.s)
               c[std::pair<f,f>(i,k)] = ac;
         }
      }
   }
   return c;
}

static assignment_ps_map combine_assignment_ps_list_parallel(ps_cfg_t a, ps_cfg_t b){
   assignment_ps_map c;
   assignment_ps_map a_map=a.assignments;
   assignment_ps_map b_map=b.assignments;
   std::vector<f> begin=generate_possibility(a.begin_v);
   std::vector<f> end=generate_possibility(b.end_v);
   for(auto i:begin){
         for(auto j:end){
            assignment_ps aa=a_map[std::pair<f,f>(i,j)];
            assignment_ps ab=b_map[std::pair<f,f>(i,j)];
            assignment_ps ac;
            ac.s = aa.s + ab.s - aa.begin_i.cost - aa.end_i.cost;
            ac.begin_i = aa.begin_i;
            ac.end_i = ab.end_i;
            ac.insts.reserve(aa.insts.size() + ab.insts.size());
            ac.insts.insert(ac.insts.end(),aa.insts.begin(),aa.insts.end());
            ac.insts.insert(ac.insts.end(),ab.insts.begin(),ab.insts.end());
            if(c[std::pair<f,f>(i,j)].s > ac.s)
               c[std::pair<f,f>(i,j)] = ac;
         }
      }
   
   return c;
   
}

static assignment_ps_map combine_assignment_ps_list_loop(ps_cfg_t a, ps_cfg_t b){
   assignment_ps_map c;
   assignment_ps_map a_map=a.assignments;
   assignment_ps_map b_map=b.assignments;
   std::vector<f> end=generate_possibility(a.begin_v);
   std::vector<f> begin=generate_possibility(a.end_v);
   for(auto i:begin){
      for(auto j:end){
            assignment_ps aa=a_map[std::pair<f,f>(j,i)];
            assignment_ps ab=b_map[std::pair<f,f>(i,j)];
            assignment_ps ac;
            ac.s = aa.s + ab.s;
            ac.begin_i = aa.begin_i;
            ac.end_i = aa.end_i;
            ac.insts.reserve(aa.insts.size() + ab.insts.size());
            ac.insts.insert(ac.insts.end(),aa.insts.begin(),aa.insts.end());
            ac.insts.insert(ac.insts.end(),ab.insts.begin(),ab.insts.end());
            if(c[std::pair<f,f>(i,j)].s > ac.s)
               c[std::pair<f,f>(i,j)] = ac;
         }
      }
   return c;
}

template <class I_t>
static float instruction_cost(const i_assignment_ps &ia, const I_t &I);

template <class I_t>
static void initlize_assignment_ps_list(ps_cfg_t &a, I_t &I){
   assignment_ps_map c;
   std::vector<f> begin=generate_possibility(a.begin_v);
   std::vector<f> end=generate_possibility(a.end_v);
   for(auto i:begin){
      for(auto j:end){
         assignment_ps aa;
         i_assignment_ps as;
         as.registers_begin = i;
         as.registers_end = j;
         as.node=&((*(a.cfg))[a.begin]);
         as.cost = instruction_cost(as,I);
         aa.s = as.cost;
         aa.begin_i = as;
         aa.end_i = as;
         aa.insts.push_back(as);
         c[std::pair<f,f>(i,j)] = aa;
      }
   }
   a.assignments = c;
}

template <class I_t>
static void generate_spcfg(ps_cfg_t &ps_cfg, I_t &I){

   if (ps_cfg.assignments.size() == 0){
      if(ps_cfg.left==-1 || ps_cfg.right==-1){
         initlize_assignment_ps_list(ps_cfg, I);
         return;
      }
      if (ps_cfg_map[ps_cfg.left].assignments.size() == 0){
         generate_spcfg(ps_cfg_map[ps_cfg.left], I);
      }
      if (ps_cfg_map[ps_cfg.right].assignments.size() == 0){
         generate_spcfg(ps_cfg_map[ps_cfg.right], I);
      }
      switch (ps_cfg.type){
         case 1:
            ps_cfg.assignments = combine_assignment_ps_list_series(ps_cfg_map[ps_cfg.left], ps_cfg_map[ps_cfg.right]);
            break;
         case 2:
            ps_cfg.assignments = combine_assignment_ps_list_parallel(ps_cfg_map[ps_cfg.left], ps_cfg_map[ps_cfg.right]);
            break;
         case 3:
            ps_cfg.assignments = combine_assignment_ps_list_loop(ps_cfg_map[ps_cfg.left], ps_cfg_map[ps_cfg.right]);
            break;
         default:
            break;
      }
      return;
   }
}

static assignment_ps get_optimal(ps_cfg_t &ps_cfg){
   if (ps_cfg.assignments.size() == 0){
      generate_spcfg(ps_cfg);
   }
   assignment_ps_map a = ps_cfg.assignments;
   assignment_ps b;
   b.s = std::numeric_limits<float>::infinity();
   for(auto i:a){
      if(b.s > i.second.s){
         b = i.second;
      }
   }
   return b;
}