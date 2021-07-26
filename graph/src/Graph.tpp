template <class T>
void Graph<T>::initialize() {
  _n =0;
}

template<class T>
Graph<T>::Graph() {
  initialize();
}




template<class T>
Graph<T>::~Graph() {
}




template <class T>
void Graph<T>::build_graph_from_matrix(int mat[MAX_MAT][MAX_MAT], int n) {


  // initialize the pointers of the vector
  _vertices = std::vector<Vertex<T> *>(n, nullptr);

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++)

      if(mat[i][j] == 1) {

        // allocating new node
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node -> index = j;
        new_node -> next = nullptr;


        // assigning the node
        if (_vertices[i] == nullptr) {
          _vertices[i] -> start = new_node;
        }

        _vertices[i] -> start -> next = new_node;
      }
    _n ++;
  }
}



template <class T>
void Grapth<T>::traverse_indepth(void (*func)(int i, int j, T element)) {

  // initialize visited with zeros
  _visited = std::vector<int>(_n, 0);

  _traverse_indepth_rec(&func, 0, visited);
}
