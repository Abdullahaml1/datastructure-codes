#include "Stack.h"
#include <iostream>
#include <string>




template <class T>
void Stack<T>::initialize()
{
   stack_ptr = 0;
}



template <class T>
void Stack<T>::push(T  element)
{
    stack_arr[stack_ptr ++] = element;
}



template <class T>
void Stack<T>::pop(T & element)
{
    element = stack_arr[-- stack_ptr];
}



template <class T>
void Stack<T>::top(T & element)
{
    element = stack_arr[stack_ptr];
}


template <class T>
void Stack<T>::clean()
{
    stack_ptr = 0;
}



template < class T>
void Stack<T>::copy(Stack & s)
{
    T & element;
    for (uint32_t i=0; i < stack_ptr; i++)
    {
        element = stack_arr[i];
        s.push(element);

    }
}



template <class T>
uint32_t Stack<T>::stack_size()
{
    return stack_ptr;
}



template <class T> 
bool Stack<T>::isEmpty()
{
    return stack_ptr == 0;
}



template <class T>
bool Stack<T>::isFull() 
{
    return stack_ptr >= MAX_STACK;
}



template <class T>
void Stack<T>::traverse(void (*fn)(T & element))
{
    T & element;
    for (uint32_t i = 0; i < stack_ptr; i++)
    {
        element = stack_arr[i];
        fn(element); // or (*fn)(element)
    }
}
