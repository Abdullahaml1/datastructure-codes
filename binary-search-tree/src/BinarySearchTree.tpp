template <class K, class T>
BinarySearchTree<K, T>::BinarySearchTree() {
  initialize();
}



template <class K, class T>
BinarySearchTree<K, T>::BinarySearchTree( int (*comp)(K key1, K key2)) {
  initialize();
  _comp = comp;
}






template <class K, class T>
BinarySearchTree<K, T>::~BinarySearchTree() {
  clean();
}



template <class K, class T>
void BinarySearchTree<K, T>::initialize() {
  _root_ptr = nullptr;
  _size_count = 0;
  _comp = nullptr;
}


template <class K, class T>
int BinarySearchTree<K,T>::insert(K key, T element) {

  // first time to insert
  if (_root_ptr == nullptr) {
    _root_ptr = (Vertex<K,T> *)malloc(sizeof(Vertex<K,T>));

    // unsuccessful allocation
    if(_root_ptr== nullptr){
      return -1;
      }

    _root_ptr -> key = key;
    _root_ptr -> element = element;
    _root_ptr -> left = nullptr;
    _root_ptr -> right = nullptr;

    _size_count ++;
    return 0;

  }
  Vertex<K,T>* new_vertex_ptr = nullptr;
  Vertex<K,T>* itr = _root_ptr;
  Vertex<K,T>* parent=nullptr;

  // preparing the new node;
  new_vertex_ptr = (Vertex<K,T> *)malloc(sizeof(Vertex<K,T>));

  // unsuccessful allocation
  if(new_vertex_ptr== nullptr){
    return -1;
  }
  new_vertex_ptr -> key = key;
  new_vertex_ptr -> element = element;
  new_vertex_ptr -> left = nullptr;
  new_vertex_ptr -> right = nullptr;

  while(itr != nullptr) {

    parent = itr;

    // bigger than -> walk right
    if (_comp(key, itr -> key) > 0) {
      itr = itr -> right;
    }
    // less than or equal -> walk left
    else {
      itr = itr -> left;
    }
  }


  if (_comp(key, parent -> key) > 0) {
    parent -> right = new_vertex_ptr;
  }
  else {
    parent -> left = new_vertex_ptr;
  }

  _size_count ++;

  return 0;
}




template<class K, class T>
void BinarySearchTree<K,T>::draw_tree() {
  std::vector<std::string> levels_vec;

  _fill_levels(_root_ptr, 0, levels_vec);

  int offset = levels_vec[levels_vec.size()-1].size() / 2 + 1;
  std::cout << offset << std::endl;
  int step = levels_vec[0].size();

  for(auto itr=levels_vec.begin(); itr != levels_vec.end(); ++itr) {
    std::cout << std::string(offset, ' ') << *itr << std::endl;
    offset -=step;
  }
}




template <class K, class T>
void BinarySearchTree<K,T>::_fill_levels(Vertex<K,T>* tree, int level,
                                         std::vector<std::string> &vec) {
  // VLR: vertex, left, right
  if (tree != nullptr) {
    //V
    std::ostringstream oss;
    if(level < vec.size()) {
      oss << std::string(5,' ') << "[" << tree -> key << "]=" << tree -> element;
      vec[level] += oss.str();
    }
    else {
      oss << "[" << tree -> key << "]=" << tree -> element;
      vec.push_back(oss.str());
    }

    //L
    _fill_levels(tree -> left, level+1, vec);

    //R
    _fill_levels(tree -> right, level+1, vec);
  }
}





template <class K, class T>
void BinarySearchTree<K,T>::clean(){
}






template <class K, class T>
size_t BinarySearchTree<K,T>::size() {
  return _size_count;
}
