//
//  bellman_ford_structure.hpp
//  netbf
//
//  Created by Gloria Budiman on 7/5/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#ifndef bellman_ford_structure_hpp
#define bellman_ford_structure_hpp

#define INF 0xFFFFFFFF

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include "node.hpp"

class BellmanFordStructure {
public:
  BellmanFordStructure();
  void add_node(uint32_t);
  void add_link(uint32_t, uint32_t);
  
  void run();
  
  void dump();
  void dump_trackers();
  
  std::map<uint32_t, Node*>* nodes;
  std::map<uint32_t, std::map<uint32_t, uint32_t>*>* distances;
  std::map<uint32_t, std::map<uint32_t, uint32_t>*>* preds;
  uint32_t node_count;
  uint32_t iteration_count;
private:
  void analyze(uint32_t);
  void init(uint32_t);
  bool step(uint32_t, uint32_t);
  uint32_t process_edge(uint32_t, uint32_t, uint32_t, uint32_t);
  bool has_path_between(uint32_t, uint32_t, uint32_t);
  bool traverse_path_between(uint32_t, uint32_t, uint32_t);
  void generate_workload(uint32_t, std::set<uint32_t>*);
};

#endif /* bellman_ford_structure_hpp */
