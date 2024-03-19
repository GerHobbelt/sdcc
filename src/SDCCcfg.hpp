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

std::map<int, unsigned int> key_to_index;
typedef int merge_type;
stucture ps_cfg_t{

  cfg_node &begin; //s node
  cfg_node &end; //t node
  cfg_t &cfg; //graph contains s and t node
  merge_type type;
  ps_cfg_t &left;
  ps_cfg_t &right;
}

static ps_cfg_t init_ps_cfg(cfg_t &cfg, vertex begin_node, vertex end_node){
  ps_cfg_t ps_cfg;
  ps_cfg.cfg=cfg;
  ps_cfg.begin=begin_node;
  ps_cfg.end=end_node;
  ps_cfg.type=0;
  ps_cfg.left=NULL;
  ps_cfg.right=NULL;
  return ps_cfg;
}

//break the graph into two series part
static void break_graph_series(cfg_t &cfg, vertex begin_node, vertex end_node, cfg_t &cfg_1, cfg_t &cfg_2,ps_cfg_t &ps_cfg){
  graph_traits<Graph>::vertex_iterator vi, vi_end, next,f;
  boost::tie(vi, vi_end) = boost::vertices(cfg);
  ps_cfg.merge_type=1;
  vi=begin_node;
 
  for (next = vi; next != vi_end; vi=next){
      ++next;
      boost::remove_vertex(cfg[i], cfg_1);
      if (*next==end_node){
        break;
      }
  }
  ps_cfg.right=init_ps_cfg(cfg_1,end_node, *(vi_end-1));
  f=vi;
  vi=next;
  for (next = vi; next != vi_end; vi=next) {
      ++next;
      boost::remove_vertex(*vi, cfg_2);
  }
  ps_cfg.left=init_ps_cfg(cfg_2,begin_node, *f);
}

static void break_graph_parallel(cfg_t &cfg, vertex begin_node, vertex end_node, cfg_t &cfg_1, cfg_t &cfg_2,ps_cfg_t &ps_cfg){
  graph_traits<Graph>::vertex_iterator vi, vi_end, next;
  boost::tie(vi, vi_end) = boost::vertices(cfg);
  ps_cfg.merge_type=2;
  graph_traits < Graph >::out_edge_iterator ei, ei_end;
  vertex p_s=NULL;
  for (boost::tie(ei, ei_end) = boost::out_edges(begin_node, cfg); ei != ei_end; ++ei) {
    vertex target = boost::target ( *ei, g );
    if (p_s==NULL || key_to_index[source->ic->key]>key_to_index[p_end->ic->key]){
      p_s=source;
    }
  }
  ++vi;
  for (next = vi; next != vi_end; vi=next) {
      ++next;
      boost::remove_vertex(*vi, cfg_1);
      if (*next==p_s){
        break;
      }
  }
  ps_cfg.left=init_ps_cfg(cfg_1,begin_node, end_node);
  vi=next;
  --vi_end;
  for (next = vi; next != vi_end; vi=next) {
      ++next;
      boost::remove_vertex(*vi, cfg_2);
  }
  ps_cfg.right=init_ps_cfg(cfg_2,begin_node, end_node); 
}

static vertex find_parallel_end(cfg_t &cfg){
  graph_traits<Graph>::vertex_iterator vi, vi_end, next;
  boost::tie(vi, vi_end) = boost::vertices(cfg);
  int count=0;
  for (next = vi; next != vi_end; vi=next) {
    ++next;
    if (boost::in_degree(*vi,cfg)=2 ){
         graph_traits < Graph >::in_edge_iterator ei, ei_end;
         int flag=0;
         for (boost::tie(ei, ei_end) = boost::in_edges(*vi, cfg); ei != ei_end; ++ei) {
             vertex source = boost::source ( *ei, g );
             if(key_to_index[source->ic->key]<key_to_index[(*vi)->ic->key]){
               flag++;
             }
         }
         if (flag==2){
            count=count-1;
            if (count==0){
              return *vi;
            }
         }else{
            next=next+1;
            graph_traits < Graph >::out_edge_iterator eei, eei_end;
            vertex l_end=NULL;
            for (boost::tie(eei, eei_end) = boost::out_edges(*next, cfg); eei != eei_end; ++eei) {
              vertex target = boost::target ( *eei, g );
              if( l_end=NULL||key_to_index[target->ic->key]>key_to_index[l_end->ic->key]){
                l_end=target;
              }
            }
            while (*next!=l_end){
              next++;
            }
          }
         
    }
    if(boost::out_degree(*vi,cfg)=2){
      count++;
    }
  }
  return NULL;
}

static void break_graph_loop(cfg_t &cfg, vertex begin_node, vertex end_node, cfg_t &cfg_1, cfg_t &cfg_2,ps_cfg_t &ps_cfg){
  ps_cfg.merge_type=3;
  graph_traits<Graph>::vertex_iterator vi, vi_end, next,f;
  boost::tie(vi, vi_end) = boost::vertices(cfg);
  f=vi+3;
  for(next=vi; next!=vi_end; vi=next){
    ++next;
    boost::remove_vertex(*vi, cfg_1);
    if (next==f){
      break;
    }
  }
  ps_cfg.left=init_ps_cfg(cfg_1,begin_node, *vi);
  vi=f;
  for(next=vi; next!=vi_end; vi=next){
    ++next;
    boost::remove_vertex(*vi, cfg_1);
  }
  ps_cfg.right=init_ps_cfg(cfg_2,*f, *(vi_end-1));
}

static ps_cfg_t convert_cfg_to_spcfg_one_step(cfg_t &cfg){
  //convert the original cfg to the root node of ps_cfg
  ps_cfg_t pscfg;
  graph_traits<Graph>::vertex_iterator vi, vi_end, next;
  boost::tie(vi, vi_end) = boost::vertices(cfg);
  pscfg=init_ps_cfg(cfg, *vi, *(vi_end-1));
  if (*vi == *(vi_end-1)) {
    return ps_cfg;
  }

  next=vi;
  next++;
  //series merge - boost::in_degree=1, boost::out_degree=1
  if (boost::in_degree(*vi,cfg)=0 && out_degree(*vi, cfg) == 1 && boost::in_degree(*next,cfg)=1 ){
    cfg_t cfg_1, cfg_2;
    boost::copy_graph(cfg, cfg_1, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
    boost::copy_graph(cfg, cfg_2, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
    break_graph_series(cfg, *vi, *next, cfg_1, cfg_2,pscfg);
    return pscfg;
  }
  //start of parallel merge - in degree=1, out degree=2, both next verdexes with larger index
  //end of parallel merge - in degree=2, out degree=1, both previous vertexes with smaller index
  if (boost::out_degree(*vi,cfg)=2){
    vertex p_end=find_parallel_end(cfg);
    if(*(vi_end-1)!=p_end){
      //if the graph is built by parallel merge then series merge
      cfg_t cfg_1, cfg_2;
      boost::copy_graph(cfg, cfg_1, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
      boost::copy_graph(cfg, cfg_2, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
      next=vi;
      while(*next!=p_end){
        next++;
      }
      break_graph_series(cfg, *vi, *(next+1), cfg_1, cfg_2, pscfg);
      return pscfg;
    }else{
      //if the graph is built by parallel merge directly
      cfg_t cfg_1, cfg_2;
      boost::copy_graph(cfg, cfg_1, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
      boost::copy_graph(cfg, cfg_2, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
      break_graph_parallel(cfg, *vi, p_end, cfg_1, cfg_2, pscfg);
    }
    return pscfg;
  }
  //start of loop merge - in degree=2, out degree=1, one previous vertex is larger and one is smaller
  //end of loop merge - in degree=1, out degree=2, both next vertexes with larger index.
  if (boost::in_degree(*vi,cfg)==2){
    if (boost::out_degree(*(vi+2),cfg)==1){
      cfg_t cfg_1, cfg_2;
      boost::copy_graph(cfg, cfg_1, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
      boost::copy_graph(cfg, cfg_2, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
      break_graph_loop(cfg, *vi, *(vi+2), cfg_1, cfg_2, pscfg);
      return pscfg;
    }else{
      graph_traits < Graph >::out_edge_iterator eei, eei_end;
      vertex l_end=NULL;
      next=vi+2;
      for (boost::tie(eei, eei_end) = boost::out_edges(*next, cfg); eei != eei_end; ++eei) {
        vertex target = boost::target ( *eei, g );
        if( l_end=NULL||key_to_index[target->ic->key]>key_to_index[l_end->ic->key]){
          l_end=target;
        }
      }
      cfg_t cfg_1, cfg_2;
      boost::copy_graph(cfg, cfg_1, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
      boost::copy_graph(cfg, cfg_2, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
      break_graph_series(cfg, *vi, l_end, cfg_1, cfg_2, pscfg);
      return pscfg
    }
  }
  return pscfg
}
