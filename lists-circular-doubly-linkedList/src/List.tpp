// #define DEBUG_INSERT_NODE



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

#ifdef DEBUG_INSERT_NODE
  std::cout << "The node we got before insertion\n";
  std::cout << "node -> elemenet = " << prev_node -> element << std::endl;
  std::cout << "node -> next = " << prev_node -> next -> element << std::endl;
  std::cout << "node -> prev = " << prev_node -> prev -> element << std::endl << std::endl;
#endif

  // attaching the two ends of the new node
  new_node -> prev = prev_node;
  new_node -> next = prev_node -> next;

#ifdef DEBUG_INSERT_NODE
  std::cout << "Our new node\n";
  std::cout << "node -> elemenet = " << new_node -> element << std::endl;
  std::cout << "node -> next = " << new_node -> next -> element << std::endl;
  std::cout << "node -> prev = " << new_node -> prev -> element << std::endl << std::endl;
#endif


  // pointing the next node to the new node
  prev_node -> next -> prev = new_node;


  // pointing the previous node to the new node
  prev_node -> next = new_node;

#ifdef DEBUG_INSERT_NODE
  std::cout << "The node we got after insertion\n";
  std::cout << "node -> elemenet = " << prev_node -> element << std::endl;
  std::cout << "node -> next = " << prev_node -> next -> element << std::endl;
  std::cout << "node -> prev = " << prev_node -> prev -> element << std::endl << std::endl;
#endif

  return 0;
}





template <class T>
Node<T> * List<T>::_get_node_with_tail(int index) {

  int num_steps =0;
  Node<T> * node_itrator = _head_node_ptr;

  // get the number of steps
  num_steps = _get_steps(index, (int)_size_count+1);


  //if steps +ve walk in the next direction
  if (num_steps >= 0) {

    for (int i=0; i<num_steps; i++) {
      node_itrator = node_itrator -> next;
    }
  }

  //if steps -ve walk in the prev direction but consider the empty node at the end
  else {
    for (int i=0; i>num_steps; i--) {
      node_itrator = node_itrator -> prev;
    }
  }

  return node_itrator;
}





template <class T>
Node<T> * List<T>::_get_node_without_tail(int index) {

  int num_steps =0;
  Node<T> * node_itrator = _head_node_ptr;

  if (_head_node_ptr == nullptr) {
    return nullptr;
  }

  // get the number of steps
  num_steps = _get_steps(index, (int)_size_count);

  //if steps +ve walk in the next direction
  if (num_steps >= 0) {

    for (int i=0; i<num_steps; i++) {
      node_itrator = node_itrator -> next;
    }
  }

  //if steps -ve walk in the prev direction but consider the empty node at the end
  else {
    node_itrator = node_itrator -> prev; // bypassing the tail node

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
  if (_head_node_ptr == nullptr && (index ==0 || index==-1)) {

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
  else if (index ==0 || index==-(int)(_size_count +1)) {

    _insert_node(new_node, _head_node_ptr -> prev);
    _head_node_ptr = new_node;

    _size_count ++;

    return 0; //sucess
  }


  // getting previous node of our desired index
  Node<T> * prev_node = _get_node_with_tail(index -1);

  _insert_node(new_node, prev_node);
  _size_count ++;

  return 0; //sucess
}




template <class T>
T List<T>::get(int index) {

  Node<T> * node_ptr = _get_node_without_tail(index);

  if (node_ptr) {
    return node_ptr -> element;
  }

  return 0;
}



template <class T>
T List<T>::edit(int index, T new_element) {
  Node<T> * node_ptr = _get_node_without_tail(index);
  T old_element;

  if (node_ptr == nullptr) {
    return 0;
  }

  old_element = node_ptr -> element;
  node_ptr -> element = new_element;

  return old_element;
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
T List<T>::retrieve(int index) {

  Node<T> * del_node = _get_node_without_tail(index); // the node to be deleted
  T element = del_node -> element;

  if (_size_count == 1 && (index ==0 || index ==-1)) {
    clean();
  }
  else {

    // attaching the previous node of the deleted node to
    // the next node of the deleted node
    del_node -> prev -> next = del_node -> next;

    // attaching the next node of the deleted node to
    // the previous node of the deleted node
    del_node -> next -> prev = del_node -> prev;


    if (index ==0 || index == -(int)_size_count) {
      _head_node_ptr = del_node -> next;
    }

    // deleting the node
    free(del_node);

      _size_count --;
  }


  return element;
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






template <class T>
void List<T>::debug_print_list() {

  Node<T> * node_itrator = _head_node_ptr;
  if (!_head_node_ptr)
    return;

  for (int i=0; i <= (int)_size_count; i++) {
    std::cout << "node -> elemenet = " << node_itrator -> element << std::endl;
    std::cout << "node -> next = " << node_itrator -> next -> element << std::endl;
    std::cout << "node -> prev = " << node_itrator -> prev -> element << std::endl << std::endl;
    node_itrator = node_itrator -> next;
  }
}

