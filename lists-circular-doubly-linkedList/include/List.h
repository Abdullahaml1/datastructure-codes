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

  /**
   * [getting the minimum steps of wether to loop list forward
   * (in next direction), or loop backwards (in prev direction)]
   *
   * @param index [int value. listSize >= index >= -(listSize +1)
   * ((Note: we take in account the tail node so  otherwise it will be:
   * listSize > index >= -listSize ))]
   *
   * @param lenght [the size of the list excluding the tailNode]
   *
   * @return [-lenght/2 > steps >= lenght/2, if steps +ve (in next direction),
   * if -ve (in prev direction)]
   */
  int _get_steps(int index, int lenght);


  /**
   * [getting a pointer to the node by the index]
   *
   * @param index [int value. listSize >= index >= -(listSize +1)
   * ((Note: we take in account the tail node, as the size of the list is not
   * counted  otherwise it will be: listSize > index >= -listSize ))]
   *
   * @return [pointer to the desired node,
   *          nullptr if the node does not exist]
   */
  Node<T> * _get_node_with_tail(int index);


  /**
   * [getting a pointer to the node by the index]
   *
   * @param index [int value. listSize > index >= -listSize
   *
   * @return [pointer to the desired node,
   *          nullptr if the node does not exist]
   */
  Node<T> * _get_node_without_tail(int index);

  /**
   * [insert new node between prev node, and next, node]
   * @param new_node [pointer to the new node between prev and next node]
   * @param prev_node [the prev node of the new node index.
   * Ex: if new_node_index = 4, the prev_node_index = 3]
   *
   * @return [0 if sucess, -1 if -1 error occurred ]
   */
  int _insert_node(Node<T>* new_node, Node<T>* prev_node);

  Node<T> * _head_node_ptr;

  size_t _size_count;




};

#include "List.tpp"
#endif // LIST_H
