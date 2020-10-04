#ifndef POLISH_CONVERTER_H
#define POLISH_CONVERTER_H


#include <iostream>
#include <stdint.h>
#include <map>
#include <vector>
#include <string>
#include <exception>

#include "OperatorPool.h"
#include "Operator.h"
#include "Stack.h"

//------------------------------------------------------------------------------
// tests macros
//------------------------------------------------------------------------------
// #define IN_OPERATOR
// #define TEST_EVAL
#define TEST_PARSE_BRACES
#define INFIX_TO_POSTFIX


// ->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// TODO add braces parser method

//------------------------------------------------------------------------------
// definitions
//------------------------------------------------------------------------------



enum class Parameter {oprand, operate};

class PolishConverter
{

public:
  PolishConverter()
  {
    oper_pool = OperatorPool();
    loadPrecedence();
  };

  ~PolishConverter(){};

  void infixToPostfix(std::string exp, std::string & post_fix);
  /**
   * [checks if the char is a valid digit]
   * @return [true: if a valid digit
   *          false: otherwise]
   */
  bool isDigit(char c);


  /**
   * [removes blank spaces form an exepression]
   */
  void removeSpaces(std::string &);


  /**
   * [the prencedent is 1xx, or 2xx where xx is the prencedence, 1 for a single
   * oprand, and 2 for two oprands.
   * Ex: 105 is an operator with single right oprand with precedence of 5]
   */
  void loadPrecedence()
  {


    oper_pool.append(new OperatorInfix("&&", 0, "double",
                                            [](auto x, auto y){return x+y;}));

    oper_pool.append(new OperatorInfix("&&&", 0, "double",
                                            [](auto x, auto y){return x+y;}));


    oper_pool.append(new OperatorInfix("+", 0, "double",
                                            [](auto x, auto y){return x+y;}));
    oper_pool.append(new OperatorInfix("-", 0, "dobule",
                                            [](auto x, auto y){return x-y;}));


    oper_pool.append(new OperatorInfix("*", 1, "double",
                                            [](auto x, auto y){return x*y;}));
    oper_pool.append(new OperatorInfix("/", 1, "double",
                                            [](auto x, auto y){return x/y;}));

    // braces
    oper_pool.append(new OperatorBraces("(", ")", 999));

  };




  /*
   * [sotres the indcies of the parameters of a string exepression in the given
   * vector]
   */
  void parseExp(std::string            & exp,
                std::vector<size_t>    & indcies,
                std::vector<Parameter> & types );




  /**
   * [returns the str extracted from an str expression using the start and
   * the end of its postion (stored in indcies vector exits if an error happend]
   */

  std::string get_str_param(std::string & exp, std::vector<size_t> & indcies,
                            size_t i)
  {
    if (i <= indcies.size()) // our range form i to i+1
      {
        if (indcies[i+1] <= exp.size()) // max (indcies[i+1] ) = exp.size()
          {
            return std::string(exp, indcies[i], indcies[i+1] - indcies[i]);
          }
      }

    std::cout << "\n in method get_str_param at index=" << i; ;
    std::cout << "is out or range or something else" << std::endl;
    exit(-1);

  };



  /*
   * [prase the braces within the expression and return the end star and the end
   * of the braces expression in a vector of OperatorBraces objects]
   */
  void parseBraces(std::string                   & exp,
                   std::vector<OperatorBraces *> & braces_vec,
                   std::vector<size_t>           & indcies,
                   std::vector<Parameter>        & types);





#ifdef IN_OPERATOR
  template<class T>
  bool isInOperator(T  c)
  {
    return oper_pool.isInOperator(c);
  };
#endif


#ifdef TEST_EVAL
  void test_eval(double x, double y, std::string oper_name)
  {
    Operator * oper = oper_pool.getOperator(oper_name);

    if (oper)
      {
        std::cout << "evaluation of operator: " << oper-> get_name() << std::endl;
        std::cout << x << oper-> get_name() << y << "=";
        std::cout << oper->eval(x, y) << std::endl;
      }

    else
      {
        std::cout << "operator: " << oper_name << "not found" << std::endl;
      }
  };
#endif

private:

  //----------------------------------------------------------------------------
  // class for storing the precedent in the operations
  //----------------------------------------------------------------------------
  OperatorPool oper_pool;

};
#endif /*POLISH_CONVERTER_H*/

