#include <iostream>
#include <vector>
#include <string>


#include "PolishConverter.h"


int main()
{
  PolishConverter pol;
  std::vector<std::string> test_exp_vec;
  std::vector<double> result;

  // appending test cases

  test_exp_vec.push_back("1+2*(3-4)");
  result.push_back(1+2*(3-4));

  test_exp_vec.push_back("1111+22222*(3333333-44444444)");
  result.push_back(1111+22222*(3333333-44444444));

  test_exp_vec.push_back("11.11+2.2222*(33.33333-4444.4444)");
  result.push_back(11.11+2.2222*(33.33333-4444.4444));

  // test_exp_vec.push_back("1+2**(3-4)/(5+7)");
  // test_exp_vec.push_back("(1+2**(3-4)/(5+7))");
  // test_exp_vec.push_back("(1+2**(3-4)/(5+7)) - (9)");
  // test_exp_vec.push_back("(1+2**(3-4)/(5+7)) - (9)/(34-87**(11.11+22.2))");
  // test_exp_vec.push_back("((1+2**(3-4)/(5+7)) - (9)/(34-87**(11.11+22.2)))");
  test_exp_vec.push_back("(((1+2**(3-4)/(5+7)) - (9)/(34-87**(11.11+22.2))))");




  // evaluating the test cases
  std::string exp;
  for (int i=0; i< test_exp_vec.size(); i++)
    {
      exp = test_exp_vec[i];

      std::cout << "Infix:   " << exp << std::endl;
      std::cout << "Postfix: " << pol.infixToPostfix(exp) << std::endl;
      std::cout << "True result = " << result[i] << std::endl;
      std::cout << "calculated result = " << pol.evaluateExpreesion(exp) << std::endl;
      std::cout << "---------------------------------------------" << std::endl;
    }

  return 0;
}
