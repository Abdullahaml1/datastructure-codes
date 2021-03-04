#include <iostream>
#include "Stack.h"
#include "Types.h"
#include <vector>



void print_fn(size_t i, void * element_ptr,size_t element_size, Types element_type)
{
  switch(element_type)
    {
    case Types::Char:
      std::cout << "stack["<< i << "]="<< *( char*)element_ptr << ", of type: Char\n";
      break;

    case Types::Int:
      std::cout << "stack["<< i << "]="<< *( int*)element_ptr << ", of type: int\n";
      break;


    case Types::Float:
      std::cout << "stack["<< i << "]="<< *( float*)element_ptr << ", of type: Float\n";
      break;


    case Types::IntArr:
      const int * intarr = (int *)element_ptr;
      std::cout << "stack["<< i << "]=\n";
      for(size_t j=0; j < element_size/sizeof(int); j++)
        {
          std::cout << "      " << "IntArr[" << j << "]=" << intarr[j] << ",\n";
        }
      break;


    // case Types::Vector:
    //   std::cout << "stack["<< i << "]="<< *( String*)element_ptr << ", of type: String\n";
    //   break;

    }
}


template <class T>
int my_push(Stack & s, T  element, Types type)
{
  if (s.isFull())
    {
      return -1;
    }
  else
    {
      s.push((void *)& element, sizeof(T), type);
    }
  return 0;
}



template <class T>
int my_push_back(Stack & s, T  element, Types type)
{
  if (s.isFull())
    {
      return -1;
    }
  else
    {
      s.push_back((void *)& element, sizeof(T), type);
    }
  return 0;
}



template <class T>
int my_pop(Stack & s, T & element, Types type)
{
  if (s.isEmpty())
    {
      return -1;
    }
  else
    {
      void * ptr;
      size_t size;
      Types t_pop;

      if (s.topElementType == type )
        {
          s.pop(ptr,size, t_pop);
          element = *(T *)ptr;


          // free(ptr); // free the memory location of the pointer
          delete (T *)ptr;
        }
      else
        {
          return -2;
        }
    }
  return 0;
}



template <class T>
int my_pop_back(Stack & s, T & element, Types type)
{
  if (s.isEmpty())
    {
      return -1;
    }
  else
    {
      void * ptr;
      size_t size;
      Types t_last;

      if (s.lastElementType == type )
        {
          s.pop_back(ptr,size, t_last);
          element = *(T *)ptr;

          // free(ptr); // free the memory location of the pointer
          delete (T *)ptr;
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
  float float_push=0, float_pop=0;
  char char_push, char_pop;

  // pushing an int element
  x_push = 10;
  my_push(s, x_push, Types::Int);
  std::cout << "pushing int " << x_push << std::endl;
  s.traverse(&print_fn);
  std::cout << "size = " << s.size() << "\n\n";




  // pushing a float element
  float_push = 1.11;
  my_push(s, float_push, Types::Float);
  std::cout << "pushing float " << float_push << std::endl;
  s.traverse(&print_fn);
  std::cout << "size = " << s.size() << "\n\n";



  // pushing a float element
  float_push = 2.22;
  my_push(s, float_push, Types::Float);
  std::cout << "pushing float " << float_push << std::endl;
  s.traverse(&print_fn);
  std::cout << "size = " << s.size() << "\n\n";



  // popping back an int element
  my_pop_back(s, x_pop, Types::Int);
  std::cout << "pop back int " << x_pop << std::endl;
  s.traverse(&print_fn);
  std::cout << "size = " << s.size() << "\n\n";


  // pushing an array
  int intArr[5] ={1, 2, 3, 4, 5};
  s.push((void *)intArr, 5*sizeof(int), Types::IntArr);
  std::cout << "pushing an int array of size=" << sizeof(intArr) << std::endl;
  s.traverse(&print_fn);
  std::cout << "size = " << s.size() << "\n\n";




  // pushing back an int element
  x_push = 99;
  my_push_back(s, x_push, Types::Int);
  std::cout << "pushing back int " << x_push << std::endl;
  s.traverse(&print_fn);
  std::cout << "size = " << s.size() << "\n\n";


  std::cout << "Cleaning stack\n";
  s.clean();
  s.traverse(&print_fn);
  std::cout << "size = " << s.size() << "\n\n";




  // pushing an array
  int intArr1[5] ={50, 40, 30, 20, 10};
  s.push_back((void *)intArr1, 5*sizeof(int), Types::IntArr);
  std::cout << "pushing an int array of size=" << sizeof(intArr1) << std::endl;
  s.traverse(&print_fn);
  std::cout << "size = " << s.size() << "\n\n";





  // pushing a char element
  char_push = 'A';
  my_push(s, char_push, Types::Char);
  std::cout << "pushing char " << char_push << std::endl;
  s.traverse(&print_fn);
  std::cout << "size = " << s.size() << "\n\n";


  // copying stack
  Stack s_copy;
  std::cout << "copying stack....\n";
  s.copy(s_copy);
  s_copy.traverse(&print_fn);
  std::cout << "size = " << s_copy.size() << "\n\n";








  // // popping an int element
  // my_pop(s, x_pop, Types::Int);
  // std::cout << "pop int " << x_pop << std::endl;
  // s.traverse(&print_fn);
  // std::cout << "size = " << s.size() << "\n\n";


  std::cout << std::endl;
  std::string strA = "strA";
  void * v_ptr = & strA ;
  std::cout << *(std::string *) v_ptr << std::endl;

    return 0;
}
