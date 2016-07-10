//
//  main.cpp
//  netbf
//
//  Created by Gloria Budiman on 7/5/16.
//  Copyright © 2016 gbudiman. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "input_interface.hpp"
#include "output_interface.hpp"
#include "main.hpp"

int main(int argc, char** argv) {
  InputInterface* input = new InputInterface(argv[1]);
  input->bfs->run();
  OutputInterface(input->bfs, 0);
  return 0;
}
