#define SPACING 8



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

  _empty_str = "[" + std::string(SPACING -2, '-') + "]";
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




template <class K, class T>
int BinarySearchTree<K,T>::search(K key, T &return_element) {

  Vertex<K,T>* itr = _root_ptr;

  while(itr != nullptr) {

    if (_comp(key, itr -> key) ==0) {
      return_element = itr -> element;
      return 0;
    }

    // bigger than -> walk right
    else if (_comp(key, itr -> key) > 0) {
      itr = itr -> right;
    }
    // equal -> walk left
    else {
      itr = itr -> left;
    }
  }

  return -1; // not found
}


template <class K, class T>
T BinarySearchTree<K,T>::get(K key) {

  Vertex<K,T> * parent = nullptr;

  // get the vertex and its parent
  Vertex<K,T> * itr = _root_ptr;

  while((itr != nullptr) && !(_comp(key, itr->key) ==0)) {
    parent = itr;
    // key > itr->key walk right
    if (_comp(key, itr->key) > 0) {
      itr = itr -> right;
    }
    // key < itr->key walk left
    else {
      itr = itr -> left;
    }
  }

  // not found raise exipession
  if (itr == nullptr) {
    return 0;
  }

  /*
   we have 4 cases:
  vertex without children (leaf)
       parent
         /\
      itr  null
      /\
   null null
  */
  T element;
  if ((itr->left == nullptr) && (itr->right == nullptr)) {
    if (itr == _root_ptr) { // the root
      _root_ptr = nullptr;
    }
    else if (parent->left == itr) {
      parent->left = nullptr;
    }
    // parent->right ==itr
    else {
      parent->right = nullptr;
    }
  }

  /*
  vertex with single left tree
       parent
         /\
      itr  tree
      /\
   tree null
  */
  else if((itr->left != nullptr) && (itr->right ==nullptr)) {
    if (itr == _root_ptr) { // the root
      _root_ptr = itr->left;
    }
    else if (parent->left == itr) {
      parent->left = itr->left;
    }
    // parent->right ==itr
    else {
      parent->right = itr->left;
    }
  }


  /*
  vertex with right  tree
       parent
         /\
      itr  tree
      /\
   null tree
  */
  else if((itr->left == nullptr) && (itr->right !=nullptr)) {

    if (itr == _root_ptr) { // parent == nullptr
      _root_ptr = itr->right;
    }
    else if (parent->left == itr) {
      parent->left = itr->right;
    }
    // parent->right ==itr
    else {
      parent->right = itr->right;
    }
  }


  /*
  vertex with tree in both branches
       parent
         /\
      itr  tree
      /\
   tree tree
  */
  else if((itr->left != nullptr) && (itr->right !=nullptr)) {

    // get the bigest vertex of the left tree
    Vertex<K,T> * mean_vertex = itr->left, * mean_patent=nullptr;
    while(mean_vertex->right != nullptr) {
      mean_patent = mean_vertex;
      mean_vertex = mean_vertex->right;
    }
    /*
     mean node will be like this
                itr
                /\
             tree tree
              /\
         tree    mean
          /\      /\
      tree tree tree null
    */
    //placing the parent of the mean_vertex
    if (mean_patent != nullptr) {
      mean_patent->right = mean_vertex->left;
    }

    //placing the mean_vertex in the position of the itr vertex
    if (mean_patent != nullptr){
      mean_vertex->left = itr->left;
    }
    mean_vertex->right = itr->right;

    // placing the parent vertex of the itr vertex(to be deleted vertex) to
    //mean_vertex
    if (itr == _root_ptr) { // parent == nullptr
      _root_ptr = mean_vertex;
    }
    else if (parent->left == itr) {
      parent->left = mean_vertex;
    }
    // parent->right ==itr
    else {
      parent->right = mean_vertex;
    }
  }

  element = itr -> element;
  free(itr);
  _size_count --;
  return element;
}


template <class K, class T>
T &BinarySearchTree<K,T>::at(K key) {

  Vertex<K,T>* itr = _root_ptr;

  while(itr != nullptr) {

    if (_comp(key, itr -> key) ==0) {
      return itr -> element;
    }

    // bigger than -> walk right
    else if (_comp(key, itr -> key) > 0) {
      itr = itr -> right;
    }
    // less than  -> walk left
    else {
      itr = itr -> left;
    }
  }
}




template <class K, class T>
std::string BinarySearchTree<K,T>::_draw_element(K key, T element) {
  std::ostringstream oss;
  int offset =0;

  oss << key << element;
  offset = (int)(SPACING - oss.str().size() - 4);
  oss.str("");

  oss << '[' << std::string(offset/2, ' ') << key << "=>"  << element;
  oss << std::string(offset/2 + offset%2,' ') << ']';

  return oss.str();
}




template<class K, class T>
void BinarySearchTree<K,T>::draw_tree() {

  std::vector<std::vector<std::string>> levels_vec;
  std::vector<int> index_vec;

  _fill_levels(_root_ptr, 0, 0, index_vec, levels_vec);



  std::vector<std::string> str_tree_vec (levels_vec.size());
  int level =(int)levels_vec.size()-1;
  int space =2;
  int offset=0;
  int element_size=SPACING;

  for(auto itr=levels_vec.rbegin(); itr != levels_vec.rend(); ++itr) {
    str_tree_vec[level] = std::string(offset, ' ');
    for (auto level_itr=(*itr).begin(); level_itr != (*itr).end(); level_itr++) {
      str_tree_vec[level] += *level_itr + std::string(space, ' ');
    }
    offset += (element_size + space)/2; // old space
    space = element_size + 2*space;

    level --;
  }

  // for(auto itr=levels_vec.begin(); itr != levels_vec.end(); itr++) {
  //   for (auto level_itr=(*itr).begin(); level_itr != (*itr).end(); level_itr++) {
  //     std::cout << *level_itr << ", ";
  //   }
  //   std::cout <<std::endl;
  // }

  for(auto itr = str_tree_vec.begin(); itr != str_tree_vec.end(); ++itr) {
    std::cout << *itr << std::endl << std::endl;
  }
}





template <class K, class T>
void BinarySearchTree<K,T>::_fill_levels(Vertex<K,T>* tree,
                                         int level, int pos,
                                         std::vector<int>&index_vec,
                                         std::vector<std::vector<std::string>> &vec) {
  // VLR: vertex, left, right
  if (tree != nullptr) {


    //V

    if(level < (int)vec.size()) {
      int offset=0;
      offset = pos - index_vec[level] -1;

      // empty entries in this level
      for(int i=0; i<offset; i++){
        vec[level].push_back(_empty_str);
      }
      vec[level].push_back(_draw_element(tree ->key, tree -> element));

      index_vec[level] = pos; // keeping track of last position
    }
    else {

      // empty entries in this level
      vec.push_back(std::vector<std::string>(pos, _empty_str));
      if (!vec.empty()) {
        vec[level].push_back(_draw_element(tree -> key, tree -> element));
      }
      else {
        vec.push_back(std::vector<std::string>(0, _empty_str));
      }

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
  _clean(_root_ptr);
  _root_ptr = nullptr;
  _size_count =0;

}




template <class K, class T>
void BinarySearchTree<K,T>::_clean(Vertex<K,T> * tree){
  if (tree != nullptr) {
    //left
    _clean(tree -> left);

    //vertex
    Vertex<K,T> *right = tree -> right;

    free(tree);

    //right
    _clean(right);
  }
}




template <class K, class T>
size_t BinarySearchTree<K,T>::size() {
  return _size_count;
}
