#include "Queue.h"
#include <iostream>
#include <string>




template <class T>
void Queue<T>::initialize()
{
  queue_front_ptr =0;
  queue_end_ptr =0;
  queue_size =0;
}



template <class T>
void Queue<T>::append(T  element)
{
  queue_arr[queue_end_ptr] = element;
  queue_end_ptr ++;
  queue_end_ptr %= MAX_QUEUE; // circular appending see README

  queue_size ++;
}



template <class T>
void Queue<T>::dequeue(T & element)
{
    element = queue_arr[queue_front_ptr];

    queue_front_ptr ++;
    queue_front_ptr %= MAX_QUEUE; //circular dequeueing see README


    queue_size --;
}



template <class T>
void Queue<T>::top(T & element)
{
    element = queue_arr[queue_front_ptr];
}


template <class T>
void Queue<T>::clean()
{
  initialize();
}



template < class T>
void Queue<T>::copy(Queue & q)
{
    T element;
    size_t i= queue_front_ptr;
    for (uint32_t c = 0; c < queue_size; c++)
      {
        element = queue_arr[i];
        q.append(element);

        i = (i+1) % MAX_QUEUE;
      }

}



template <class T>
size_t Queue<T>::size()
{
  return queue_size;
}



template <class T>
bool Queue<T>::isEmpty()
{
    return queue_size== 0;
}



template <class T>
bool Queue<T>::isFull()
{
    return queue_size >= MAX_QUEUE;
}



template <class T>
void Queue<T>::traverse(void (*fn)(int index, T  element))
{
  T element;
  size_t i= queue_front_ptr;
  for (uint32_t c = 0; c < queue_size; c++)
    {
      element = queue_arr[i];
      std::cout << "array[" << i << "] =" << element << std::endl;
      // fn(c, element); // or (*fn)(element)


      i = (i+1) % MAX_QUEUE;
    }
}
