template <class T>
List<T>::List() {
  initialize();
}


template <class T>
List<T>::~List() {
  clean();
}



template <class T>
void List<T>::initialize() {
  _head_node_ptr = nullptr;
  _size_count = 0;
}






template <class T>
int List<T>::_get_steps(int index, int lenght) {

  if (index > 0) {

    // i=1, lenght=10  1(next direction)
    if (index <= lenght/2) {
      return index;
    }
    // i=9, lenght=10 -1(prev direction)
    else {
      return -lenght + index;
    }
  }

  else if (index  < 0) {
    // i=-1, lenght=10  -1(prev direction)
    if (index >= -lenght/2) {
      return index;
    }
    // i=-9, lenght=10  1(next direction)
    else {
      return lenght + index;
    }
  }

    return 0;
}




template <class T>
int List<T>::_insert_node(Node<T>* new_node, Node<T>* prev_node){

  std::cout << "The node we got before insertion\n";
  std::cout << "node -> elemenet = " << prev_node -> element << std::endl;
  std::cout << "node -> next = " << prev_node -> next -> element << std::endl;
  std::cout << "node -> prev = " << prev_node -> prev -> element << std::endl << std::endl;


  // attaching the two ends of the new node
  new_node -> prev = prev_node;
  new_node -> next = prev_node -> next;
  std::cout << "Our new node\n";
  std::cout << "node -> elemenet = " << new_node -> element << std::endl;
  std::cout << "node -> next = " << new_node -> next -> element << std::endl;
  std::cout << "node -> prev = " << new_node -> prev -> element << std::endl << std::endl;


  // pointing the next node to the new node
  prev_node -> next -> prev = new_node;


  // pointing the previous node to the new node
  prev_node -> next = new_node;
  std::cout << "The node we got after insertion\n";
  std::cout << "node -> elemenet = " << prev_node -> element << std::endl;
  std::cout << "node -> next = " << prev_node -> next -> element << std::endl;
  std::cout << "node -> prev = " << prev_node -> prev -> element << std::endl << std::endl;

  return 0;
}


template <class T>
Node<T> * List<T>::_get_node(int index) {

  int num_steps =0;
  Node<T> * node_itrator = nullptr;

  // get the number of steps
  num_steps = _get_steps(index, (int)_size_count);

  // debug ---------------------------------------------------------------------
  std::cout << "num_steps=" << num_steps << std::endl;


  node_itrator = _head_node_ptr;

  for (int i=0; i <= (int)_size_count; i++) {
  std::cout << "node -> elemenet = " << node_itrator -> element << std::endl;
  std::cout << "node -> next = " << node_itrator -> next -> element << std::endl;
  std::cout << "node -> prev = " << node_itrator -> prev -> element << std::endl << std::endl;
  node_itrator = node_itrator -> next;
  }
  // debug end >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


  node_itrator = _head_node_ptr;
  //if steps +ve walk in the next direction
  if (num_steps >= 0) {

    for (int i=0; i<num_steps; i++) {
      node_itrator = node_itrator -> next;
    }
  }

  //if steps -ve walk in the prev direction but consider the empty node at the end
  else {
    // node_itrator = node_itrator -> prev; // bypassing the tail node

    for (int i=0; i>num_steps; i--) {
      node_itrator = node_itrator -> prev;
    }
  }

  return node_itrator;
}



template <class T>
int List<T>::insert(int index, T element) {



  // Allocate the new node and storing element
  Node<T> * new_node = (Node<T> *)malloc(sizeof(Node<T>));
  if (new_node == nullptr) {
    // no space for the new node quit the method
    return -1;
  }
  new_node -> element = element;


  // first insertion
  if (_head_node_ptr == nullptr && index ==0) {

    // Allocate the tail node
    Node<T> * tail_node = (Node<T> *)malloc(sizeof(Node<T>));
    if (tail_node == nullptr) {
      // no space for the new node quit the method
      return -1;
    }

    // debug >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    tail_node -> element = -99;

    // attaching the head node
    _head_node_ptr = new_node;
    _head_node_ptr -> next = tail_node;
    _head_node_ptr -> prev = tail_node;

    // attaching the tail node
    tail_node -> next = _head_node_ptr;
    tail_node -> prev = _head_node_ptr;

    _size_count ++;

    return 0; //sucess
  }
  // for the 0 index
  else if (index ==0) {

    _insert_node(new_node, _head_node_ptr -> prev);
    _head_node_ptr = new_node;

    _size_count ++;

    return 0; //sucess
  }


  // getting previous node of our desired index
  Node<T> * prev_node = _get_node(index -1);

  _insert_node(new_node, prev_node);
  _size_count ++;

  return 0; //sucess

}




template <class T>
T List<T>::get(int index) {

  Node<T> * node_ptr = _get_node(index);

  if (node_ptr) {
    return node_ptr -> element;
  }

  return 0;
}


template <class T>
int List<T>::push_back(T element) {
  return insert(-1, element);
}





template <class T>
int List<T>::push_forward(T element) {
  return insert(0, element);
}



template <class T>
size_t List<T>::size() {
  return _size_count;
}



template <class T>
bool List<T>::is_empty() {
  return _head_node_ptr == nullptr;
}



template <class T>
bool List<T>::is_full() {
  return false;
}



template <class T>
int List<T>::clean() {
  Node<T> * node_free = nullptr;
  Node<T> * node_itrator = _head_node_ptr;

  for (int i; i<= (int)_size_count; i++) {

    node_free = node_itrator;

    node_itrator = node_itrator -> next;

    free(node_free);
  }

  _head_node_ptr = nullptr;
  _size_count =0;

  return 0;
}
