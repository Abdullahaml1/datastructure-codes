#include <stdexcept>



template <typename T>
void Stack<T>::initialize()
{
   stack_ptr = NULL;
   stack_last_ptr = NULL; size_count = 0;
}



template <typename T>
void Stack<T>::push(T  element)
{
    // Allocating a new place in memory to the now node
    StackNode<T> * new_node_ptr = (StackNode<T> *) malloc(sizeof(StackNode<T>));
    if (new_node_ptr == NULL)
        throw std::runtime_error (" The Os has no enough memory");

    new_node_ptr -> element = element;

    // arttaching the two ends of the new nodes
    new_node_ptr -> next = stack_ptr;

    if (stack_ptr == NULL)
        stack_last_ptr = new_node_ptr; //if it is the first node to be pushed

    // placing the stack ptr at the first element
    stack_ptr = new_node_ptr;

    size_count ++;
}



template <typename T>
void Stack<T>::push_back(T element)
{
    // Allocating a new place in memory for the new node
    StackNode<T> * new_node_ptr = (StackNode<T> *)malloc(sizeof(StackNode<T>));

    if (new_node_ptr == NULL)
        throw std::runtime_error (" The Os has no enough memory");

    //placeing the new element
    new_node_ptr -> element = element;

    //attaching the  end of the new node
    new_node_ptr -> next = NULL;

    //attaching the old left node
    if (stack_last_ptr)
        stack_last_ptr -> next = new_node_ptr;

    else
        stack_ptr = new_node_ptr; //if it is the first node to be pushed

    //placing the the last_stack pointer at the end of the stack again
    stack_last_ptr = new_node_ptr;

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
    StackNode<T> * del_ptr = stack_ptr;

    // moving the stack pointer
    stack_ptr = stack_ptr -> next;


    if(stack_ptr == NULL)
        stack_last_ptr = NULL;//if the stack becames empty

    //freeing the allocated memory for this node
    free(del_ptr);

    size_count --;
}


template <typename T>
void Stack<T>::pop_back(T & element)
{
    element = stack_last_ptr -> element;
    pop_back();
}

template <typename T>
void Stack<T>::pop_back()
{
    // StackNode<T> * del_ptr = stack_last_ptr;

    // //moving the last_stack pointer
    // stack_last_ptr = stack_last_ptr -> prev;

    // // attaching the nexr end to the end of the deleted node
    // if (stack_last_ptr)
    //     stack_last_ptr -> next = del_ptr -> next; //which is NULL

    // else
    //     stack_ptr  = NULL;//if the stack becames empty

    // //freeing the allocated memory for this node
    // free(del_ptr);

    // size_count --;
}



template <typename T>
void Stack<T>::top(T & element)
{
    element = stack_ptr -> element;
}



template< typename T>
void Stack<T>::top_back(T & element )
{
    element = stack_last_ptr -> element;
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

    stack_last_ptr = NULL;
    size_count = 0;
}



template < typename T>
void Stack<T>::copy(Stack & s)
{
    //this is exacly as the traverse_backward, but more professional
    //for("init statement; iterate if this condition is true; incremantal statemet)
    // for(StackNode<T> * node_ptr = stack_last_ptr; node_ptr; node_ptr = node_ptr -> prev)
    //     s.push(node_ptr -> element);
}



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

