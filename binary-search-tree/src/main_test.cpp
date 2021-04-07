#include "BinarySearchTree.h"


int comp(int key1, int key2) {
  return key1 - key2;
}
int main() {

  BinarySearchTree<int,int> bst(&comp);
  bst.insert(0,1);
  bst.insert(1,1);
  bst.insert(-1,1);
  bst.draw_tree();
  std::cout <<"size=" << bst.size() << std::endl;
  return 0;
}
