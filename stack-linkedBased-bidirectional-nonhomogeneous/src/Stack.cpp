#include "Types.h"
#include "Stack.h"

#include <string.h>

void Stack::initialize()
{
  stack_ptr = NULL;
  stack_last_ptr = NULL;
  size_count = 0;
}






void Stack::push(void * element_ptr,Types element_type, size_t element_size)
{
  // Allocating a new place in memory to the now node
  StackNode * new_node_ptr = (StackNode *) malloc(sizeof(StackNode));



  // ---- Copying the element's data into the new node ---

  // allocating memory for the element's value
  new_node_ptr -> element_ptr = (void *)malloc(element_size);

  // copying the element's value to the new memory pointed by the Stacknode
  memcpy(new_node_ptr -> element_ptr, element_ptr, element_size);

  new_node_ptr -> size = element_size;
  new_node_ptr -> type = element_type;

  //------------------------------------------------------

  // arttaching the two ends of the new nodes
  new_node_ptr -> next = stack_ptr;
  new_node_ptr -> prev = NULL;

  // attaching the top node prev end -> new node
  if (stack_ptr)
    stack_ptr -> prev = new_node_ptr;
  else
    stack_last_ptr = new_node_ptr; //if it is the first node to be pushed


  // placing the stack ptr at the first element
  stack_ptr = new_node_ptr;



  topElementType = element_type; // public variable to accessed by the user
  size_count ++;
}





// *& reference to pointer
void Stack::pop(void *& element_ptr, size_t & element_size, Types & element_type)
{
  element_ptr = stack_ptr -> element_ptr;
  element_size = stack_ptr -> size;
  topElementType = stack_ptr -> type;

  pop();
}






void Stack::pop()
{
  // pointer to be deleted
  StackNode * del_ptr = stack_ptr;

  // moving the stack pointer
  stack_ptr = stack_ptr -> next;

  // attaching the prev end to the end of the deleted node
  if (stack_ptr)
    {
      stack_ptr -> prev = del_ptr -> prev; //which is equal to NULL
    }

  else
    stack_last_ptr = NULL;//if the stack becames empty

  //freeing the allocated memory for this node
  free(del_ptr);

  size_count --;
}








size_t Stack::size()
{
  return size_count;
}






// *& reference to pointer
void Stack::top(void *& element_ptr, size_t & element_size, Types & element_type)
{
  element_ptr = stack_ptr -> element_ptr;
  element_size = stack_ptr -> size;
  topElementType = stack_ptr -> type;

}






void Stack::clean()
{
  StackNode * del_node_ptr = stack_ptr;


  while (stack_ptr != NULL)
    {
      stack_ptr = stack_ptr -> next;

      free(del_node_ptr -> element_ptr);
      free(del_node_ptr);

      del_node_ptr = stack_ptr;

    }

  stack_last_ptr = NULL;
  size_count = 0;
}





bool Stack::isEmpty()
{
  return stack_ptr == NULL;
}






bool Stack::isFull()
{
  return false;
}






void Stack::traverse(void (*fn)(size_t index, void * element_ptr,size_t element_size, Types element_type))
{
  StackNode * node_ptr = stack_ptr;
  size_t index = size_count ;

  while (node_ptr != NULL)
    {
      fn(--index, node_ptr -> element_ptr,node_ptr -> size, node_ptr -> type );

      node_ptr = node_ptr -> next;
    }
}
