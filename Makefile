all: BellmanFord

BellmanFord: main input_interface bellman_ford_structure node
	g++ main.o input_interface.o bellman_ford_structure.o node.o -o BellmanFord

main: main.cpp 
	g++ -c main.cpp

input_interface: input_interface.cpp
	g++ -c input_interface.cpp input_interface.hpp

bellman_ford_structure: bellman_ford_structure.cpp
	g++ -c bellman_ford_structure.cpp bellman_ford_structure.hpp

node: node.cpp
	g++ -c node.cpp node.hpp

clean:
	rm *o BellmanFord
