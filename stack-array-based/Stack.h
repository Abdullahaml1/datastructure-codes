#ifndef _STACK_H_
#define _STACK_H_



#include <stdint.h>
#define MAX_STACK 1000



template <class T>
class Stack
{
public:
    Stack()
    {
        initialize();
    };


    ~Stack(){};

    /**
     * [the method for initailzing the stakc pointer]
     */
    void initialize();


    /**
     * [pushes an element at the top of the stack]
     */
    void push(T );


    /**
     * [pops an element form the stack]
     */
    void pop(T & value);
    void pop();


    /**
     * [hand the top element of stack without affecting int]
     */
    void top(T & value);


    /**
     * [return the stack to its initialized state ]
     */
    void clean();


    /**
     * [copies the stack to another one]
     */
    void copy(Stack & clonned);


    /*
     * [@return the stack size]
     */
    uint32_t stack_size();


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
     * void fun(uint32 index, int element)
     {
       // do some thing with index, and element
     }]
     */
  void traverse(void (*fn)(uint32_t index, T  element));



private:


    //--------------------------------------------------------------------------
    // the array that we used to save the stack
    //--------------------------------------------------------------------------
    T stack_arr[MAX_STACK];



    //--------------------------------------------------------------------------
    // the ptr points to the first emapty location in the array
    //--------------------------------------------------------------------------
    uint32_t stack_ptr;




};


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
void Stack<T>::pop()
{
  -- stack_ptr;
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
    T  element;
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
void Stack<T>::traverse(void (*fn)(uint32_t ,T ) )
{
    T element;
    for (int i = stack_ptr - 1; i >= 0; i--)
    {
        element = stack_arr[i];
        fn(i, element); // or (*fn)(element)
    }
}

#endif

