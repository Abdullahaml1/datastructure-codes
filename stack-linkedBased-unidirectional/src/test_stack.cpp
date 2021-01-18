#include <stdint.h>
#include "Stack.h"
#include <iostream>


int main()
{
  Stack <int64_t> s;
  for(uint64_t i=0; i<= 128000000; i++)
    s.push(i);
  s.clean();

  return 0;
}
