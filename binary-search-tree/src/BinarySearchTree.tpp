#define SPACING 4




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
  std::vector<int> index_vec;
  int offset =0, step =0;

  _fill_levels(_root_ptr, 0, 0, index_vec, levels_vec);

  if (! levels_vec.empty()) {
    step = (int)levels_vec[0].size() /2;
  }
  offset = (int)std::pow(2, (float)levels_vec.size()-2) * SPACING * 2 -4;
  std::cout << "offset=" << offset << std::endl;
  std::cout << "step =" << step << std::endl;


  for(auto itr=levels_vec.begin(); itr != levels_vec.end()-1; ++itr) {
    std::cout << std::string(offset, ' ') << *itr << std::endl;
    step = step+step/2;
    offset -= step;
  }
  std::cout << *(levels_vec.end()-1) << std::endl; // the last element
}




template <class K, class T>
void BinarySearchTree<K,T>::_fill_levels(Vertex<K,T>* tree,
                                         int level, int pos,
                                         std::vector<int>&index_vec,
                                         std::vector<std::string> &vec) {
  // VLR: vertex, left, right
  if (tree != nullptr) {


    //V
    std::ostringstream oss;
    oss << tree -> key << "=>" << tree -> element << std::string(SPACING, ' ');

    if(level < (int)vec.size()) {
      int offset=0;

      offset = pos - index_vec[level] -1;

      vec[level] += std::string(2*offset*SPACING, ' ') + oss.str();
      index_vec[level] = pos; // keeping track of last position
    }
    else {
      vec.push_back(std::string(2*pos*SPACING, ' ') + oss.str());
      index_vec.push_back(pos);
    }

    //L
    _fill_levels(tree -> left, level+1, 2*pos, index_vec, vec);

    //R
    _fill_levels(tree -> right, level+1, 2*pos+1, index_vec, vec);
  }
}





template <class K, class T>
void BinarySearchTree<K,T>::clean(){
}






template <class K, class T>
size_t BinarySearchTree<K,T>::size() {
  return _size_count;
}
