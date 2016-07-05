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

int main(int argc, char** argv) {
  std::cout << "Hello world\n";
  InputInterface* input = new InputInterface(argv[1]);
  return 0;
}