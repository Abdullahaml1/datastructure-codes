#ifndef LIST_H
#define LIST_H


#include <stdint.h>
#include <stdlib.h>
#include <iostream>

template <class T>
struct Node {
  T element;

  Node<T> * next;
  Node<T> * prev;
};



template <class T>
class List {

public:

  List();

  ~List();


  void initialize();

  int insert(int index, T element);


  int push_back(T element);


  int push_forward(T element);


  T get(int index);


  T retrieve(int index);


  size_t size();


  bool is_empty();


  bool is_full();


  int clean();

private:

  int _get_steps(int index, int lenght);

  Node<T> * _get_node(int index);

  int _insert_node(Node<T>* new_node, Node<T>* prev_node);

  Node<T> * _head_node_ptr;

  size_t _size_count;




};

#include "List.tpp"
#endif // LIST_H
