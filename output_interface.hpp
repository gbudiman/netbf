//
//  output_interface.hpp
//  netbf
//
//  Created by Gloria Budiman on 7/6/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#ifndef output_interface_hpp
#define output_interface_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "bellman_ford_structure.hpp"
#include "main.hpp"

#define OUTPUT_PATH "output.txt"

class OutputInterface {
public:
  OutputInterface(BellmanFordStructure*, uint32_t);
  static std::string itos(uint32_t);
private:
  void traverse_nodes(BellmanFordStructure*, uint32_t, std::string*);
  void recurse(std::map<uint32_t, uint32_t>*, uint32_t, uint32_t, std::vector<uint32_t>*);
};
#endif /* output_interface_hpp */
