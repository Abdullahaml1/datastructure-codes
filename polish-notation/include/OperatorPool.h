#ifndef OPERATOR_POOL_H
#define OPERATOR_POOL_H

#include <stdint.h>
#include <vector>
#include <algorithm>    // std::find_if

#include "Parameter.h"
#include "Operator.h"

class OperatorPool
{
public:

  OperatorPool(){};

  ~OperatorPool(){};

  /*
   * [load OperatorPool]
   * @return [if it is not exists will return true, and false if it exists]
   */


  bool append(Operator * oper_ptr)
  {
    return append(oper_ptr, operator_vec_pool);
  };

  bool append(Operator * oper_ptr, std::vector<Operator *> & vec)
  {
    if (!findOperator(oper_ptr->get_name(), oper_ptr->type))
      {
        vec.push_back(oper_ptr);

        return true;
      }

    return false;
  };


  /*
   * [gets the prencedent value of the structure]
   */
  int getPrecedence(std::string name, ParameterType type)
  {
    return getOperator(name, type) -> periority;
  };



  /*
   * @return [true if it is an operator, fale otherwise]
   */
  bool isOperator(std::string name)
  {
    auto oper_cond =[name=name](Operator* oper){return oper->check_name(name);};

    auto itr = std::find_if(operator_vec_pool.begin(), operator_vec_pool.end(),
                            oper_cond);

    // if the operator name not found
    if (itr == operator_vec_pool.end())
      {
        return false;
      }

    return true;
  };

  /**
   * [checks if a string or char in a listed operator or not]
   */
  template<class T>
  bool isInOperator(T & c)
  {
    // lambda for finding the char in the key
    auto find_c = [c=c](Operator* oper){
                    return (oper->in_name(c));};


    auto itr=std::find_if(operator_vec_pool.begin(), operator_vec_pool.end(),find_c);

    //if the operator object not found
    if (itr == operator_vec_pool.end())
      {
        return false;
      }

    return true;

  };





  //----------------------------------------------------------------------------
  // Helper methos
  //----------------------------------------------------------------------------


  /*
   * [gets an operator object of the vector]
   * @return [a pointer to the operator, nullptr if not found]
   */


  Operator * getOperator(std::string name, ParameterType type)
  {
    return findOperator(operator_vec_pool, name, type);
  };


  /*
   * [gets the >>>>first<<<< operator object of the vector that have the same
   * name]
   * @return [a pointer to the operator, NULL if not found]
   */


  Operator * getOperator(std::string name)
  {
    return findOperator(operator_vec_pool, name);
  };


  /*
   * [gets the  operator >>>braces<<<< object of the vector that have the same
   * name]
   * @param name [the start or the end of the braces]
   * @return [a pointer to the operator, nullptr if not found]
   */


  OperatorBraces * getBraces(std::string name)
  {
    return (OperatorBraces *)findOperator(operator_vec_pool, name,
                                                       ParameterType::braces);
  };










  /*
   * [checks and retuns an operator oject if an operatorif an operator exists or
   * not with two parametes: its name, and type]
   * @return [the operator object: if it was found, nullptr if it is not found]
   *
   */

  Operator * findOperator(std::string name, ParameterType type)
  {
    return findOperator(operator_vec_pool, name, type);
  }


  Operator * findOperator(std::vector<Operator *> & vec,
                   std::string name, ParameterType type)
  {
    auto is_operator = [name=name, type=type](Operator * oper){
                         return (oper->check_name(name)) && (oper->type == type);};

    std::vector<Operator *>::iterator itr;
    itr = std::find_if(vec.begin(), vec.end(), is_operator);

    // if not found
    if (itr == vec.end())
      return nullptr;

    return *itr;
  };


  /*
   * [checks and retuns an operator oject if an operator exists or not with by
   * its >>>>name<<<<< only]
   * @return [the operator object: if it was found, nullptr if it is not found]
   *
   */

  Operator * findOperator(std::string name)
  {
    return findOperator(operator_vec_pool, name);
  }


  Operator * findOperator(std::vector<Operator *> & vec, std::string name)
  {
    auto is_operator = [name=name](Operator * oper){
                         return oper->check_name(name);};

    std::vector<Operator *>::iterator itr;
    itr = std::find_if(vec.begin(), vec.end(), is_operator);

    // if not found
    if (itr == vec.end())
      return nullptr;

    return *itr;
  };







  /*
   * [checks if the operator name is used single time in the operatos vector]
   * @return [true: if the operator name is used single time,
   *          false: otherwise (operator name does not exist, or used more than
   *          one time) ]
   */
  bool singleUsedOperator(std::vector<Operator*> & vec, std::string name)
  {

    int count = 0;
    for(std::vector<Operator*>::iterator itr=vec.begin(); itr!=vec.end(); ++itr)
      {
        if ((*itr)->check_name(name))
          count++;

        if (count == 2) //more than one operator has the same name
          return false;
      }

    if (count == 1)
      {
        return true;
      }

    return false; // the name of the operator does not exists (not logical as we
                 //checked before this statge)
  }




private:

  //----------------------------------------------------------------------------
  // map for storing the precedent in the operations
  //----------------------------------------------------------------------------
  std::vector <Operator*> operator_vec_pool;
};


#endif /* OPERATOR_POOL_H */
