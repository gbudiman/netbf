//
//  node.cpp
//  netbf
//
//  Created by Gloria Budiman on 7/5/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#include "node.hpp"


Node::Node(uint32_t id) {
  this->id = id;
  edges = new std::map<uint32_t, uint32_t>;
}

void Node::add_link(uint32_t target, uint32_t distance) {
  edges->insert(std::pair<uint32_t, uint32_t>(target, distance));
}
