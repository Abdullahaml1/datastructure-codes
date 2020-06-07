#include <iostream>
#include "Stack.h"
#include <vector>

template<class T>
void print_fn(uint32_t i, T  element )
{
  std::cout << "stack["<< i << "]="<< element << std::endl;
}


int main()
{
  Stack<int> s;

  s.push(2);
  s.push(3);
  s.push(0);
  s.push(8);
  s.push(1);

  s.traverse(& print_fn);
  std::cout<< std::endl;

  int  x;
  if (!s.isEmpty())
    s.pop(x);
  std::cout << "pop(x), x = " << x << std::endl;
  s.traverse(& print_fn);
  std::cout<< std::endl;

  std::cout << "push(200)" << std::endl;
  s.push(200);
  s.traverse(& print_fn);
  std::cout << "stack size = " << s.stack_size() << std::endl;;
  std::cout<< std::endl;

  std::cout <<"cleaning stack .................." << std::endl;
  s.clean();
  std::cout << "trying to pop form an emapty stack" ;
  if (!s.isEmpty())
    s.pop(x);
  else
    std::cout<< " , but failed.";
  std::cout<< std::endl;
  std::cout << "stack size = " << s.stack_size() << std::endl;;
  std::cout << std::endl;

  std::cout << "push(200)" << std::endl;
  if (!s.isFull())
    s.push(200);
  s.traverse(& print_fn);
  std::cout<< std::endl;

  std::cout << "Inserting elements in the stack form 1 to 10" << std::endl;
  for (int i = 1; i <= 10; i++)
    s.push(i);
  s.traverse(& print_fn);
  std::cout<< std::endl;

  std::cout << "copying the stack" << std::endl;
  Stack<int> s_copy;
  s.copy(s_copy);
  s_copy.traverse(& print_fn);
  std::cout<< std::endl;


  Stack<int64_t> s_long;
  std::cout << "Stress testing with " << MAX_STACK << " element" << std::endl;
  for(int64_t i = 0;i < MAX_STACK; i++)
      s_long.push(i);
  s_long.clean();

  return 0;
}
