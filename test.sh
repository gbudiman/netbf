make clean
make

./BellmanFord input/N7.csv
echo "Diff output ====="
diff -b output.txt input/output-N7.txt
echo "================="

./BellmanFord input/N10.csv
echo "Diff output ====="
diff -b output.txt input/output-N10.txt
echo "================="

./BellmanFord input/N20.csv
echo "Diff output ====="
diff -b output.txt input/output-N20.txt
echo "================="
