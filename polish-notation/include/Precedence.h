#ifndef PRENCEDECE_H
#define PRENCEDECE_H

#include <stdint.h>
#include <vector>
#include <algorithm>    // std::find_if

#include "Operator.h"

class Precedence
{
public:

  Precedence(){};

  ~Precedence(){};

  /*
   * [load Precedence]
   * @return [if it is not exists will return true, and false if it exists]
   */
  bool append(Operator * oper_ptr)
  {
    if (!findOperator(oper_ptr->name, oper_ptr->type))
      {
        _operators_vec.push_back(oper_ptr);

        return true;
      }

    return false;
  };


  /*
   * [gets the prencedent value of the structure]
   */
  int getPrecedence(std::string name, OperatorType type)
  {
    return getOperator(name, type) -> periority;
  };



  /*
   * @return [true if it is an operator, fale otherwise]
   */
  bool isOperator(std::string name)
  {
    auto oper_cond = [name=name](Operator* oper){return oper->name == name;};

    auto itr = std::find_if(_operators_vec.begin(), _operators_vec.end(),
                            oper_cond);


    // if the operator name not found
    if (itr == _operators_vec.end())
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
                    return (oper->name.find(c) != std::string::npos);};


    auto itr=std::find_if(_operators_vec.begin(), _operators_vec.end(),find_c);

    //if the operator object not found
    if (itr == _operators_vec.end())
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
   * @return [a pointer to the operator, NULL if not found]
   */


  Operator * getOperator(std::string name, OperatorType type)
  {
    return getOperator(_operators_vec, name, type);
  }


  Operator * getOperator(std::vector<Operator*> & vec,
                         std::string name, OperatorType type)
  {
    auto is_operator = [name=name, type=type](Operator * oper){
                         return (oper->name == name) && (oper->type == type);};

    std::vector<Operator *>::iterator itr;
    itr = std::find_if(vec.begin(), vec.end(), is_operator);

    // if not found
    if (itr == vec.end())
      return NULL;

    return *itr; // return pointer to the operator
  }



  /*
   * [gets the >>>>first<<<< operator object of the vector that have the same
   * name]
   * @return [a pointer to the operator, NULL if not found]
   */


  Operator * getOperator(std::string name)
  {
    return getOperator(_operators_vec, name);
  }


  Operator * getOperator(std::vector<Operator*> & vec, std::string name)
  {
    auto is_operator = [name=name](Operator * oper_ptr){
                         return oper_ptr->name == name;};

    std::vector<Operator *>::iterator itr;
    itr = std::find_if(vec.begin(), vec.end(), is_operator);

    // if not found
    if (itr == vec.end())
      return NULL;

    return *itr; // return pointer to the operator
  }







  /*
   * [checks if an operator exists or not with two parametes:
   * its name, and type]
   * @return [true: if it was found, false if it is not found]
   *
   */

  bool findOperator(std::string name, OperatorType type)
  {
    return findOperator(_operators_vec, name, type);
  }


  bool findOperator(std::vector<Operator*> & vec,
                   std::string name, OperatorType type)
  {
    auto is_operator = [name=name, type=type](Operator * oper){
                         return (oper->name == name) && (oper->type == type);};

    std::vector<Operator *>::iterator itr;
    itr = std::find_if(vec.begin(), vec.end(), is_operator);

    // if not found
    if (itr == vec.end())
      return false;

    return true;
  }



  /*
   * [checks if the operator name is used single time in the operatos vector]
   * @return [true: if the operator name is used single time,
   *          false: otherwise (operator name does not exist, or used more than
   *          one time) ]
   */
  bool singleUsedOperator(std::vector<Operator*> vec, std::string name)
  {

    int count = 0;
    for(std::vector<Operator*>::iterator itr=vec.begin(); itr!=vec.end(); ++itr)
      {
        if ((*itr)->name == name)
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
  std::vector <Operator*> _operators_vec;
};


#endif /*PRENCEDENCE_H*/
