# DataStructure Codes for this [Course](https://www.youtube.com/playlist?list=PLoK2Lr1miEm-5zCzKE8siQezj9rvQlnca)

| DataStructure Name               | Test Type                                       | Time          | Notes                                                 |
|----------------------------------|-------------------------------------------------|---------------|-------------------------------------------------------|
| STL vector                       | pushing `128000000` (`1GB`) of int64 & clearing | 5.0188 sec    | It uses nearly (`1GB`) of system memory               |
| Bidirectional stack linked based | pushing `128000000` (`1GB`) of int64 & clearing | 8.1857 sec    | the whole struct is `24 byte` the real size > (`3GB`) |
| Bidirectional stack linked based | pushing `500000` of int64                       | nearly .4 sec |                                                       |
| stack array based                | pushing `500000` of int64                       | nearly .4 sec |                                                       |



# Polish Notation Converter and Evaluator
Done docs is remained
TODO 


# Queue Array based
I will mention a nice sinple trick was used as the base of this code which is ***circular implementation***. We have two pointers front and end pointer. At appending: 
```
end_pointer = (end_pointer +1) % MAX_QUEUE;
```
And at the dequeueing
```
front_pointer = (end_pointer +1) % MAX_QUEUE;
```

Example: if MAX_QUEUE = 10, end_pointer = 4 at the appending end_pointer = (4 +1) % 10 = 5. </br>
But if end_pointer = 9, at the next append end_pointer = (1+9) %10 = 0. **Which means we are circulating around the array with two pointers***. The same happens at the dequeueing process.


# stack-linkedBased-bidirectional-nonhomogeneous

[This stack supports nonhomogeneous data defined in Types.h on one condition:
 (the data should be continous space in memory)]
 ex: int, float, double, char, arrays, structs, classed (classes should not
 use dynamic memory allocation ex: we can not use std::string, or std::vector)
 you can use any type in stack-linkedBased with the template definition


TODO


# list-circular-doubly-linkedList
A circular doubly linked list but with Addition features: 
* loop throw N/2 while getting the node  by selecting the shortest path either from the start of the list or the end of the list;
* template implemented we can use list of any data type
* supports negative and positive indcies -1 means the end of the list, and 0 means the start of the list 
```c++
int x = l[-3];
```
* supports std::iterator which will reduce time greatly comparing the normal way. theoriatically looping throw iterator is $\theta$(N), and looping throw indexing ie: `l.get(i)` or `l[i]` is $\theta$(N<sup>2</sup>). But in practice normal way of looping take more more than N<sup>2</sup> due to memory.
```c++
#include <iostream>

#include "List.h"
// #define ITERATOR
#define NORMAL

int main() {

  List<long int> l;
  long int max = 100000;
  long int count =0;

  for (long int i=0; i<max; i++) {
    l.push_back(i);
  }
  std::cout << "size=" <<l.size() << std::endl;

#ifdef ITERATOR
  std::cout << "Loop throw iterator test\n";
  count =0;
  for(List<long int>::iterator itr = l.begin(); itr !=l.end(); ++itr) {
    *itr -=1;
    count ++;
  }
  std::cout << "iterator loop finished with count=" << count << std::endl;
#endif



#ifdef NORMAL
  std::cout << "Loop throw normal way test\n";
  count =0;
  for(long int i=0; i<max; i++) {
    l[i] -=1;
    count ++;
  }
  std::cout << "Normal loop finished with count=" << count << std::endl;
#endif


  return 0;
}

```
