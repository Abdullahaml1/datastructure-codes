#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

template <typename K, class T>
struct Vertex {
  K key;
  T element;
  Vertex<k, T> * left, right;
}
#endif // BINARY_SEARCH_TREE_H
