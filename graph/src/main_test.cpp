#include "Graph.h"
#include <vector>
#include <iostream>


void traverse_print(int i, int j, int element) {
  // std::cout << "[" << i << "]" << "---->" << "[" << j << "]\n";
  std::cout << '[' << i << "]\n";
  std::cout << " | \n";
}

int main() {

  Graph<int> g;

  int mat[MAX_MAT][MAX_MAT] = {
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 0},
    {1, 0, 0, 0}
  };

  g.build_graph_from_matrix(mat, 4);
  g.traverse_indepth(traverse_print);

  std::cout << "---------------------------\n";
  g.traverse_indepth_v2(traverse_print);

  return 0;
}
