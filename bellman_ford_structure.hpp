//
//  bellman_ford_structure.hpp
//  netbf
//
//  Created by Gloria Budiman on 7/5/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#ifndef bellman_ford_structure_hpp
#define bellman_ford_structure_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include "node.hpp"

class BellmanFordStructure {
public:
  BellmanFordStructure();
  void add_node(uint32_t);
  void add_link(uint32_t, uint32_t);
  std::map<uint32_t, Node*>* get_nodes();
  
  void dump();
private:
  std::map<uint32_t, Node*>* nodes;
};

#endif /* bellman_ford_structure_hpp */
