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

    // assigning the node
    if (_vertices[i] == nullptr) {

      //allocating vertex for the first time
      Vertex<T> *new_vertex = (Vertex<T>*)malloc(sizeof(Vertex<T>));
      new_vertex->start = nullptr;
      new_vertex->end = nullptr;

      //attacing the vertex
      _vertices[i] = new_vertex;

      // new_vertex -> element = element;
    }
    _n ++;

    for (int j=0; j<n; j++) {

      if(mat[i][j]) {

        // allocating new node
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node -> index = j;
        new_node -> next = nullptr;

        // assigning the node
        if (_vertices[i]->start == nullptr) {

          _vertices[i]->start = new_node;
          _vertices[i]->end = new_node;
        }
        else {
          _vertices[i]->end->next = new_node;
          _vertices[i]->end = new_node;
        }
      }
    }
  }
}



template <class T>
void Graph<T>::_traverse_indepth_rec(void (*func)(int i, int j, T element),
                                     int start_i,
                                     std::vector<int> &visited) {
  if (_vertices[start_i]->start) {
    func(start_i, _vertices[start_i]->start->index, _vertices[start_i]->element);
  }
  visited[start_i] = 1;

  // looping throw Av adjacent to the vertex
  for(Node *node = _vertices[start_i] -> start; node; node = node -> next) {
    if (!visited[node->index]) {
    // (*func)(start_i, node->index, _vertices[start_i]->element); //applying func
    _traverse_indepth_rec(func, node->index, visited);
    }
  }
}


template <class T>
void Graph<T>::traverse_indepth(void (*func)(int i, int j, T element)) {

  // initialize visited with zeros
  std::vector<int> visited = std::vector<int>(_n, 0);

  _traverse_indepth_rec(func, 0, visited);

  //isolated vertices
  for (int i=0; i<_n; i++) {
    if(!visited[i]) {
      _traverse_indepth_rec(func, i, visited);
    }
  }
}




template <class T>
void Graph<T>::_traverse_indepth_rec_v2(void (*func)(int i, int j, T element),
                                     int start_i,
                                     std::vector<Node *> &visited) {
  if (_vertices[start_i]->start) {
    func(start_i, _vertices[start_i]->start->index, _vertices[start_i]->element);
  }
  if (visited[start_i] == nullptr) {
    visited[start_i] = _vertices[start_i]->start;
  }

  int endpoint=0;

  // looping throw Av adjacent to the vertex
  for(Node *node = visited[start_i]; node; node = node -> next) {
    endpoint = node->index;
    if (!visited[endpoint]) {

      // the node to be visited has a path to the current vertex
      if(_vertices[endpoint]->start) {
        if(_vertices[endpoint]->start->index == start_i) {
        visited[endpoint] = _vertices[endpoint]->start->next;
        }
      }
      _traverse_indepth_rec_v2(func, endpoint, visited);

    }
  }
}



template <class T>
void Graph<T>::traverse_indepth_v2(void (*func)(int i, int j, T element)) {

  // initialize visited with zeros
  std::vector<Node *> visited = std::vector<Node *>(_n, nullptr);

  _traverse_indepth_rec_v2(func, 0, visited);

  // //isolated vertices
  // visited = std::vector<int>(_n, 0);
  // for (int i=0; i<_n; i++) {
  //   if(!visited[i]) {
  //     _traverse_indepth_rec(func, i, visited);
  //   }
  // }
}

