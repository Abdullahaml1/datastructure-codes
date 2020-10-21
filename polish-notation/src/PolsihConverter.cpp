#include "PolishConverter.h"

#include <iostream>
#include <sstream>


template <class T>
void invalid_arguemt_excep(T param)
{
  std::ostringstream oss;
  oss << "'" << param << "'"<< " is not VALID" << std::endl;
  throw std::invalid_argument(oss.str());
}


void print_braces_message(std::string & exp, size_t i, std::string msg)
{
  std::cout << std::endl << msg;
  std::cout << std::endl << exp << std::endl;
  std::cout << std::string(i, ' ') << "^";
  std::cout << std::endl;
  exit(-1);

};


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
  else if (oper_pool.isInOperator(exp[last_i]))
    {
      indcies.push_back(last_i);
      types.push_back(Parameter::operate);
    }
  else
    {
      // raise exepression invalid operantor
    }


  for (size_t i = 1; i < exp.size(); i++ )
    {
      if (isDigit(exp[last_i]) && oper_pool.isInOperator(exp[i]))
        {
          indcies.push_back(i);
          types.push_back(Parameter::operate);
        }

      else if (oper_pool.isInOperator(exp[last_i]) && isDigit(exp[i]))
        {
          size_t start_index = indcies.back();
          // the string excludgin the last char (i)
          std::string sym = std::string(exp, start_index, i - start_index);

          // for operator of more than one char
          if(oper_pool.isOperator(sym))
            {
              indcies.push_back(i);
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
      else if (oper_pool.isInOperator(exp[last_i]) && oper_pool.isInOperator(exp[i]))
        {
          size_t start_index = indcies.back();
          std::string sym = std::string(exp, start_index, i - start_index + 1);
          std::string sym_1 = std::string(exp, start_index, i - start_index );

          if(!oper_pool.isInOperator(sym)  && oper_pool.isOperator(sym_1))
            {
              indcies.push_back(i);
              // the next item is an operator
              types.push_back(Parameter::operate);
            }
        }


      else if (!isDigit(exp[i]) && !oper_pool.isInOperator(exp[i]))
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

  if (!oper_pool.isOperator(temp) && !isDigit(exp.back()))

    {
      // raise excepssion invalid sympol
      invalid_arguemt_excep(temp);
    }

  // if (indcies.back() != exp.size() - 1)
  indcies.push_back(exp.size());
}






void PolishConverter::parseBraces(std::string                   & exp,
                                  std::vector<OperatorBraces *> & braces_vec,
                                  std::vector<size_t>           & indcies,
                                  std::vector<Parameter>        & types)
{
  OperatorBraces * b = nullptr;
  std::string opr_str;



  for(size_t i=0; i<types.size(); i++)
    {
      if (types[i] == Parameter::operate)
        {
          opr_str = get_str_param(exp, indcies, i);
          b = oper_pool.getBraces(opr_str);


          if (b != nullptr) // its is a braces
            {

              if (braces_vec.empty() && b-> check_start(opr_str))
                {
                  braces_vec.push_back(b -> clone());
                  braces_vec.back() -> append_exp_start(indcies[i+1]);
                }


              // the start of the braces
              else if( !braces_vec.empty() && b -> check_start(opr_str))
                {
                  braces_vec.push_back(b -> clone());
                  braces_vec.back() -> append_exp_start(indcies[i+1]);
                }


              //  we will loop in braces_vec untill we find a matching brace
              else if( !braces_vec.empty() && b -> check_end(opr_str))
                {
                  for(int j=braces_vec.size()-1; j>-1; j--)
                    {
                      if (!braces_vec[j] -> check_exp_end_changed())
                        {
                          braces_vec[j] -> append_exp_end(indcies[i] -1);
                          break;
                        }

                      // we reached the end withot finding a matching brace
                      else if(j == 0)
                        {
                          print_braces_message(exp, indcies[i], "Expected start of the braces before the end");
                        }
                    }
                }


              else
                {
                  print_braces_message(exp, indcies[i], "Expected end of the braces or, beginning with the end of the braces");
                }

            } // if (b != nullptr)
        } // the string is a valid ooperator
    } // for loop



  // checking if the braces start but has no closer
  for(int j=braces_vec.size()-1; j>-1; j--)
    {
      if (!braces_vec[j] -> check_exp_end_changed())
        {
          size_t i = braces_vec[j] -> get_exp_start();
          print_braces_message(exp, i-1, "the braces has no end");
        }
    }


#ifdef TEST_PARSE_BRACES
  for(int j=braces_vec.size()-1; j>-1; j--)
    {
      std::cout << "bracs[" << j << "] start = " << braces_vec[j] -> get_exp_start();
      std::cout << ", end= " << braces_vec[j] -> get_exp_end() << std::endl;
      std::cout << exp << std::endl;
      std::cout << std::string(braces_vec[j] -> get_exp_start() - 1, ' ') << "^";
      std::cout << std::string(braces_vec[j] -> get_exp_end() -
                               braces_vec[j] -> get_exp_start() +1, ' ') << "^";
      std::cout << std::endl;

    }
#endif

};


void PolishConverter::infixToPostfix_algorithm(std::string & exp,
                                               int exp_start_index,
                                               int exp_end_index,
                                               std::vector<size_t> & in_indcies,
                                               std::vector<Parameter> & types,
                                               std::vector<OperatorBraces *> & braces_vec,

                                               std::string & postfix_str,
                                               std::vector<size_t> & out_indcies,
                                               std::vector<Operator *> & out_operator_vec)

{
  // get the start of the exp in the in_indcies vector
  int loop_start = 0;
  for (int i=0; i < in_indcies.size(); i++)
    {
      if (in_indcies[i] == exp_start_index)
        {
          loop_start = i;
          break;
        }
    }


  std::string param;
  Operator * opr;
  Operator * top_opr;
  Stack<Operator*> opr_stack;

  std::cout << "loop start = " << loop_start << std::endl;

  for (int i = loop_start; in_indcies[i] <= exp_end_index; i++)
    {

      std::cout << "in_incies[i] = " << in_indcies[i] << std::endl;

      param = get_str_param(exp, in_indcies,i);

      if (types[i] == Parameter::oprand)
        {
          out_indcies.push_back(postfix_str.size()); // the star of the oprand
          out_operator_vec.push_back(new Operator()); // an operator with no type
          postfix_str += param;
        }

      else
        {
          opr = oper_pool.getOperator(param);
          switch(opr -> type)
            {
            case OperatorType::infix :
              if (opr_stack.isEmpty())
                {
                  opr_stack.push(opr);
                }

              else
                {
                  opr_stack.top(top_opr);

                  if (opr -> bigger(top_opr))
                    {
                      opr_stack.push(opr);
                    }

                  else if (opr -> smaller_or_equal(top_opr))
                    {

                      while (opr -> smaller_or_equal(top_opr) &&
                             ! opr_stack.isEmpty())
                        {
                          opr_stack.pop(top_opr);

                          // the star of the oprand
                          out_indcies.push_back(postfix_str.size());

                          out_operator_vec.push_back(top_opr);
                          postfix_str += top_opr -> get_name();

                          if (!opr_stack.isEmpty())
                            {
                              opr_stack.top(top_opr);
                            }
                        }

                      opr_stack.push(opr);
                    }
                }


              break;

            case OperatorType::single_prefix :
              break;

            case OperatorType::single_postfix :
              break;

            case OperatorType::braces :
              break;


            }

        }
    }




  // flush all the remainder of operators in the stack
  while (! opr_stack.isEmpty())
    {
      opr_stack.pop(top_opr);

      // the star of the oprand
      out_indcies.push_back(postfix_str.size());

      out_operator_vec.push_back(top_opr);
      postfix_str += top_opr -> get_name();
    }


  // out_indcies should end with the string size
  out_indcies.push_back(postfix_str.size());

}









void PolishConverter::infixToPostfix(std::string & exp, std::string & postfix_exp,
                                     std::vector<size_t> & out_indcies,
                                     std::vector<Operator*> & out_operator_vec)
{
  std::vector<size_t> indcies; //donates the start and stop of each parameter
  std::vector<Parameter> types; // the type of each parameter
  std::vector<OperatorBraces *> braces_vec;
  Stack<Operator *> oper_stack;



  removeSpaces(exp);
  parseExp(exp, indcies, types);
  parseBraces(exp, braces_vec, indcies, types);


  postfix_exp = "";
  infixToPostfix_algorithm(exp, 0, exp.size()-1, indcies, types, braces_vec,
                           postfix_exp, out_indcies, out_operator_vec);


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

