#include <iostream>
#include "List.h"
#include <vector>

int main() {

  List<int> l ;
  int i=0;


  std::cout << "Insert test:\n";

  i =0;
  l.insert(i, 1);
  l.debug_print_list();
  std::cout << "l[" << i << "]=" << l.get(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";


  l.clean(); std::cout << "List cleaned\n";
  l.debug_print_list();
  i =-1;
  l.insert(i, 8);
  l.debug_print_list();
  std::cout << "l[" << i << "]=" << l.get(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";



  l.clean(); std::cout << "List cleaned\n";
  i =-1;
  l.insert(i, 1);
  l.debug_print_list();
  std::cout << "l[" << i << "]=" << l.get(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";



  i =-1;
  l.insert(i, 2);
  l.debug_print_list();
  std::cout << "l[" << i << "]=" << l.get(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";


  for (int j=3; j<9 ;j++)
    l.insert(-1, j);
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";



  i =4;
  l.insert(i, 44);
  l.debug_print_list();
  std::cout << "l[" << i << "]=" << l.get(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";




  i =-4;
  l.insert(i, 55);
  l.debug_print_list();
  std::cout << "l[" << i << "]=" << l.get(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";




  std::cout << "Max positive and negative limits\n";
  i =-l.size(); // 1
  l.insert(i, 111);
  l.debug_print_list();
  std::cout << "l[" << i << "]=" << l.get(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";

  i =-(l.size()+1); // 0
  l.insert(i, 10000);
  l.debug_print_list();
  std::cout << "l[" << i << "]=" << l.get(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";


  i =l.size() -1;
  l.insert(i, 777);
  l.debug_print_list();
  std::cout << "l[" << i << "]=" << l.get(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";

  i =l.size();
  l.insert(i, 888);
  l.debug_print_list();
  std::cout << "l[" << i << "]=" << l.get(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";


  std::cout << "Insert stress test\n";
  l.clean(); std::cout << "List cleaned !\n";
  l.insert(0, 1);
  int rand_int =0;
  int rand_i =0;
  for (int j=0; j<5; j++) {
    rand_int = rand();

    if (rand_int >=0) {
      rand_i = rand_int % (l.size() +1);
    }
    else {
      rand_i = rand_int % (l.size() +2);
    }

    l.insert(rand_i, rand_int);
    std::cout << "l[" << rand_i << "]=" << l.get(rand_i) << std::endl;
    std::cout << "List size=" << l.size() << "\n\n";
  }
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";

  std::cout << "Thanks to ALLAH the insert test was finished successfully \n";


  //----------------------------------------------------------------------------

  std::cout << "retrieve Test\n";
  l.clean(); std::cout << "List cleaned !\n";
  i =0;
  l.insert(i, 1);
  l.debug_print_list();
  std::cout << "retrieve(" << i << ")=" << l.retrieve(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";



  i =-1;
  l.insert(i, 1);
  l.debug_print_list();
  std::cout << "retrieve(" << i << ")=" << l.retrieve(i) << std::endl;
  std::cout << "List size=" << l.size() << "\n\n";


  for(int j=0; j<10; j++) {
    l.push_back(j);
  }
  l.debug_print_list();


  i =-1;
  std::cout << "retrieve(" << i << ")=" << l.retrieve(i) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";


  i =0;
  std::cout << "retrieve(" << i << ")=" << l.retrieve(i) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";



  i =(int)l.size()-1;
  std::cout << "retrieve(" << i << ")=" << l.retrieve(i) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";


  i =-(int)l.size();
  std::cout << "retrieve(" << i << ")=" << l.retrieve(i) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";


  i =-4;
  std::cout << "retrieve(" << i << ")=" << l.retrieve(i) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";


  i =3;
  std::cout << "retrieve(" << i << ")=" << l.retrieve(i) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";

  //----------------------------------------------------------------------------

  std::cout << "Edit Test\n";
  l.clean(); std::cout << "List cleaned !\n";
  i = 0;
  l.push_forward(1);
  std::cout << "old edit(" << i << ")=" << l.edit(i, 88) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";


  l.clean(); std::cout << "List cleaned !\n";
  i = -1;
  l.push_back(1);
  std::cout << "old edit(" << i << ")=" << l.edit(i, 88) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";



  l.clean(); std::cout << "List cleaned !\n";
  for(int j=0; j<10; j++) {
    l.push_back(j);
  }
  l.debug_print_list();


  i = 0;
  std::cout << "old edit(" << i << ")=" << l.edit(i, 88) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";



  i = -1;
  std::cout << "old edit(" << i << ")=" << l.edit(i, 88) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";


  i = (int)l.size() -1;
  std::cout << "old edit(" << i << ")=" << l.edit(i, 777) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";


  i = -(int)l.size();
  std::cout << "old edit(" << i << ")=" << l.edit(i, 777) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";



  i = 5;
  std::cout << "old edit(" << i << ")=" << l.edit(i, 777) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";


  i = -4;
  std::cout << "old edit(" << i << ")=" << l.edit(i, 777) << std::endl;
  l.debug_print_list();
  std::cout << "List size=" << l.size() << "\n\n";


  return 0;
}
