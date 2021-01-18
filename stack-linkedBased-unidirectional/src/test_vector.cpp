#include <stdint.h>
#include <vector>
#include <iostream>


int main()
{
  std::vector <int64_t> vec;
  for(uint64_t i=0; i<= 128000000; i++)
    vec.push_back(i);
  vec.clear();

  return 0;
}
