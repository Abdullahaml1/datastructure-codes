#include <iostream>
#include <vector>
#include <string>


#include "PolishConverter.h"


int main()
{
  PolishConverter pol;
  std::vector<std::string> test_exp_vec;

  // appending test cases

  test_exp_vec.push_back("1+2**(3-4)");
  test_exp_vec.push_back("1111+22222**(3333333-44444444)");
  test_exp_vec.push_back("11.11+2.2222**(33.33333-4444.4444)");
  test_exp_vec.push_back("1+2**(3-4)/(5+7)");
  test_exp_vec.push_back("(1+2**(3-4)/(5+7))");
  test_exp_vec.push_back("(1+2**(3-4)/(5+7)) - (9)");
  test_exp_vec.push_back("(1+2**(3-4)/(5+7)) - (9)/(34-87**(11.11+22.2))");
  test_exp_vec.push_back("((1+2**(3-4)/(5+7)) - (9)/(34-87**(11.11+22.2)))");
  test_exp_vec.push_back("(((1+2**(3-4)/(5+7)) - (9)/(34-87**(11.11+22.2))))");




  // evaluating the test cases
  for (std::vector<std::string>::iterator itr=test_exp_vec.begin();
       itr != test_exp_vec.end(); ++itr)
    {
      std::cout << "Infix:   " << *itr << std::endl;
      std::cout << "Postfix: " << pol.infixToPostfix(*itr) << std::endl;
      std::cout << "---------------------------------------------" << std::endl;
    }

  return 0;
}
