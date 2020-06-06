#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include <stdint.h>


template <typename T>
struct StackNode
{
public:

    T element;

    StackNode<T> * next;
    StackNode<T> * prev;
};



template <typename T>
class Stack
{
public:
    Stack()
    {
        initialize();
    };


    ~Stack(){};


    /**
     * [the size counter of the stack]
     */
    size_t size_count;


    /**
     * [the method for initailzing the stakc pointer]
     */
    void initialize();


    /**
     * [pushes an element at the top of the stack]
     */
    void push(T );


    /**
     * [pushes an element at the end of the stack]
     */
    void push_back(T);


    /**
     * [pops an element form the stack]
     */
    void pop(T & value);
    void pop();


    /**
     * [pops an element form the end of the stack]
     */
    void pop_back(T & value);
    void pop_back();



    /**
     * [hand the top element of stack without affecting int]
     */
    void top(T & value);


    /**
     * [hand the top element of the end of stack without affecting it]
     */
    void top_back(T & value);



    /**
     * [return the stack to its initialized state ]
     */
    void clean();


    /**
     * [copies the stack to another one]
     */
    void copy(Stack & clonned){};


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


    /**
     * [a ways to acess all the elements in the stack. the input function will
     * be at this form:
     * void fun(uint32 index, int element)
     {
       // do some thing with index, and element
     }]
     */
  void traverse(void (*fn)(size_t index, T  element));



private:


    //--------------------------------------------------------------------------
    // points to the first node
    //--------------------------------------------------------------------------
    StackNode<T> * stack_ptr;


    //--------------------------------------------------------------------------
    // points the last element of the stack
    //--------------------------------------------------------------------------
    StackNode<T> * stack_last_ptr;



};

// accounting for the template linker issue
#include "Stack.tpp"


#endif

