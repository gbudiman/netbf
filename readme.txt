Gloria Budiman
6528-1836-50

=== COMPILING ===
make

=== CLEANUP ===
make clean

=== RUNNING ===
./BellmanFord <path_to_input_file>

=== OUTPUT ===
Hardcoded to "output.txt" in project's root directory

=== EXAMPLE ===
./BellmanFord input/N7.csv
cat output.txt
0,33,13,10,24,26,38
0
0->3->1
0->3->2
0->3
0->3->4
0->3->4->5
0->3->1->6
Iteration: 4
