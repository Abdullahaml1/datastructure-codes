#include "Graph.h"
#include <vector>


int main() {

  Graph<int> g;

  int mat[MAX_MAT][MAX_MAT] = {
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0}
  };

  g.build_graph_from_matrix(mat, 4);

  return 0;
}
