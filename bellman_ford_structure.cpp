//
//  bellman_ford_structure.cpp
//  netbf
//
//  Created by Gloria Budiman on 7/5/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#include "bellman_ford_structure.hpp"

BellmanFordStructure::BellmanFordStructure() {
  nodes = new std::map<uint32_t, Node*>;
}

void BellmanFordStructure::add_node(uint32_t id) {
  if (nodes->find(id) == nodes->end()) {
    nodes->insert(std::make_pair(id, new Node(id)));
  } else {
    std::cout << "ALERT!! Overwriting modifying node " << id << "\n";
  }
}

void BellmanFordStructure::add_link(uint32_t id, uint32_t distance) {
  if (nodes->find(id) == nodes->end()) {
    std::cout << "ALERT!! Node not found: " << id;
  } else {
    nodes->at(id)->add_link(id, distance);
  }
}

void BellmanFordStructure::dump() {
  for (std::map<uint32_t, Node*>::iterator n = nodes->begin(); n != nodes->end(); ++n) {
    std::cout << "Node ID: " << n->first << "\n";
    
    std::map<uint32_t, uint32_t>* edges = n->second->edges;
    for (std::map<uint32_t, uint32_t>::iterator e = edges->begin(); e != edges->end(); ++e) {
      std::cout << "Edge " << e->first << ": " << e->second << "\n";
    }
  }
}