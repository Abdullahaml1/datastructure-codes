#ifndef OPERATOR_POOL_H
#define OPERATOR_POOL_H

#include <stdint.h>
#include <vector>
#include <algorithm>    // std::find_if

#include "Operator.h"

struct Pos
{
public:
  Pos(int _index, OperatorType _type):index(_index), type(_type){};

  int index;
  OperatorType type;
};



class OperatorPool
{
public:

  OperatorPool(){};

  ~OperatorPool(){};

  /*
   * [load OperatorPool]
   * @return [if it is not exists will return true, and false if it exists]
   */


  template <typename Tr, typename Ti>
  bool append(OperatorInfix* oper_ptr)
  {
    return append(oper_ptr, _infix_vec_pool);
  };


  template <typename Tr, typename Ti>
  bool append(OperatorPostfix* oper_ptr)
  {
    return append(oper_ptr, _postfix_vec_pool);
  };


  bool append(OperatorPrefix* oper_ptr)
  {
    return append(oper_ptr, _prefix_vec_pool);
  };


  bool append(OperatorBraces* oper_ptr)
  {
    return append(oper_ptr, _braces_vec_pool);
  };


  template <class O>
  bool append(O * oper_ptr, std::vector<O*> & vec)
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
  // int getPrecedence(std::string name, OperatorType type)
  // {
  //   return getOperator(name, type) -> periority;
  // };



  /*
   * @return [true if it is an operator, fale otherwise]
   */
  bool isOperator(std::string name)
  {
    auto oper_cond =[name=name](Operator* oper){return oper->check_name(name);};

    if (check_cond(_infix_vec_pool, oper_cond))
      return true;

    else if(check_cond(_postfix_vec_pool, oper_cond))
      return true;
        
    else if(check_cond(_prefix_vec_pool, oper_cond))
      return true;

    else if(check_cond(_braces_vec_pool, oper_cond))
      return true;



    return false;


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


    if (check_cond(_infix_vec_pool, find_c))
      return true;

    else if(check_cond(_postfix_vec_pool, find_c))
      return true;
        
    else if(check_cond(_prefix_vec_pool, find_c))
      return true;

    else if(check_cond(_braces_vec_pool, find_c))
      return true;


    return true;

  };




  /*
   *@return [ture if the condition lambda was true]
   */
  template <class T, class Lambda>
  bool check_cond(std::vector<T* > vec, Lambda cond)
  {
    return std::find_if(vec.begin(), vec.end(), cond) != vec.end();
  };

  //----------------------------------------------------------------------------
  // Helper methos
  //----------------------------------------------------------------------------


  /*
   * [gets an operator object of the vector]
   * @return [a pointer to the operator, NULL if not found]
   */


  // TODO >>>>>>>>><<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



  // template <class O>
  // O * getOperator(std::vector<O *> & vec, Pos & pos)
  // {
  //   switch(pos.type)
  //     {
  //     case OperatorType::infix:
  //       return findOperator(_infix_vec_pool, name, type);
  //       break;

  //     case OperatorType::single_postfix:
  //       return findOperator(_postfix_vec_pool, name, type);
  //       break;


  //     case OperatorType::single_prefix:
  //       return findOperator(_prefix_vec_pool, name, type);
  //       break;


  //     case OperatorType::braces:
  //       return findOperator(_braces_vec_pool, name, type);
  //       break;
  //     }
  //   // return findOperator(_operators_vec, name, type);
  // }
   

  // // TODO >>>>>>>>><<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  // /*
  //  * [gets the >>>>first<<<< operator object of the vector that have the same
  //  * name]
  //  * @return [a pointer to the operator, NULL if not found]
  //  */


  // Operator * getOperator(std::string name)
  // {
  //   return getOperator(_operators_vec, name);
  // }


  // template <class O>
  // O * getOperator(std::vector<O *> & vec, std::string name)
  // {
  //   auto is_operator = [name=name](O * oper_ptr){
  //                        return oper_ptr->check_name(name); };

  //   std::vector<O *>::iterator itr;
  //   itr = std::find_if(vec.begin(), vec.end(), is_operator);

  //   // if not found
  //   if (itr == vec.end())
  //     return NULL;

  //   return *itr; // return pointer to the operator
  // }




  /*
   * [checks if an operator exists or not with two parametes:
   * its name, and type]
   * @return [the possiton of the operator in form of Pos strct: if it was found,
   * NULL if it is not found]
   *
   */

  Pos findOperator(std::string name, OperatorType type)
  {
    switch(type)
      {
      case OperatorType::infix:
        return findOperator(_infix_vec_pool, name, type);
        break;

      case OperatorType::single_postfix:
        return findOperator(_postfix_vec_pool, name, type);
        break;


      case OperatorType::single_prefix:
        return findOperator(_prefix_vec_pool, name, type);
        break;


      case OperatorType::braces:
        return findOperator(_braces_vec_pool, name, type);
        break;
      }
    // return findOperator(_operators_vec, name, type);
  }


  template <class O>
  Pos findOperator(std::vector<O *> & vec,
                   std::string name, OperatorType type)
  {
    auto is_operator = [name=name, type=type](O * oper){
                         return (oper->check_name(name)) && (oper->type == type);};

    std::vector<O *>::iterator itr;
    itr = std::find_if(vec.begin(), vec.end(), is_operator);

    // if not found
    if (itr == vec.end())
      return;

    return Pos(it - vec.begin(), type);
  };



  /*
   * [checks if the operator name is used single time in the operatos vector]
   * @return [true: if the operator name is used single time,
   *          false: otherwise (operator name does not exist, or used more than
   *          one time) ]
   */
  // bool singleUsedOperator(std::vector<Operator*> vec, std::string name)
  // {

  //   int count = 0;
  //   for(std::vector<Operator*>::iterator itr=vec.begin(); itr!=vec.end(); ++itr)
  //     {
  //       if ((*itr)->check_name(name))
  //         count++;

  //       if (count == 2) //more than one operator has the same name
  //         return false;
  //     }

  //   if (count == 1)
  //     {
  //       return true;
  //     }

  //   return false; // the name of the operator does not exists (not logical as we
  //                //checked before this statge)
  // }




private:

  //----------------------------------------------------------------------------
  // map for storing the precedent in the operations
  //----------------------------------------------------------------------------
  std::vector <OperatorInfix*> _infix_vec_pool;
  std::vector <OperatorPrefix*> _prefix_vec_pool;
  std::vector <OperatorPostfix*> _postfix_vec_pool;
  std::vector <OperatorBraces*> _braces_vec_pool;
};


#endif /*PRENCEDENCE_H*/
