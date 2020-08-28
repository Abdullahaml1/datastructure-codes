#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <functional>



enum class OperatorType {infix, single_postfix, single_prefix, braces};




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



  virtual std::string get_name()
  {
    return name;
  };

  virtual bool check_name(std::string str)
  {

    return name==str;
  };


  template <class T>
  bool in_name(T & c)
  {

    return name.find(c)!=std::string::npos;
  }

  // overlaodded operators >, <, ==

  bool operator >(Operator* x)
  {
    return (this->periority) > (x-> periority) ;
  }

  bool operator <(Operator* x)
  {
    return (this->periority) < (x-> periority) ;
  }

  bool operator ==(Operator* x)
  {
    return (this->periority) == (x-> periority) ;
  }


  //----------------------------------------------------------------------------
  // variabe attribute
  //----------------------------------------------------------------------------



  int periority;
  OperatorType type;


protected:

  std::string name; // for single sympol operator aka(not braces)



};


//------------------------------------------------------------------------------
// operator classes
//------------------------------------------------------------------------------

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







class OperatorBraces : public Operator
{
public:

  OperatorBraces(std::string _s_name, std::string _e_name, int _per):
    Operator(_s_name+_e_name, _per, OperatorType::braces)
  {
  };


private:


  std::string s_name; // the start of the braces
  std::string e_name; // the end of the braces
};

#endif /*OPERATOR_H*/
