#include <iostream>
#include "Stack.h"
#include "Types.h"
#include <vector>

template<typename T>
void print_fn(size_t i, T  element )
{
  std::cout << "stack["<< i << "]="<< element << std::endl;
}


int push_int(Stack & s, int  element)
{
  if (s.isFull())
    {
      return -1;
    }
  else
    {
      s.push((void *)& element, Types::Int, sizeof(int));
    }
  return 0;
}





int pop_int(Stack & s, int & element)
{
  if (s.isEmpty())
    {
      return -1;
    }
  else
    {
      Types t;
      void * ptr;

      if (s.topElementType == Int )
        {
          s.pop(ptr, t);
          element = *(int *)ptr;
          free(ptr);
          std::cout << element << " in funciton\n";
        }
      else
        {
          return -2;
        }
    }
  return 0;
}





int main()
{
  Stack s;
  int x_push=0, x_pop=0;

  // pushing an int element
  x_push = 10;
  push_int(s, x_push);
  std::cout << "pushing int " << x_push << std::endl;
  std::cout << "size = " << s.size() << "\n\n";


  // popping an int element
  pop_int(s, x_pop);
  std::cout << "pop int " << x_pop << std::endl;
  std::cout << "size = " << s.size() << "\n\n";






    return 0;
}
