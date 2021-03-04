#include <iostream>
#include "List.h"

int main() {

  List<int> l ;

  l.insert(0, 1);
  l.insert(0, -1);
  l.insert(2, 2);
  l.insert(2, 11);
  l.insert(-1, 3);
  // l.insert(0, -2);

  std::cout << l.get(0) << std::endl;
  return 0;
}
