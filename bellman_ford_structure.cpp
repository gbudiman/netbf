//
//  bellman_ford_structure.cpp
//  netbf
//
//  Created by Gloria Budiman on 7/5/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#include "bellman_ford_structure.hpp"

BellmanFordStructure::BellmanFordStructure() {
  nodes     = new std::map<uint32_t, Node*>;
  distances = new std::map<uint32_t, std::map<uint32_t, uint32_t>*>();
  preds     = new std::map<uint32_t, std::map<uint32_t, uint32_t>*>();
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

void BellmanFordStructure::run() {
  analyze(0);
  
  std::cout << "Bellman-Ford run completed\n";
}

void BellmanFordStructure::analyze(uint32_t origin) {
  bool terminated_early = false;
  uint32_t iteration = 0;
  init(origin);
  
  dump_trackers();
  for (iteration = 0; iteration < node_count && !terminated_early; iteration++) {
    terminated_early = step(origin, iteration);
  }
  
  std::cout << "Algorithm completed at iteration " << iteration << "\n";
  iteration_count = iteration;
}

void BellmanFordStructure::init(uint32_t origin) {
  std::map<uint32_t, uint32_t>* distance = new std::map<uint32_t, uint32_t>();
  std::map<uint32_t, uint32_t>* pred = new std::map<uint32_t, uint32_t>();
  
  for (uint32_t i = 0; i < node_count; i++) {
    distance->insert(std::pair<uint32_t, uint32_t>(i, INF));
    pred->insert(std::pair<uint32_t, uint32_t>(i, INF));
  }
  
  distance->at(origin) = 0;
  pred->at(origin) = origin;
  
  std::pair<uint32_t, std::map<uint32_t, uint32_t>*> pair_dist;
  std::pair<uint32_t, std::map<uint32_t, uint32_t>*> pair_pred;
  
  pair_dist = std::make_pair(origin, distance);
  pair_pred = std::make_pair(origin, pred);
  
  distances->insert(pair_dist);
  preds->insert(pair_pred);
}

bool BellmanFordStructure::step(uint32_t origin, uint32_t iteration) {
  std::cout << "\n#### BEGIN ITERATION " << iteration << " ####\n\n";
  std::set<uint32_t>* workload = new std::set<uint32_t>();
  uint32_t updates = 0;

  generate_workload(origin, workload);
  for (std::set<uint32_t>::iterator w = workload->begin(); w != workload->end(); ++w) {
    std::cout << "Relaxing node " << *w << "\n";
    
    std::map<uint32_t, uint32_t>* edges = nodes->at(*w)->edges;
    for (std::map<uint32_t, uint32_t>::iterator e = edges->begin(); e != edges->end(); ++e) {
      updates += process_edge(origin, *w, e->first, e->second);
      dump_trackers();
    }
  }
  
  if (updates == 0) {
    std::cout << "Early termination called at iteration " << iteration << "\n";
    return true;
  }
  
  return false;
}

void BellmanFordStructure::generate_workload(uint32_t origin, std::set<uint32_t> *workload) {
  std::map<uint32_t, uint32_t>* distance = distances->at(origin);
  
  for (std::map<uint32_t, uint32_t>::iterator d = distance->begin(); d != distance->end(); ++d) {
    if (d->second != INF) {
      workload->insert(d->first);
//      std::map<uint32_t, uint32_t> *edges = nodes->at(d->first)->edges;
//      for (std::map<uint32_t, uint32_t>::iterator e = edges->begin(); e != edges->end(); ++e) {
//        workload->insert(e->first);
//      }
    }
  }
}

uint32_t BellmanFordStructure::process_edge(uint32_t origin, uint32_t source, uint32_t target, uint32_t dist) {
  uint32_t current_dist = distances->at(origin)->at(source);
  uint32_t new_dist;
  uint32_t target_dist = distances->at(origin)->at(target);
  
  if (current_dist == INF) {
    new_dist = dist;
  } else {
    new_dist = current_dist + dist;
  }
  
  if (new_dist < target_dist) {
    distances->at(origin)->at(target) = new_dist;
    preds->at(origin)->at(target) = source;
    
    return 1;
  }
  
  return 0;
}

bool BellmanFordStructure::traverse_path_between(uint32_t origin, uint32_t source, uint32_t target) {
  uint32_t pred = preds->at(origin)->at(target);
  
  if (pred == INF) {
    std::cout << "\n";
    return false; // no path existed
  } else {
    std::cout << " => " << pred;
    if (pred == source) {
      std::cout << "\n";
      return true;
    } else {
      return traverse_path_between(origin, source, pred);
    }
  }
}

void BellmanFordStructure::dump_trackers() {
  std::map<uint32_t, uint32_t>* distance = distances->at(0);
  std::map<uint32_t, uint32_t>* pred = preds->at(0);
  
  std::cout << "   ";
  for (int i = 0; i < node_count; i++) {
    printf("%3d ", i);
  }
  std::cout << "\n";
  
  std::cout << "D: ";
  for (std::map<uint32_t, uint32_t>::iterator d = distance->begin(); d != distance->end(); ++d) {
    if (d->second == INF) {
      std::cout << "INF ";
    } else {
      printf("%3d ", d->second);
    }
  }
  std::cout << "\n";
  
  std::cout << "P: ";
  for (std::map<uint32_t, uint32_t>::iterator p = pred->begin(); p != pred->end(); ++p) {
    if (p->second == INF) {
      std::cout << "INF ";
    } else {
      printf("%3d ", p->second);
    }
  }
  std::cout << "\n";
  std::cout << "----------------------------\n";
  
}
