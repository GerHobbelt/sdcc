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

  cfg_node begin; //s node
  cfg_node end; //t node
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




static void convert_cfg_to_spcfg(cfg_t &cfg, mergelist mlist){
  //go through the cfg and find the in edge and out edge
  //if the in edge is 1 and the out edge is 1, then it is just series
  //if the in edge is 2 and the out edge is 1, then it is the start of loop merge
  //if the in edge is 1 and the out edge is 2, then it is the start of parallel merge
}
