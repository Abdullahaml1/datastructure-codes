#ifndef LIST_H
#define LIST_H


#include <stdint.h>
#include <stdlib.h>
#include <iterator>
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

  //references for iterators:
  //https://www.cplusplus.com/reference/iterator/iterator/
  //https://en.cppreference.com/w/cpp/language/operators
  class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {

    Node<T> * node_ptr;

  public:
    iterator(Node<T> * _node_ptr) :node_ptr(_node_ptr){};

    iterator(const iterator& itr): node_ptr(itr.node_ptr){};

    ~iterator(){};

    T& operator*() {return node_ptr -> element;};

    // prefix increment
    //prefix increment means increment then return (we will return the
    // incremented value);
    iterator& operator++() {
      node_ptr = node_ptr-> next;
      return *this;
    };


    //postfix increment
    //postfix increment means return then increment (we will the old value);
    //int argument is ignored
    iterator operator++(int) {
      iterator old_itr(*this); // old iterator
      operator++(); // node_ptr -> next (increment our iterator)
      return old_itr;
    };

    // prefix decrement
    //prefix decrement means decrement then return (we will return the
    // decremented value);
    iterator& operator--() {
      node_ptr = node_ptr-> prev;
      return *this;
    };

    inline bool operator==(const iterator & itr) const {
      return itr.node_ptr == node_ptr;
    };


    inline bool operator!=(const iterator & itr) const {
      return itr.node_ptr != node_ptr;
    };

    //ex: itr+=3
    iterator& operator+=(int count) {
      if (count >=0) {
        for(int i=0; i<count; i++) {
          node_ptr = node_ptr -> next;
        }
      }
      else {
        for(int i=count; i<0; i++) {
          node_ptr = node_ptr -> prev;
        }
      }
      return *this;
    };


    //ex: itr+3
    friend iterator operator+(iterator lhs_itr, int rhs_count) {
      lhs_itr += rhs_count; // lhs_itr.operator+=(rhs_count)
      return lhs_itr;
    };


    //ex: itr-=3
    iterator& operator-=(int count) {
      return operator+=(-count);
    };


    //ex: itr-3
    friend iterator operator-(iterator lhs_itr, int rhs_count) {
      return operator+(lhs_itr, -rhs_count);
    };




    //postfix decrement
    //postfix decrement means return then decrement (we will the old value);
    //int argument is ignored
    iterator operator--(int) {
      iterator old_itr(*this); // old iterator
      operator--(); // node_ptr -> next (decrement our iterator)
      return old_itr;
    };



  };


  List();

  ~List();


  void initialize();

  /**
   * [insert element in the list of a given index]
   * @param index [-(size() +1) >= index <= size()
   *               -1 is last element.]
   * @return [0 if the element is inserted successfully in the list
   *           otherwise will return error code ]
   * Ex: l.insert(-3, element) the element will be in position 3 from the
   * last element
   */
  int insert(int index, T element);

  /**
   * [insert element at the end of the list]
   * @return [0 if the element is inserted successfully in the list
   *           otherwise will return error code ]
   * Ex: push_back(element) is the same as insert(-1, element)
   * last element
   */
  int push_back(T element);


  /**
   * [insert element at the start of the list]
   * @return [0 if the element is inserted successfully in the list
   *           otherwise will return error code ]
   * Ex: push_forward(element) is the same as insert(0, element)
   * last element
   */
  int push_forward(T element);


  /**
   * [return the element from the list]
   * @param index [-size()  >= index <= size() -1
   *               -1 is last element.]
   */
  T get(int index);


  /**
   * [edit the element at the given index and the return the old element]
   * @param index [-size()  >= index <= size() -1
   *               -1 is last element.]
   * @return [old element]
   */
  T edit(int index, T nex_element);


  /**
   * [return a reference to the element at the given index
   * Ex:
   * l[3] = 800; // will edit the value of element of index 3 to 800
   * int x = l[3]; // will copy element at index 3 to x
   * x = 99 // will no affect the element at index 3
   * int& y= l[3]; //if we change y, l[3] will also change]
   * @param index [-size()  >= index <= size() -1
   *               -1 is last element.]
   * @return [a reference to the element at thet index]
   */
  T& operator[](int index) ;


  /**
   * [delete the element at the given index and return the element value]
   * @param index [-size()  >= index <= size() -1
   *               -1 is last element.]
   * @return [the element at the given index]
   */
  T retrieve(int index);


  /**
   * @return [the size of the list]
   */
  size_t size();


  /**
   * @return [true if the list is empty, false otherwise]
   */
  bool is_empty();


  bool is_full();


  /**
   * [cleans the list]
   * @return [0 the cleaning process finished successfully,
   *          error code otherwise]
   */
  int clean();

  void debug_print_list();


  /**
   * @return [the begin iterator of the list]
   */
  iterator begin() {
      return iterator(_head_node_ptr);
  };


  /**
   * @return [the end iterator of the list]
   */
  iterator end(){
      return iterator(_head_node_ptr -> prev); // last node
  };

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
