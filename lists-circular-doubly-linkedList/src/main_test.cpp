#include <iostream>
#include "List.h"

int main() {

  List<int> l ;

  l.insert(0, 1);
  l.insert(0, -1);
  l.insert(2, 2);
  l.insert(2, 11);
  l.insert(-1, 3);
  l.push_back(4);
  l.push_forward(-2);
  l.insert(0, -3);

  l.clean();

  l.insert(0, 1);
  l.insert(1, 2);
  l.insert(-1, 3);
  l.push_back(4);
  l.push_forward(-1);

  std::cout << "retrieved=" << l.retrieve(3) <<std::endl;

  std::cout << l.get(-1) << std::endl;
  std::cout << "List size=" << l.size() << std::endl;
  return 0;
}
