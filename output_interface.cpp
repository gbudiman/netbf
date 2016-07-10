//
//  output_interface.cpp
//  netbf
//
//  Created by Gloria Budiman on 7/6/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#include "output_interface.hpp"

OutputInterface::OutputInterface(BellmanFordStructure* bfs, uint32_t origin) {
  std::string distance_str = "";
  std::string iteration_str = "Iteration: " + OutputInterface::itos(bfs->iteration_count);
  std::string traversal_str = "";
  std::map<uint32_t, uint32_t>* distance = bfs->distances->at(origin);
  
  traverse_nodes(bfs, origin, &traversal_str);
  for (std::map<uint32_t, uint32_t>::iterator d = distance->begin(); d != distance->end(); ++d) {
    distance_str += OutputInterface::itos(d->second) + ",";
  }
  distance_str.erase(distance_str.length() - 1);
  distance_str += "\n";
  
  if (PROJ_DEBUG) {
    std::cout << distance_str << "\n";
    std::cout << traversal_str << "\n";
    std::cout << iteration_str << "\n";
  }
  
  std::ofstream ofile;
  ofile.open("output.txt");
  ofile << distance_str;
  ofile << traversal_str;
  ofile << iteration_str;
  ofile.close();
}

void OutputInterface::traverse_nodes(BellmanFordStructure* bfs, uint32_t origin, std::string* s) {
  std::map<uint32_t, uint32_t>* pred = bfs->preds->at(origin);

  for (std::map<uint32_t, uint32_t>::iterator p = pred->begin(); p != pred->end(); ++p) {
    uint32_t node = p->first;
    std::vector<uint32_t>* paths = new std::vector<uint32_t>;
    
    paths->push_back(node);
    recurse(pred, node, origin, paths);
    std::reverse(paths->begin(), paths->end());
    
    for (std::vector<uint32_t>::iterator p = paths->begin(); p != paths->end(); ++p) {
      s->append(OutputInterface::itos(*p) + "->");
    }
    s->erase(s->length() - 2);
    
    s->append("\n");
  }
}

void OutputInterface::recurse(std::map<uint32_t, uint32_t>* pred, uint32_t node, uint32_t origin, std::vector<uint32_t> *paths) {
  
  uint32_t previous_node = pred->at(node);
  
  if (previous_node == origin) {
    if (node != origin) {
      paths->push_back(previous_node);
    }
  } else {
    paths->push_back(previous_node);
    recurse(pred, previous_node, origin, paths);
  }
}

std::string OutputInterface::itos(uint32_t x) {
  std::ostringstream oss;
  oss << x;
  return oss.str();
}
