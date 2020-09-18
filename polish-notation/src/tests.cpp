#include <iostream>
#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <memory>

#include "PolishConverter.h"

// #define LOOP
// #define IS_DIGIT
// #define REMOVE_SPACES
// #define GET_MAP_VALUE
// #define IN_OPERATOR
// #define PARSE_EXP
#define TEST_INHARITANCE




void my_handler(int s){
  printf("Existing the code %d\n",s);
  exit(0);
}


#ifdef TEST_INHARITANCE
class A
{
public:
  A(int _x):x(_x){};

  virtual void print()
  {
    std::cout << "A: "<< x << std::endl;
  };


  template <class T>
  virtual void haha(T y)
  {
    std::cout << "A: "<< y << std::endl;
  };

  int x;
};

class B : public A
{
public:
  B(int _x):A(_x * 100){};
  void print() override
  {
    std::cout << "B: " << x << std::endl;
  };

  template <class T>
  void haha(T y)
  {
    std::cout << "hahahah; " << y << std::endl;
  };


};



#endif



int main()
{
  signal (SIGINT,my_handler);


  PolishConverter pol;


#ifdef TEST_INHARITANCE
  // solution for polymorphic pointers: https://stackoverflow.com/questions/32759556/task-list-in-c-vector-with-more-than-one-type
  // much simpler solution to mark methods of the parent class as virtual https://stackoverflow.com/questions/47186497/polymorphic-pointer
  std::vector<A* > vec;
  vec.push_back(new B(10));
  A* cp = vec.back();
  cp -> print();
  cp -> haha(5);



  // vec.push_back(new A(10));
  // cp = vec.back();
  // cp -> print();


#endif


#ifdef GET_MAP_VALUE
  std::map <std::string, int> hash;
  hash ["+"] = 3;
  int x  = 0 ;
  std::cout << pol.getMapValue(hash, std::string("+"), x) << " the value = " << x << std::endl; // for a sstring
  std::cout << pol.getMapValue(hash, std::string(1, '-'), x) << " the value = " << x << std::endl; //for a single char
#endif



#ifdef LOOP
  while (true)
    {
#ifdef IS_DIGIT
      char c;
      std::cin >> c;
      std::cout << "Is " << c << " digit ? "<< pol.isDigit(c) << std::endl;
#endif



#ifdef remove_spaces
      std::string str;
      getline(std::cin, str);
      pol.removespaces(str);
      std::cout << str << std::endl;
      std::cout << "------------------" << std::endl;
#endif





#ifdef IN_OPERATOR
      std::string str;
      getline(std::cin, str);
      std::cout << "the result of " << str[0]<<  " is: " << pol.isInOperator(str) << std::endl;
      std::cout << "------------------" << std::endl;
#endif



#ifdef PARSE_EXP
      std::string exp;
      std::vector<size_t> indcies;
      std::vector<Parameter> types;

      getline(std::cin, exp);
      pol.parseExp(exp, indcies, types);
      std::cout << "indces size = " << indcies.size() << std::endl;
      std::cout << "[";
      for(int i=0; i<indcies.size(); i++)
        std::cout << indcies[i] << ", ";
      std::cout << "]";
      std::cout<< std::endl;

      std::cout << "[";
      for(int i=0; i<types.size(); i++)
        {
          if (types[i] == Parameter::oprand)
            std::cout << "oprand" << ", ";
          else if (types[i] == Parameter::operate)
            std::cout << "operator" << ", ";
        }
     std::cout << "]";
     std::cout<< std::endl;
     std::cout << "types size = " << types.size() << std::endl;

      std::vector<size_t>::iterator i_itr;
      std::vector<Parameter>::iterator t_itr;
      for (i_itr = indcies.begin(), t_itr = types.begin(); t_itr != types.end(); i_itr++, t_itr++)
        {
          std::cout<<std::string(exp, *i_itr, *(i_itr + 1) - *i_itr);
          if (*t_itr == Parameter::oprand)
            std::cout << "    oprand";
          else if (*t_itr == Parameter::operate)
            std::cout << "    operator";

          std::cout << std::endl;

        }
      std::cout << "------------------" << std::endl;
#endif
    }
#endif
  return 0;
}
