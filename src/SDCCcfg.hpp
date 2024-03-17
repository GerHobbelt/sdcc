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


typedef int merge_type;

structure merge_node{
  merge_type type;
  ps_cfg_t &left;
  ps_cfg_t &right;
}

stucture ps_cfg_t{

  cfg_node &begin; //s node
  cfg_node &end; //t node
  cfg_t &cfg; //graph contains s and t node
  merge_node &merge; //merge type
}

static merge_node merge_node_init(merge_type type, ps_cfg_t &left, ps_cfg_t &right){
  merge_node &m;
  m.type = type;
  m.left = left;
  m.right = right;
  return &m;
}

//series_merge
static void series_merge(ps_cfg_t &cfg_1, ps_cfg_t &cfg_2, ps_cfg_t &cfg_3)
{
  boost::copy_graph(cfg_1.cfg, cfg_3.cfg, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
  boost::copy_graph(cfg_2.cfg, cfg_3.cfg, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
  boost::add_edge(cfg_1.end, cfg_2.begin, cfg_3.cfg);
  cfg_3.begin = cfg_1.begin;
  cfg_3.end = cfg_2.end;
  cfg_3.merge = merge_node_init(1, cfg_1, cfg_2);
}

//parallel_merge
static void parallel_merge(ps_cfg_t &cfg_1, ps_cfg_t &cfg_2,ps_cfg_t &cfg_3 )
{
  boost::copy_graph(cfg_1.cfg, cfg_3.cfg, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
  boost::copy_graph(cfg_2.cfg, cfg_3.cfg, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
  boost::add_edge(cfg_1.begin, cfg_2.begin, cfg_3.cfg);
  boost::add_edge(cfg_2.end, cfg_1.end, cfg_3.cfg);
  cfg_3.begin = cfg_1.begin;
  cfg_3.end = cfg_1.end;
  cfg_3.merge = merge_node_init(2, cfg_1, cfg_2);
}

//loop_merge
static void loop_merge(ps_cfg_t &cfg_1, ps_cfg_t &cfg_2, ps_cfg_t &cfg_3){

  boost::copy_graph(cfg_1.cfg, cfg_3.cfg, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
  boost::copy_graph(cfg_2.cfg, cfg_3.cfg, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
  boost::add_edge(cfg_1.begin, cfg_2.begin, cfg_1.cfg);
  boost::add_edge(cfg_2.end, cfg_1.begin, cfg_1.cfg);
  cfg_3.begin = cfg_1.begin;
  cfg_3.end = cfg_1.end;
  cfg_3.merge = merge_node_init(3, cfg_1, cfg_2);
}

static int if_loop_end(cfg_t &cfg, vertex vi){
  if(indegree(vi,cfg)!=1){
    return 0;
  }
  typename GraphTraits::in_edge_iterator in_i, in_end;
  boost::tie(in_i, in_end) = in_edges(vi, cfg);
  Vertex src = source(*in_i, cfg);
  if(indegree(src,cfg)!=1){
    return 0;
  }
  boost::tie(in_i, in_end) = in_edges(source, cfg);
  Vertex src = source(*in_i, cfg);
  if(indegree(src,cfg)==2){
     for ( boost::tie(in_i, in_end) = in_edges(src, cfg);in_i != in_end; ++in_i) {
          e = *in_i;
          Vertex src = source(e, cfg);
          if(src.index<vi.index){
            flag++;
          }
      }
      if (flag==1){
        return 1;
      }
  }
  return 0;
}

static ps_cfg_t get_parallel_part(cfg_t &cfg, vertex begin_loop){
  graph_traits<Graph>::vertex_iterator vi, vi_end, next;
  boost::tie(vi, vi_end) = vertices(cfg);
  vi=begin_loop;
  for (next = vi; vi != vi_end; vi = next) {
      ++next;
      flag=0;
      if(indegree(vi,cfg)=2 && out_degree(vi, cfg) == 1){
        typename GraphTraits::in_edge_iterator in_i, in_end;
        for ( boost::tie(in_i, in_end) = in_edges(vi, cfg);in_i != in_end; ++in_i) {
          e = *in_i;
          Vertex src = source(e, cfg);
          if(src.index<vi.index){
            flag++;
          }
        }
        if (flag==2){
          //this is the end of loop, create the tree  
       }
      }
      if(indegree(vi,cfg)=1 && out_degree(vi, cfg) == 2){
        //check if it is the end of loop or the start of parallel
       }
}


static pscfg convert_cfg_to_spcfg(cfg_t &cfg){
  //convert the original cfg to the root node of ps_cfg
  ps_cfg_t pscfg;
  pscfg.cfg=cfg;
  graph_traits<Graph>::vertex_iterator vi, vi_end, next;
  boost::tie(vi, vi_end) = vertices(cfg);
  if (*vi == *(vi_end-1)) {
    ps_cfg.begin=*vi;
    ps_cfg.end=vi;
    ps_cfg.merge=NULL; 
    return ps_cfg;
  }
  pscfg.begin = *vi;
  pscfg.end = *(vi_end-1);
  //series merge - indegree=1, outdegree=1
  if (indegree(vi,cfg)=0 && out_degree(vi, cfg) == 1 && indegree(next,cfg)=1 ){
    cfg_t cfg_1, cfg_2;
    boost::copy_graph(cfg, cfg_1, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
    boost::copy_graph(cfg, cfg_2, boost::vertex_copy(forget_properties()).edge_copy(forget_properties()));
    remove_vertex(*vi, cfg_2);
    vi=next;
    for (next = vi; vi != vi_end; vi = next) {
      ++next;
      remove_vertex(*vi, cfg_1);
   }
   pscfg.merge = merge_node_init(1, convert_cfg_to_spcfg(cfg_1),convert_cfg_to_spcfg(cfg_2) );
  }
  //start of parallel merge - in degree=1, out degree=2, both next verdexes with larger index
  //end of parallel merge - in degree=2, out degree=1, both previous vertexes with smaller index
  //start of loop merge - in degree=2, out degree=1, one previous vertex is larger and one is smaller
  //end of loop merge - in degree=1, out degree=2, both next vertexes with larger index.
  //index of end of loop is always 2 larger than loop of begin
  
}
