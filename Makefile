all: BellmanFord

BellmanFord: main input_interface bellman_ford_structure node output_interface
	g++ main.o input_interface.o bellman_ford_structure.o node.o output_interface.o -o BellmanFord

main: main.cpp main.hpp
	g++ -c main.cpp main.hpp

input_interface: input_interface.cpp
	g++ -c input_interface.cpp input_interface.hpp

bellman_ford_structure: bellman_ford_structure.cpp
	g++ -c bellman_ford_structure.cpp bellman_ford_structure.hpp

node: node.cpp
	g++ -c node.cpp node.hpp

output_interface: output_interface.cpp
	g++ -c output_interface.cpp output_interface.hpp

clean:
	rm *o *gch BellmanFord
	rm output.txt
