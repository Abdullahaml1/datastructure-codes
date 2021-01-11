#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include <stdint.h>
#include "Types.h"


struct StackNode
{
public:

  void * element_ptr;

  StackNode * next;
  StackNode * prev;

  Types type;   // the type of the element;
  size_t size;  // the size of the element in bytes
};



class Stack
{
public:
  Stack()
  {
    initialize();
  };


  ~Stack(){};


  Types topElementType;
  Types lastElementType;


  /**
   * [the method for initailzing the stakc pointer]
   */
  void initialize();


  /**
   * [pushes an element at the top of the stack]
   * @param element [the element to be pushed to the stack]
   * @param element_size [the size of  element to be pushed to the stack]
   */
  void push(void * element_ptr,Types element_type, size_t element_size);




  void pop(void *& element_ptr, Types & element_type);
  void pop();


  // /**
  //  * [pops an element form the end of the stack]
  //  */
  // void pop_back(T & value);
  // void pop_back();



  // /**
  //  * [hand the top element of stack without affecting it]
  //  */
  // void top(T & value);


  // /**
  //  * [hand the top element of the end of stack without affecting it]
  //  */
  // void top_back(T & value);



  /**
   * [return the stack to its initialized state ]
   */
  void clean();


  // /**
  //  * [copies the stack to another one]
  //  */
  // void copy(Stack & clonned);


  /*
   * [@return the stack size]
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


  // /**
  //  * [a ways to acess all the elements in the stack. the input function will
  //  * be at this form:
  //  * void fun(uint32 index, int element)
  //  {
  //  // do some thing with index, and element
  //  }]
  // */
  // void traverse(void (*fn)(size_t index, T  element));


  // /**
  //  * [a ways to acess all the elements in the stack wih reverse order
  //  * (acessing the last element of the stack first)].
  //  * @param [the input function will be at this form:
  //  *
  //  * void fun(uint32 index, int element)
  //  {
  //  // do some thing with index, and element
  //  }]
  // */
  // void traverse_backward(void (*fn)(size_t index, T  element));




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

// accounting for the template linker issue
#include "Stack.tpp"


#endif

