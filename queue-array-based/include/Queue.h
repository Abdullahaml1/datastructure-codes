#ifndef _QUEUE_H_
#define _QUEUE_H_



#include <stdint.h>
#define MAX_QUEUE 1000



template <class T>
class Queue
{
public:
    Queue()
    {
        initialize();
    };


    ~Queue(){};

    /**
     * [the method for initializing of queue ]
     */
    void initialize();


    /**
     * [pushes an element at the end of the queue]
     */
    void append(T );


    /**
     * [pops an element form the queue]
     */
    void dequeue(T & value);
    void dequeue();


    /**
     * [hand the top element of queue without affecting int]
     */
    void top(T & value);


    /**
     * [return the queue to its initialized state ]
     */
    void clean();


    /**
     * [copies the queue to another one]
     */
    void copy(Queue & clonned);


    /*
     * [@return the queue size]
     */
    size_t size();


    /**
     * [@return True if the queue is emapty
     *          False othewise]
     */
    bool isEmpty();


    /**
     * [@return True is the queue is Full, and False otherwise]
     */
    bool isFull();


    /**
     * [a ways to acess all the elements in the queue. the input function will
     * be at this form:
     * void fun(uint32 index, int element)
     {
       // do some thing with index, and element
     }]
     */
  void traverse(void (*fn)(int index, T  element));



private:


    //--------------------------------------------------------------------------
    // the array that we used to save the queue
    //--------------------------------------------------------------------------
    T queue_arr[MAX_QUEUE];



    //--------------------------------------------------------------------------
    // the ptr points to the first emapty location in the array
    //--------------------------------------------------------------------------
  /**
   * | |b|c|d| | | | |
   *    ^     ^
   *  front   ^
   *         end
   */
  size_t queue_front_ptr;
  size_t queue_end_ptr;
  size_t queue_size;




};

#include <Queue.tpp>

#endif

