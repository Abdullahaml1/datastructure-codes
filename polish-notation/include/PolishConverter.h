#ifndef POLISH_CONVERTER_H
#define POLISH_CONVERTER_H



#include <stdint.h>
#include <map>
#include <vector>
#include <string>
#include <exception>

#include "OperatorPool.h"
#include "Operator.h"


//------------------------------------------------------------------------------
// tests macros
//------------------------------------------------------------------------------
// #define IN_OPERATOR



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


    oper_pool.append(new OperatorInfix<double, double>("&&", 0,
                                            [](auto x, auto y){return x+y;}));

    oper_pool.append(new OperatorInfix<double, double>("&&&", 0,
                                            [](auto x, auto y){return x+y;}));


    oper_pool.append(new OperatorInfix<double, double>("+", 0,
                                            [](auto x, auto y){return x+y;}));
    oper_pool.append(new OperatorInfix<double, double>("-", 0,
                                            [](auto x, auto y){return x-y;}));


    oper_pool.append(new OperatorInfix<double, double>("*", 1,
                                            [](auto x, auto y){return x*y;}));
    oper_pool.append(new OperatorInfix<double, double>("/", 1,
                                            [](auto x, auto y){return x/y;}));

  }




  /*
   * [sotres the indcies of the parameters of a string exepression in the given
   * vector]
   */
  void parseExp(std::string            & exp,
                std::vector<size_t>    & indcies,
                std::vector<Parameter> & types );



  /*
   * [prase the braces within the expression and return the end star and the end
   * of the braces expression in a vector at braces_indcies vector at this form
   * {braes_i_start, braces_i_end, braces_i_start, braes_i_end, ......}]
   */
  void parseBraces(std::string            & exp,
                   std::vector<size_t>    & braces_indcies);




#ifdef IN_OPERATOR
  template<class T>
  bool isInOperator(T  c)
  {
    return operp.isInOperator(c);
  };
#endif

private:

  //----------------------------------------------------------------------------
  // class for storing the precedent in the operations
  //----------------------------------------------------------------------------
  OperatorPool oper_pool;

};
#endif /*POLISH_CONVERTER_H*/

