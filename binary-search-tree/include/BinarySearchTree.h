#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip> // for std::setw(n)
#include <string>
#include <cmath>

template <class K, class T>
struct Vertex {
  K key;
  T element;
  Vertex<K,T> * left;
  Vertex<K,T> * right;
};


template <class K, class T>
class BinarySearchTree {

public:

  BinarySearchTree();
  BinarySearchTree(int (*comp)(K key1, K key2));

  void initialize();

  ~BinarySearchTree();

  int insert(K key, T element);

  T search(K key);

  T &at(K key);

  size_t size();

  bool is_empty();

  void clean();

  int blance_tree();

  void draw_tree();

private:

  Vertex<K,T> * _root_ptr;

  size_t _size_count;

  int (*_comp)(K, K);

  void _fill_levels(Vertex<K,T>* tree,
                   int level, int pos,
                   std::vector<int>&index_vec,
                    std::vector<std::vector<std::string>> &vec);

  std::string _draw_element(K key, T element);

  std::string _dray_empty_element();
};



#include "BinarySearchTree.tpp"
#endif // BINARY_SEARCH_TREE_H
