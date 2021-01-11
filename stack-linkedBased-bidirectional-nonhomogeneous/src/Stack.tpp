




// template <typename T>
// void Stack<T>::push_back(T element)
// {
//     // Allocating a new place in memory for the new node
//     StackNode<T> * new_node_ptr = (StackNode<T> *)malloc(sizeof(StackNode<T>));

//     //placeing the new element
//     new_node_ptr -> element = element;

//     //attaching the two ends of the new node
//     new_node_ptr -> prev = stack_last_ptr;
//     new_node_ptr -> next = NULL;

//     //attaching the old left node
//     if (stack_last_ptr)
//         stack_last_ptr -> next = new_node_ptr;

//     else
//         stack_ptr = new_node_ptr; //if it is the first node to be pushed

//     //placing the the last_stack pointer at the end of the stack again
//     stack_last_ptr = new_node_ptr;

//     size_count ++;
// }




// template <typename T>
// void Stack<T>::pop_back(T & element)
// {
//     element = stack_last_ptr -> element;
//     pop_back();
// }

// template <typename T>
// void Stack<T>::pop_back()
// {
//     StackNode<T> * del_ptr = stack_last_ptr;

//     //moving the last_stack pointer
//     stack_last_ptr = stack_last_ptr -> prev;

//     // attaching the nexr end to the end of the deleted node
//     if (stack_last_ptr)
//         stack_last_ptr -> next = del_ptr -> next; //which is NULL

//     else
//         stack_ptr  = NULL;//if the stack becames empty

//     //freeing the allocated memory for this node
//     free(del_ptr);

//     size_count --;
// }



// template <typename T>
// void Stack<T>::top(T & element)
// {
//     element = stack_ptr -> element;
// }



// template< typename T>
// void Stack<T>::top_back(T & element )
// {
//     element = stack_last_ptr -> element;
// }







// template < typename T>
// void Stack<T>::copy(Stack & s)
// {
//     //this is exacly as the traverse_backward, but more professional
//     //for("init statement; iterate if this condition is true; incremantal statemet)
//     for(StackNode<T> * node_ptr = stack_last_ptr; node_ptr; node_ptr = node_ptr -> prev)
//         s.push(node_ptr -> element);
// }









// template <typename T>
// void Stack<T>::traverse(void (*fn)(size_t ,T ) )
// {
//     StackNode<T> * node_ptr = stack_ptr;
//     size_t index = size_count;

//     while(node_ptr != NULL)
//         {
//             (*fn)(--index, node_ptr -> element);
//             node_ptr = node_ptr -> next;

//         }
// }




// template <typename T>
// void Stack<T>::traverse_backward(void (*fn)(size_t ,T ) )
// {
//     StackNode<T> * node_ptr = stack_last_ptr;
//     size_t index =  0;

//     while(node_ptr != NULL)
//         {
//             (*fn)(index++, node_ptr -> element);
//             node_ptr = node_ptr -> prev;

//         }
// }
