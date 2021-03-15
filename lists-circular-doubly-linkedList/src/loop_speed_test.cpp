#include <iostream>

#include "List.h"
// #define ITERATOR
#define NORMAL

int main() {

  List<long int> l;
  long int max = 100000;
  long int count =0;

  for (long int i=0; i<max; i++) {
    l.push_back(i);
  }
  std::cout << "size=" <<l.size() << std::endl;

#ifdef ITERATOR
  std::cout << "Loop throw iterator test\n";
  count =0;
  for(List<long int>::iterator itr = l.begin(); itr !=l.end(); ++itr) {
    *itr -=1;
    count ++;
  }
  std::cout << "iterator loop finished with count=" << count << std::endl;
#endif



#ifdef NORMAL
  std::cout << "Loop throw normal way test\n";
  count =0;
  for(long int i=0; i<max; i++) {
    l[i] -=1;
    count ++;
  }
  std::cout << "Normal loop finished with count=" << count << std::endl;
#endif


  return 0;
}
