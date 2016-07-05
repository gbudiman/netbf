//
//  node.hpp
//  netbf
//
//  Created by Gloria Budiman on 7/5/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <stdio.h>
#include <stdint.h>
#include <map>

class Node {  
public:
  Node(uint32_t);
  void add_link(uint32_t, uint32_t);
  std::map<uint32_t, uint32_t>* get_edges();
private:
  uint32_t id;
  std::map<uint32_t, uint32_t>* edges;
};
#endif /* node_hpp */
