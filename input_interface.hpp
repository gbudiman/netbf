//
//  input_interface.hpp
//  netbf
//
//  Created by Gloria Budiman on 7/5/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#ifndef input_interface_hpp
#define input_interface_hpp

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "bellman_ford_structure.hpp"
#include "main.hpp"

class InputInterface {
public:
  InputInterface(const char *path);
  BellmanFordStructure* bfs;
  
private:
  void load();
  uint32_t parse(const char *line, uint32_t);
  
  char* filepath;
  uint32_t node_count;
};

#endif /* input_interface_hpp */
