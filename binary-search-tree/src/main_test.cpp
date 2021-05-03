#include "BinarySearchTree.h"


int comp(int key1, int key2) {
  return key1 - key2;
}
int main() {

  BinarySearchTree<int,int> bst(&comp);
  bst.insert(10,9);
  bst.insert(15,1);
  bst.insert(5,1);


  bst.insert(3,1);
  bst.insert(7,8);
  bst.insert(50,1);
  bst.insert(14,1);


  bst.insert(100,1);
  bst.insert(1,1);

  // bst.insert(200,1);


  std::cout << "at key 7 =" << bst.at(7) << std:: endl;

  bst.draw_tree();
  std::cout <<"size=" << bst.size() << std::endl;



  int key = 14;
  std::cout << "get key=" << key << "->" << bst.get(key) << std::endl;
  bst.draw_tree();


  key = 10;
  std::cout << "get key=" << key << "->" << bst.get(key) << std::endl;
  bst.draw_tree();


  key = 50;
  std::cout << "get key=" << key << "->" << bst.get(key) << std::endl;
  bst.draw_tree();


  key = 7;
  std::cout << "get key=" << key << "->" << bst.get(key) << std::endl;
  bst.draw_tree();


  key = 15;
  std::cout << "get key=" << key << "->" << bst.get(key) << std::endl;
  bst.draw_tree();

  key = 100;
  std::cout << "get key=" << key << "->" << bst.get(key) << std::endl;
  bst.draw_tree();


  key = 5;
  std::cout << "get key=" << key << "->" << bst.get(key) << std::endl;
  bst.draw_tree();


  key = 3;
  std::cout << "get key=" << key << "->" << bst.get(key) << std::endl;
  bst.draw_tree();


  key = 1;
  std::cout << "get key=" << key << "->" << bst.get(key) << std::endl;
  bst.draw_tree();

  std::cout <<"size=" << bst.size() << std::endl;
  // std::cout << "Tree cleaned\n";
  // bst.clean();
  // std::cout <<"size=" << bst.size() << std::endl;

  bst.insert(88, 0);
  bst.insert(99, 5);
  bst.draw_tree();
  // std::cout <<"size=" << bst.size() << std::endl;

  return 0;
}
