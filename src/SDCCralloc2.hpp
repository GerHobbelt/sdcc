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


//TODO: change the global_reg to map

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
#include "SDCCcfg.hpp"
#include <chrono>


extern "C"
{
#include "SDCCbtree.h"
}

// Integer constant upper bound on port->num_regs
#define MAX_NUM_REGS port->num_regs

//int duration_of_permutation=0;

static void if_f_match(f f1,f f2, f &f3){
   int n=f1.size();
  
   f3.resize(n);
   for(int i=0;i<n;++i){
      if(f1[i]==-3||f1[i]==f2[i]){
         f3[i]=f2[i];
      }else if (f2[i]==-3){
         f3[i]=f1[i];
      }else{
         f3[0]=-2;
         return;
      
      }
   }
}

//get to variable_set, return all possible pair of global allocation?
//when calculate the permutation, can we store it and reuse to save time.



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


//we need to see if we can get the cost of each instruction directly from this function
//I hope it is not hard, but I am not sure.
//static float instruction_cost(i_assignment_ps &a);

static std::vector<var_t> unionVectors(std::vector<var_t>& vec1, 
                         std::vector<var_t>& vec2) 
{ 
    std::vector<var_t> ans; 
    // Declare the set to store the unique elements 
    std::set<var_t> s; 
    // insert elements from vector 1 into the set 
    for (int i = 0; i < vec1.size(); i++) { 
        s.insert(vec1[i]); 
    } 
    // insert elements from vector 2 into the set 
    for (int i = 0; i < vec2.size(); i++) { 
        s.insert(vec2[i]); 
    } 
    // Store the union of both the vectors into a resultant 
    // vector 
    for (auto it = s.begin(); it != s.end(); it++) { 
        ans.push_back(*it); 
    } 
    return ans; 
} 


static void initial_after(cfg_t &cfg){
   boost::graph_traits<cfg_t>::vertex_iterator vi, vi_end;
   for (boost::tie(vi, vi_end) = vertices(cfg); vi != vi_end; ++vi){
          boost::graph_traits<cfg_t>::out_edge_iterator eout, eout_end;
            for (boost::tie(eout, eout_end) = out_edges(*vi, cfg); eout != eout_end; ++eout){
               vertex target=boost::target(*eout, cfg);
               cfg[*vi].after=unionVectors(cfg[*vi].after,cfg[target].alive);
            }
            std::sort(cfg[*vi].after.begin(),cfg[*vi].after.end());

   }

}

static void calcSubset(f& A, std::vector<f>& res,
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

      results.push_back(variables);}
   
   
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
  // std::cout<<"begin generate_possibility"<<std::endl;
   std::vector<f> results;
   std::vector<f> sub_set=subsets(variables);
   for(auto sub:sub_set){
      if(sub.size()<=MAX_NUM_REGS){
        f v;
        for(int i=0; i<MAX_NUM_REGS;++i){
          v.push_back(-1);
        }
        std::sort(sub.begin(),sub.end());
        int len=sub.size();
        for(int i=0;i<len;++i){
          v[MAX_NUM_REGS-len+i]=sub[i];
        }

        std::vector<f> p=generate_permutation(v);

        results.reserve(results.size() + distance(p.begin(),p.end()));
        results.insert(results.end(),p.begin(),p.end());
        //results.push_back(v);
      }
   }
 //  std::cout<<"finish generate_possibility"<<std::endl;

   return results;
}



//this function is used to combine two assignment_ps_list while series merge
static void combine_assignment_ps_list_series(assignment_ps_map &a, assignment_ps_map &b, assignment_ps_map &c){
   f va=a.begin()->second.variables;
   f vb=b.begin()->second.variables;
   if (va==vb){for (auto i:permutation_map[va]){
     float s=a[i].s+b[i].s;
     c[i]=assignment_ps(s,a[i].begin_cost,b[i].end_cost,va);
   } return;}
   f v=unionVectors(va,vb);
   std::vector<f> gs; 
   bool newv= (permutation_map.find(v)==permutation_map.end());   
  for(auto &i:a){
   for(auto &j:b){
      f newf;
      if_f_match(i.first ,j.first,newf);
      if (newf[0]==-2){
         continue;
      }
       if(newv){
         gs.push_back(newf);
      }
      float s=i.second.s+j.second.s;
       if(c.find( newf ) == c.end() || c[newf].s > s){
         c[newf] = assignment_ps(s,i.second.begin_cost,j.second.end_cost,v);
      }

   }
  }
  if(newv){
  permutation_map[v]=gs;
 }
   //std::cout<<"combine_assignment_ps_list_series.size"<<c.size() <<std::endl;
}

static void combine_assignment_ps_list_parallel(assignment_ps_map &a, assignment_ps_map &b, assignment_ps_map &c){
f va=a.begin()->second.variables;
f vb=b.begin()->second.variables;
   if (va==vb){for (auto i:permutation_map[va]){
     float s=a[i].s+b[i].s-a[i].end_cost-a[i].begin_cost;
     c[i]=assignment_ps(s,a[i].begin_cost,a[i].end_cost,va);
   }     return;
}
   f v=unionVectors(va,vb);
   std::vector<f> gs; 
   bool newv= (permutation_map.find(v)==permutation_map.end());    

 for(auto &i:a){
   for(auto &j:b){
      f newf;
      if_f_match(i.first ,j.first,newf);
      if (newf[0]==-2){
         continue;
      }
      if(newv){
         gs.push_back(newf);
      }
      float s=i.second.s-i.second.end_cost-i.second.begin_cost+j.second.s;
      if(c.find( newf ) == c.end() || c[newf].s > s){
      c[newf] = assignment_ps(s,i.second.begin_cost,i.second.end_cost,v);
   }
  }
 }
 if(newv){
  permutation_map[v]=gs;
 }
   
}

static void combine_assignment_ps_list_loop(assignment_ps_map &a, assignment_ps_map &b, assignment_ps_map &c){
  // std::cout<<"begin combine_assignment_ps_list_loop"<<std::endl;
  f va=a.begin()->second.variables;
   f vb=b.begin()->second.variables;
   if (va==vb){for (auto i:permutation_map[va]){
     float s=a[i].s+b[i].s;
     c[i]=assignment_ps(s,b[i].begin_cost,b[i].end_cost,va);
   }     return;
}
f v=unionVectors(va,vb);
std::vector<f> gs; 
   bool newv= (permutation_map.find(v)==permutation_map.end());   
  for(auto &i:b){
   for(auto &j:a){
      f newf;
      if_f_match(i.first ,j.first,newf);;
     if (newf[0]==-2){
         continue;
      }
       if(newv){
         gs.push_back(newf);
      }
      float s=i.second.s+j.second.s;
      if(c.find( newf ) == c.end() || c[newf].s > s){
         c[newf] = assignment_ps(s,i.second.begin_cost,i.second.end_cost,v);
      }
   }
   }
   if(newv){
  permutation_map[v]=gs;
 }
}

template <class I_t>
static float instruction_cost_easy(const f & global, cfg_node &node, const I_t &I);

static void convert_to_global(std::vector<short int> v,std::vector<var_t> variables, f &global, int n){ 
   global.resize(n,-3);
   int end=variables.size();
   for(int i=0;i<end;++i){
      global[variables[i]]=getIndex(v,variables[i]);
   }}


static std::vector<f> generate_p_w(f variables, int n){
   std::vector<f> results;
   f v;
   f current;
   v.resize(MAX_NUM_REGS,-1);
   results.push_back(v);
   if(permutation_map.find(current)!=permutation_map.end()){
      std::vector<f> globs;
      for(auto i:results){
         f global;
         convert_to_global(i,current,global,n);
         globs.push_back(global);
      }
      permutation_map[current]=globs;
   }
   for(auto i:variables){
      current.push_back(i);
      std::vector<f> new_results;
      for(auto j:results){
         for(int k=0;k<MAX_NUM_REGS;++k){
            if(j[k]==-1){
               f newf=j;
               newf[k]=i;
               new_results.push_back(newf);
            }

      }
   }
   results.insert(results.end(),new_results.begin(),new_results.end());
   if(permutation_map.find(current)!=permutation_map.end()){
      std::vector<f> globs;
      for(auto i:results){
         f global;
         convert_to_global(i,current,global,n);
         globs.push_back(global);
      }
      permutation_map[current]=globs;
   }
   }
 return results;     
}


template <class I_t>
static void initlize_assignment_ps_list(ps_cfg_t &a, I_t &I){
    
    int n=boost::num_vertices(I);
      //print begin v
     if(permutation_map.find(a.begin_v)==permutation_map.end()){
      generate_p_w(a.begin_v,n);
     }
   std::vector<f>  begin_p=permutation_map[a.begin_v];
     

     
   //std::cout<<"end size:"<<end.size()<<std::endl;
   //std::cout<<"finish generating"<<std::endl;
   cfg_node node=((*(a.cfg))[a.begin]);
   for(auto i:begin_p){
         a.assignments.emplace(std::make_pair(i, assignment_ps(instruction_cost_easy(i,node,I),a.begin_v)));
   }
   
      
   
}

static void generate_spcfg(ps_cfg_t &ps_cfg){

   if (ps_cfg.assignments.size() == 0){
      if (ps_cfg_map[ps_cfg.left].assignments.size() == 0){
       //  std::cout<<"2"<<std::endl;
         generate_spcfg(ps_cfg_map[ps_cfg.left]);
      }
      if (ps_cfg_map[ps_cfg.right].assignments.size() == 0){
       //  std::cout<<"3"<<std::endl;
         generate_spcfg(ps_cfg_map[ps_cfg.right]);
      }
      switch (ps_cfg.type){
         case 1:
         //  std::cout<<"4"<<std::endl;
            combine_assignment_ps_list_series(ps_cfg_map[ps_cfg.left].assignments, ps_cfg_map[ps_cfg.right].assignments,ps_cfg.assignments);
         //  std::cout<<"current optimal:"<<get_optimal(ps_cfg,I).s<<std::endl;
            break;
         case 2:
         //   std::cout<<"5"<<std::endl;
            combine_assignment_ps_list_parallel(ps_cfg_map[ps_cfg.left].assignments, ps_cfg_map[ps_cfg.right].assignments,ps_cfg.assignments);
        //   std::cout<<"current optimal:"<<get_optimal(ps_cfg,I).s<<std::endl;
            break;
         case 3:
         //   std::cout<<"6"<<std::endl;
            combine_assignment_ps_list_loop(ps_cfg_map[ps_cfg.left].assignments, ps_cfg_map[ps_cfg.right].assignments,ps_cfg.assignments);
         //  std::cout<<"current optimal:"<<get_optimal(ps_cfg,I).s<<std::endl;
            break;
         default:
            break;
      }
   }
}

static assignment_ps get_optimal(ps_cfg_t &ps_cfg){
   assignment_ps_map a = ps_cfg.assignments;
   assignment_ps b;
   b.s = std::numeric_limits<float>::infinity();
   f c;
   for(auto i:a){
      //std::cout<<"i.second.s:"<<i.second.s<<std::endl;
      //std::cout << std::endl;
      if(b.s > i.second.s){
         b = i.second;
         c=i.first;
      }
   }


  std::cout << "our Winner: ";
  for(unsigned int i = 0; i < c.size(); i++)
  {
  	std::cout << "(" << i << ", " << int(c[i]) << ") ";
  }
  std::cout << "\n";
  std::cout << "Cost: " << b.s << "\n";
   
   return b;
}