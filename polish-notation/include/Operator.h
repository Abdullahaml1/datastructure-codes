#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <functional>



enum class OperatorType {infix, single_postfix, single_prefix};




class Operator
{
public:
  Operator(){};

  Operator(std::string _name, int _Per, OperatorType _type):
                                                      name(_name),
                                                      periority(_Per),
                                                      type(_type)
  {
  };


  ~Operator(){};



  template <typename Tr, typename Ti>
  Tr eval(Ti x, Ti y);


  template <typename Tr, typename Ti>
  Tr eval(Ti x);


  //----------------------------------------------------------------------------
  // variabe attribute
  //----------------------------------------------------------------------------
  std::string name;
  int periority;
  OperatorType type;



};



template <typename Tr, typename Ti>
class OperatorInfix : public Operator
{
public:

  template <class Lambda>
  OperatorInfix(std::string _name, int _per, Lambda _func):
    Operator(_name, _per, OperatorType::infix), func(_func)
  {
  };


  std::function<Tr(Ti, Ti)> func;

  Tr eval(Ti x, Ti y)
  {
    return static_cast<Tr>(func(x, y));
  }

};


template <typename Tr, typename Ti>
class OperatorPostfix : public Operator
{
public:

  template <class Lambda>
  OperatorPostfix(std::string _name, int _per, Lambda _func):
    Operator(_name, _per, OperatorType::single_postfix), func(_func)
  {
  };


  std::function<Tr(Ti)> func;

  Tr eval(Ti x)
  {
    return static_cast<Tr>(func(x));
  }

};






template <typename Tr, typename Ti>
class OperatorPrefix : public Operator
{
public:

  template <class Lambda>
  OperatorPrefix(std::string _name, int _per, Lambda _func):
    Operator(_name, _per, OperatorType::single_prefix), func(_func)
  {
  };


  std::function<Tr(Ti)> func;

  Tr eval(Ti x)
  {
    return static_cast<Tr>(func(x));
  }

};

#endif /*OPERATOR_H*/
