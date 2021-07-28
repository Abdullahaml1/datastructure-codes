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
  Node *end;
};



template <class T>
class Graph {
public:
  Graph();

  void initialize();

  ~Graph();

  // allowing single path to the same vertex
  void build_graph_from_matrix(int mat[MAX_MAT][MAX_MAT], int n);

  void traverse_indepth(void (*func)(int i, int j, T element));


  void traverse_indepth_v2(void (*func)(int i, int j, T element));



private:


  // support bidirectional paths without repetaion to the same vertex
  void _traverse_indepth_rec(void (*func)(int i, int j, T element),
                             int start_i,
                             std::vector<int> &visited);


  // support bidirectional paths without repetaion to the same vertex
  void _traverse_indepth_rec_v2(void (*func)(int i, int j, T element),
                             int start_i,
                             std::vector<Node *> &visited);



  std::vector<Vertex<T> *> _vertices;
  int _n;
};
#include "Graph.tpp"
