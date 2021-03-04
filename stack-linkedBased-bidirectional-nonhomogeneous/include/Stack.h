#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include <stdint.h>
#include "Types.h"


struct StackNode
{
public:

  void * element_ptr;
  Types type;   // the type of the element;
  size_t size;  // the size of the element in bytes

  StackNode * next;
  StackNode * prev;

};



/**
 * [This stack supports nonhomogeneous data defined in Types.h on one condition:
 * (the data should be continous space in memory)]
 * ex: int, float, double, char, arrays, structs, classed (classes should not
 * use dynamic memory allocation ex: we can not use std::string, or std::vector)
 * you can use any type in stack-linkedBased with the template definition
 */
class Stack
{
public:
  Stack()
  {
    initialize();
  };


  ~Stack();


  Types topElementType;
  Types lastElementType;


  /**
   * [the method for initailzing the stakc pointer]
   */
  void initialize();


  /**
   * [pushes an element at the top of the stack]
   * @param element_ptr [A void pointer to the desired element ]
   * @param element_size [the size of  element in bytes ]
   * @param element_type [the type of the element dfined in Types.h]
   */
  void push(void * element_ptr, size_t element_size, Types element_type);


  /**
   * [pushes an element at the top of the stack]
   * @param element_ptr [A void pointer to the desired element ]
   * @param element_size [the size of  element in bytes ]
   * @param element_type [the type of the element dfined in Types.h]
   */
  void push_back(void * element_ptr, size_t element_size, Types element_type);



  /**
   * [pops an element of the stack]
   * @param element_ptr [A void pointer to the desired element ]
   * @param element_size [the size of  element in bytes ]
   * @param element_type [the type of the element dfined in Types.h]
   */
  void pop(void *& element_ptr, size_t & element_size, Types & element_type);

  /**
   * [pops an element of the stack]
   */
  void pop();

  /**
   * [pops an element from the back of the stack]
   * @param element_ptr [A void pointer to the desired element ]
   * @param element_size [the size of  element in bytes ]
   * @param element_type [the type of the element dfined in Types.h]
   */
  void pop_back(void *& element_ptr, size_t & element_size, Types & element_type);

  /**
   * [pops an element from the back of the stack]
   */
  void pop_back();




  /**
   * [hand the top element of stack without affecting it]
   * @param element_ptr [A void pointer to the desired element ]
   * @param element_size [the size of  element in bytes ]
   * @param element_type [the type of the element dfined in Types.h]
   */
  void top(void * &element_ptr,size_t & element_size, Types & element_type);



  /**
   * [hand the last element of stack without affecting it]
   * @param element_ptr [A void pointer to the desired element ]
   * @param element_size [the size of  element in bytes ]
   * @param element_type [the type of the element dfined in Types.h]
   */
  void last(void * &element_ptr,size_t & element_size, Types & element_type);





  /**
   * [cleans the stack]
   */
  void clean();


  /**
   * [copies the stack to another one]
   */
  void copy(Stack & s_copy);


  /**
   * @return [the number of elements in the stack]
   */
  size_t size();


  /**
   * [@return True if the stack is emapty
   *          False othewise]
   */
  bool isEmpty();



  /**
   * [@return True is the stack is Full, and False otherwise]
   */
  bool isFull();


  /**
   * [a ways to acess all the elements in the stack. the input function will
   * be at this form:
   * void fun(size_t index, void * element_ptr, size_t element_size, Types element_type)
   {
   // do some thing with index, and element
   }]

   * @param (*fn) a pointer to function with those parameters:
   *             @param element_ptr [A void pointer to the desired element ]
   *             @param element_size [the size of  element in bytes ]
   *             @param element_type [the type of the element dfined in Types.h]

  */
  void traverse(void (*fn)(size_t index, void * element_ptr, size_t element_size, Types element_type));



private:


  //--------------------------------------------------------------------------
  // points to the first node
  //--------------------------------------------------------------------------
  StackNode * stack_ptr;


  //--------------------------------------------------------------------------
  // points the last element of the stack
  //--------------------------------------------------------------------------
  StackNode * stack_last_ptr;



  /**
   * [the size counter of the stack]
   */
  size_t size_count;



};

#endif

