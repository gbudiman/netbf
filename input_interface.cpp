//
//  input_interface.cpp
//  netbf
//
//  Created by Gloria Budiman on 7/5/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#include "input_interface.hpp"

InputInterface::InputInterface(const char* path) {
  filepath = (char*) path;
  node_count = 0;
  bfs = new BellmanFordStructure();
  
  load();
}

void InputInterface::load() {
  printf("Successfully called\n");
  std::string line = *new std::string();
  std::ifstream ifs(filepath, std::ifstream::in);
  uint32_t node_id = 0;
  
  if (ifs.is_open()) {
    std::cout << "Reading file [" << filepath << "]\n";
    
    while (std::getline(ifs, line)) {
      node_id += parse(line.c_str(), node_id);
    }
  } else {
    std::cout << "File [" << filepath << "] is not accessible\n";
  }
  
  bfs->node_count = node_id;
  bfs->dump();
}

uint32_t InputInterface::parse(const char* line, uint32_t node_id) {
  uint32_t destination_id = 0;
  uint32_t distance = 0;
  char *element;
  element = strtok((char*) line, ",");
  
  if (element != NULL) {
    bfs->add_node(node_id);
  
    while (element != NULL) {
      //if (strcmp(&element[0], "*") == 0) {
      if (element[0] == '*') {
        // ignored
      } else if (destination_id == node_id) {
        // ignored
      } else {
        distance = (uint32_t) std::strtol(element, NULL, 10);
        bfs->nodes->at(node_id)->add_link(destination_id, distance);
      }
      
      destination_id++;
      element = strtok(NULL, ",");
    }
    
    return 1;
  }
  
  return 0;
}
