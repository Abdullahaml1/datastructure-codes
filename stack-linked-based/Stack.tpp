template <typename T>
void Stack<T>::initialize()
{
   stack_ptr = NULL;
   size_count = 0;
}



template <typename T>
void Stack<T>::push(T  element)
{
    // Allocating a new place in memory to the now node
    StackNode<T> * new_node_ptr = (StackNode<T> *) malloc(sizeof(StackNode<T>));

    new_node_ptr -> element = element;
    new_node_ptr -> next = stack_ptr;
    stack_ptr = new_node_ptr;

    size_count ++;
}



template <typename T>
void Stack<T>::pop(T & element)
{
    element = stack_ptr -> element;
    pop();
}

template <typename T>
void Stack<T>::pop()
{
    StackNode<T> * del_node = stack_ptr;
    stack_ptr = stack_ptr -> next;

    //freeing the allocated memory for this node
    free(del_node);

    size_count --;
}



template <typename T>
void Stack<T>::top(T & element)
{
    element = stack_ptr -> element;
}




template <typename T>
void Stack<T>::clean()
{
    StackNode<T> * del_node_ptr = stack_ptr;
    while (stack_ptr != NULL)
        {
            stack_ptr = stack_ptr -> next;
            free(del_node_ptr);
            del_node_ptr = stack_ptr;
        }
    size_count = 0;
}



// template < typename T>
// void Stack<T>::copy(Stack & s)
// {
//     T  element;
//     for (uint32_t i=0; i < stack_ptr; i++)
//     {
//         element = stack_arr[i];
//         s.push(element);
//     }
// }



template <typename T>
size_t Stack<T>::size()
{
    return size_count;
}



template <typename T>
bool Stack<T>::isEmpty()
{
    return stack_ptr == NULL;
}



template <typename T>
bool Stack<T>::isFull()
{
    return false;
}




template <typename T>
void Stack<T>::traverse(void (*fn)(size_t ,T ) )
{
    StackNode<T> * node_ptr = stack_ptr;
    size_t index = size_count;

    while(node_ptr != NULL)
        {
            (*fn)(--index, node_ptr -> element);
            node_ptr = node_ptr -> next;

        }
}

