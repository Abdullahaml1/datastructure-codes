#include "BinarySearchTree.h"


int comp(int key1, int key2) {
  return key1 - key2;
}
int main() {

  BinarySearchTree<int,int> bst(&comp);
  bst.insert(10,1);
  bst.insert(15,1);
  bst.insert(5,1);


  bst.insert(3,1);
  bst.insert(7,1);
  bst.insert(50,1);
  bst.insert(14,1);


  bst.insert(100,1);

  // bst.insert(200,1);



  bst.draw_tree();
  std::cout <<"size=" << bst.size() << std::endl;
  return 0;
}
