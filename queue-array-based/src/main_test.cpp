#include <iostream>
#include "Queue.h"
#include <vector>

template<class T>
void print_fn(int i, T  element )
{
  std::cout << "queue["<< i << "]="<< element << std::endl;
}


int main()
{

  Queue<int> q;

  q.append(2);
  q.append(3);
  q.append(0);
  q.append(8);
  q.append(1);


  q.traverse(& print_fn);
  std::cout<< std::endl;

  // dequeueing element
  int  x;
  if (!q.isEmpty())
    q.dequeue(x);
  std::cout << "dequeue(x), x = " << x << std::endl;
  q.traverse(& print_fn);
  std::cout<< std::endl;


  // appending element
  x = 200;
    std::cout << "append(" << x << ")" << std::endl;
  q.append(x);
  q.traverse(& print_fn);
  std::cout << "queue size = " << q.size() << std::endl;;
  std::cout<< std::endl;



  // dequeueing element
  if (!q.isEmpty())
    q.dequeue(x);
  std::cout << "dequeue(x), x = " << x << std::endl;
  q.traverse(& print_fn);
  std::cout<< std::endl;



  // appending element
  x = 800;
  std::cout << "append(" << x << ")" << std::endl;
  q.append(x);
  q.traverse(& print_fn);
  std::cout << "queue size = " << q.size() << std::endl;;
  std::cout<< std::endl;



  std::cout <<"cleaning queue .................." << std::endl;
  q.clean();
  std::cout << "trying to pop form an emapty queue" ;
  if (!q.isEmpty())
    q.dequeue(x);
  else
    std::cout<< " , but failed.";
  std::cout<< std::endl;
  std::cout << "queue size = " << q.size() << std::endl;;
  std::cout << std::endl;



  std::cout << "push(200)" << std::endl;
  if (!q.isFull())
    q.append(200);
  q.traverse(& print_fn);
  std::cout<< std::endl;

  std::cout << "Inserting elements in the queue form 1 to 10" << std::endl;
  for (int i = 1; i <= 10; i++)
    q.append(i);
  q.traverse(& print_fn);
  std::cout<< std::endl;

  std::cout << "copying the queue" << std::endl;
  Queue<int> q_copy;
  q.copy(q_copy);
  q_copy.traverse(& print_fn);
  std::cout<< std::endl;



  return 0;
}
