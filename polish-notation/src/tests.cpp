#include <iostream>
#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <memory>
#include <functional>

#include "PolishConverter.h"

#define LOOP
// #define IS_DIGIT
// #define REMOVE_SPACES
// #define PARSE_EXP
// #define TEST_INHARITANCE




void my_handler(int s){
  printf("Existing the code %d\n",s);
  exit(0);
}


#ifdef TEST_INHARITANCE
class A
{
public:

    template <class lam>
    A(int _x,char _type, lam exp):x(_x), type(_type)
    {
        addf = exp;
        addi = exp;
        addb = exp;
    };

  virtual void print()
  {
    std::cout << "A: "<< x << std::endl;
  };

  template <typename T>
  T eval(T a, T b)
  {
    switch(type)
      {

      case 'i':
        return addi(a, b);
        break;

      case 'f':
        return addf(a, b);
        break;


      case 'b':
        return addb(a, b);
        break;
      }
  };


  std::function<int(int, int)> addi;
  std::function<float(float, float)> addf;
  std::function<bool(bool, bool)> addb;

  char type;



  int x;
};

class B : public A
{
public:


  template <class lam>
  B(int _x,char _type, lam exp):A(_x, _type, exp)
  {
    y = 99999;
  };


  void print() override
  {
    std::cout << "B: " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "Lambda int: " << addi(x, 88);
    std::cout << " Lambda float: " << addf(11, 44.44);
    std::cout << " lambda bool: " << addb(x, 1) << std::endl;
  };


  void add99(int & m)
  {
      std::cout << "adding 99" << std::endl;
      m+=99;
  };



  int y;



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
  vec.push_back(new B(10, 'f', [](auto x, auto y){return x+y;}) );
  A* cp = vec.back();
  cp -> print();
  std::cout << "4.1 + 5.5 =" << cp->eval(4.1, 5.5) << std::endl;
  std::cout << std::endl;

  vec.push_back(new B(10, 'i', [](auto x, auto y){return x+y;}) );
  A* cp1 = vec.back();
  cp1 -> print();
  std::cout << "4.1 + 5.5 =" << cp1->eval(4.1, 5.5) << std::endl;
  std::cout << std::endl;

  B * b = (B*)vec.back();
  int z = 0;
  b -> add99(z);
  std::cout << "z =" << z << std::endl;




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
      std::vector<ParameterType> types;

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
          if (types[i] == ParameterType::oprand)
            std::cout << "oprand" << ", ";
          else if (types[i] == ParameterType::operate)
            std::cout << "operator" << ", ";
        }
     std::cout << "]";
     std::cout<< std::endl;
     std::cout << "types size = " << types.size() << std::endl;

      std::vector<size_t>::iterator i_itr;
      std::vector<ParameterType>::iterator t_itr;
      for (i_itr = indcies.begin(), t_itr = types.begin(); t_itr != types.end(); i_itr++, t_itr++)
        {
          std::cout<<std::string(exp, *i_itr, *(i_itr + 1) - *i_itr);
          if (*t_itr == ParameterType::oprand)
            std::cout << "    oprand";
          else if (*t_itr == ParameterType::operate)
            std::cout << "    operator";

          std::cout << std::endl;

        }
      std::cout << "------------------" << std::endl;
#endif


#ifdef TEST_EVAL
      std::string str;
      std::string oper_name;
      double x, y;

      std::cout << "input the firist parameter: " ;
      getline(std::cin, str);
      x = std::stod(str);


      std::cout << "input the operator " ;
      getline(std::cin, str);
      oper_name = str;


      std::cout << "input the second parameter: " ;
      getline(std::cin, str);
      y = std::stod(str);

      pol.test_eval(x, y, oper_name);

#endif




#ifdef INFIX_TO_POSTFIX
      std::string exp;
      std::vector<size_t> indcies;
      std::vector<ParameterType> types;

      getline(std::cin, exp);
      pol.removeSpaces(exp);
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
          if (types[i] == ParameterType::oprand)
            std::cout << "oprand" << ", ";
          else if (types[i] == ParameterType::operate)
            std::cout << "operator" << ", ";
        }
     std::cout << "]";
     std::cout<< std::endl;
     std::cout << "types size = " << types.size() << std::endl;

      std::vector<size_t>::iterator i_itr;
      std::vector<ParameterType>::iterator t_itr;
      for (i_itr = indcies.begin(), t_itr = types.begin(); t_itr != types.end(); i_itr++, t_itr++)
        {
          std::cout<<std::string(exp, *i_itr, *(i_itr + 1) - *i_itr);
          if (*t_itr == ParameterType::oprand)
            std::cout << "    oprand";
          else if (*t_itr == ParameterType::operate)
            std::cout << "    operator";

          std::cout << std::endl;

        }


      std::cout << "postfix: " << pol.infixToPostfix(exp)<< std::endl;
      std::cout << "infix: " << exp << std::endl;

      std::cout << "------------------" << std::endl;

#endif


#ifdef EVALUATE_EXPRESSION
      std::string exp;
      getline(std::cin, exp);
      std::cout << "postfix: " << pol.infixToPostfix(exp)<< std::endl;
      std::cout << exp << " = " << pol.evaluateExpreesion(exp) << std::endl;
      std::cout << "------------------" << std::endl;


#endif




    }
#endif /*LOOP*/




  return 0;
}
