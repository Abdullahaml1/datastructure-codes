#include <iostream>
#include <vector>
#include <string>
#include <math.h>


#include "PolishConverter.h"


int main()
{
  PolishConverter pol;
  std::vector<std::string> test_exp_vec;
  std::vector<double> result_vec;

  // appending test cases

  test_exp_vec.push_back("1+2*(3-4)");
  result_vec.push_back(1+2*(3-4));

  test_exp_vec.push_back("1111+222*(333-44444)");
  result_vec.push_back(11111+222*(333-44444));

  test_exp_vec.push_back("1111+22222*(3333333-44444444)");
  result_vec.push_back(1111+22222*(3333333-44444444));

  test_exp_vec.push_back("11.11+2.2222*(33.33333-4444.4444)");
  result_vec.push_back(11.11+2.2222*(33.33333-4444.4444));

  test_exp_vec.push_back("1+2**(3-4)/(5+7)");
  result_vec.push_back(1+pow(2, (3-4))/(5+7));

  test_exp_vec.push_back("(1+2**(3-4)/(5+7))");
  result_vec.push_back((1+pow(2,(3-4))/(5+7)));

  test_exp_vec.push_back("(1+2**(3-4)/(5+7)) - (9)");
  result_vec.push_back((1+pow(2,(3-4))/(5+7)) - (9));

  // test_exp_vec.push_back("(1+2**(3-4)/(5+7)) - (9)/(34-87**(11.11+22.2))");
  // test_exp_vec.push_back("((1+2**(3-4)/(5+7)) - (9)/(34-87**(11.11+22.2)))");
  test_exp_vec.push_back("(((1+2**(3-4)/(5+7)) - (9)/(34-87**(11.11+22.2))))");
  result_vec.push_back((((1+pow(2, (3-4))/(5+7)) - (9)/(34-pow(87, (11.11+22.2))))));




  // evaluating the test cases
  std::string exp;
  for (int i=0; i< test_exp_vec.size(); i++)
    {
      exp = test_exp_vec[i];

      std::cout << "Infix:   " << exp << std::endl;
      std::cout << "Postfix: " << pol.infixToPostfix(exp) << std::endl;
      std::cout << "True result = " << result_vec[i] << std::endl;
      std::cout << "calculated result = " << pol.evaluateExpreesion(exp) << std::endl;
      std::cout << "---------------------------------------------" << std::endl;
    }

  return 0;
}
