#include <stdint.h>
#include <stdlib.h>
#include <vector>

#define MAX_MAT 4

typedef std::vector<std::vector<int>> MAT;

struct Node {
  int index;
  Node *next;
};

template <class T>
struct Vertex {
  T element;
  Node *start;
};



template <class T>
class Graph {
public:
  Graph();

  void initialize();

  ~Graph();

  void build_graph_from_matrix(int mat[MAX_MAT][MAX_MAT], int n);

  void traverse_indepth(void (*func)(int i, int j, T element));

private:


  void _traverse_indepth_rec(void (*func)(int i, int j, T element),
                             int index,
                             std::vector<int> visited)

  std::vector<Vertex<T> *> _vertices;
  int _n;
};
#include "Graph.tpp"
