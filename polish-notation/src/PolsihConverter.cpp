#include "PolishConverter.h"

#include <iostream>
#include <sstream>

#include "Stack.h"

template <class T>
void invalid_arguemt_excep(T param)
{
  std::ostringstream oss;
  oss << "'" << param << "'"<< " is not VALID" << std::endl;
  throw std::invalid_argument(oss.str());
}


bool PolishConverter::isDigit(char c)
{
  return ((c >= '0') && (c <= '9')) || (c == '.');
}


void PolishConverter::removeSpaces(std::string &str)
{
  std::string::iterator itr;
  itr = str.begin();

  while (itr != str.end())
    {
      if (*itr == ' ')
        str.erase(itr, itr+1);

      else
        itr++;
    }
}






void PolishConverter::parseExp(std::string            & exp,
                               std::vector<size_t>    & indcies,
                               std::vector<Parameter> & types )
{
  size_t last_i = 0;

  if (isDigit(exp[last_i]))
    {
      indcies.push_back(last_i);
      types.push_back(Parameter::oprand);
    }
  else if (operp.isInOperator(exp[last_i]))
    {
      indcies.push_back(last_i);
      types.push_back(Parameter::operate);
    }
  else
    {
      // raise exepression invalid operantor
      invalid_arguemt_excep(exp[last_i]);
    }


  for (size_t i = 1; i < exp.size(); i++ )
    {
      if (isDigit(exp[last_i]) && operp.isInOperator(exp[i]))
        {
          indcies.push_back(i);
          types.push_back(Parameter::operate);
        }

      else if (operp.isInOperator(exp[last_i]) && isDigit(exp[i]))
        {
          size_t start_index = indcies.back();
          // the string excludgin the last char (i)
          std::string sym = std::string(exp, start_index, i - start_index);

          // for operator of more than one char
          if(operp.isOperator(sym))
            {
              indcies.push_back(i); //start of a digit
            }

          else
            {
              // raise excepssion invaild operator
              invalid_arguemt_excep(sym);
            }

          // the number is operand
          types.push_back(Parameter::oprand);
        }

      // for operantor more than one char
      else if (operp.isInOperator(exp[last_i]) && operp.isInOperator(exp[i]))
        {
          size_t start_index = indcies.back();
          std::string sym = std::string(exp, start_index, i - start_index + 1);
          std::string sym_1 = std::string(exp, start_index, i - start_index );

          if(!operp.isInOperator(sym)  && operp.isOperator(sym_1))
            {
              indcies.push_back(i);
              // the next item is an operator
              types.push_back(Parameter::operate);
            }
        }


      else if (!isDigit(exp[i]) && !operp.isInOperator(exp[i]))
        {
          // raise exepession invaild operator
          invalid_arguemt_excep(exp[i]);
        }

      last_i = i;
    }

  std::string temp;
  if (indcies.empty())
    temp = exp;
  else
    temp = std::string(exp, indcies.back());

  if (!operp.isOperator(temp) && !isDigit(exp.back()))

    {
      // raise excepssion invalid sympol
      invalid_arguemt_excep(temp);
    }

  // if (indcies.back() != exp.size() - 1)
  indcies.push_back(exp.size());
}






void PolishConverter::parseBraces(std::string            & exp,
                                  std::vector<size_t>    & braces_indcies)
{
  Stack<OperatorBraces*> braces_pool;
};

    
  
  
  



void PolishConverter::infixToPostfix(std::string exp, std::string & post_fix)
{
  std::vector<size_t> indcies; //donates the start and stop of each parameter
  std::vector<Parameter> types; // the type of each parameter
  Stack<std::string> oper_s;


  removeSpaces(exp);
  parseExp(exp, indcies, types);



  std::vector<size_t>::iterator i_itr;
  std::vector<Parameter>::iterator t_itr;
  for (i_itr = indcies.begin(), t_itr = types.begin(); t_itr != types.end();
       i_itr++, t_itr++)
    {
      std::string param = std::string(exp, *i_itr, *(i_itr + 1) - *i_itr);

      if (*t_itr == Parameter::oprand)
        {
        }

      else if (*t_itr == Parameter::operate)
        {
        }

    }

  /*
  std::string::iterator itr, last_itr, num_start, num_end;
  Stack operators;

  while (itr != exp.end())
    {
           // if it is a sympol push it to the stack

        // check if the operator has more han one sympol

          // if the sympol has a single left opernad

          // if the symple has a single right operand

          // if the operator is infix
    }
    */
}

