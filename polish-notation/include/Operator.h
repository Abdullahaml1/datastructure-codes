#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <functional>



enum class OperatorType {infix, single_postfix, single_prefix, braces};




class Operator
{
public:
  Operator(){};

  Operator(std::string _name, int _Per,OperatorType _type,
           std::string _data_type): name(_name),
                                    periority(_Per),
                                    type(_type),
                                    data_type(_data_type)
  {

    eval_2_int = nullptr;
    eval_2_double = nullptr;
    eval_2_bool = nullptr;


    eval_1_int = nullptr;
    eval_1_double = nullptr;
    eval_1_bool = nullptr;
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



  /**
   * [evaluation method for the for the operator]
   */
  template <typename T>
  T eval(T x, T y)
  {
    if (data_type == "int")
      {
        return eval_2_int(x, y);
      }

    else if (data_type == "double")
      {
        return eval_2_double(x, y);
      }

    else if (data_type == "bool")
      {
        return eval_2_bool(x, y);
      }

  };

  template <typename T>
  T eval(T x)
  {
    if (data_type == "int")
      {
        return eval_1_int(x);
      }

    else if (data_type == "double")
      {
        return eval_1_double(x);
      }

    else if (data_type == "bool")
      {
        return eval_1_bool(x);
      }

  };

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
  // helpers
  //----------------------------------------------------------------------------
  template <class Lamda>
  void setup_eval2(std::string & d, Lamda & lam)
  {
    if (d == "int")
      {
        eval_2_int = lam;
      }

    else if (d == "double")
      {
        eval_2_double = lam;
      }

    else if (d == "bool")
      {
        eval_2_bool = lam;
      }

  };



  template <class Lamda>
  void setup_eval1(std::string & d, Lamda & lam)
  {
    if (d == "int")
      {
        eval_1_int = lam;
      }

    else if (d == "double")
      {
        eval_1_double = lam;
      }

    else if (d == "bool")
      {
        eval_1_bool = lam;
      }

  };

  //----------------------------------------------------------------------------
  // variabe attribute
  //----------------------------------------------------------------------------



  int periority;
  OperatorType type;


protected:

  std::string name; // for single sympol operator aka(not braces)

  std::string data_type; // int, or double or boolean, .....


  // ---------------functions to evaluate the expreesion
  // 2, or 1 -> the number of input paramers

  std::function<int(int, int)> eval_2_int;
  std::function<double(double, double)> eval_2_double;
  std::function<bool(bool, bool)> eval_2_bool;


  std::function<int(int)> eval_1_int;
  std::function<double(double)> eval_1_double;
  std::function<bool(bool)> eval_1_bool;

};


//------------------------------------------------------------------------------
// operator classes
//------------------------------------------------------------------------------

class OperatorInfix : public Operator
{
public:

  template <class Lambda>
  OperatorInfix(std::string _name, int _per,std::string _data_type, Lambda lam):
    Operator(_name, _per, OperatorType::infix, _data_type)
  {
    setup_eval2(data_type, lam);
  };



};






class OperatorPostfix : public Operator
{
public:

  template <class Lambda>
  OperatorPostfix(std::string _name, int _per,std::string _data_type, Lambda lam):
    Operator(_name, _per, OperatorType::single_postfix, _data_type)
  {
    setup_eval1(data_type, lam);
  };



};









class OperatorPrefix : public Operator
{
public:

  template <class Lambda>
  OperatorPrefix(std::string _name, int _per, std::string _data_type, Lambda lam):
    Operator(_name, _per, OperatorType::single_prefix, _data_type)
  {
    setup_eval1(data_type, lam);
  };

};






class OperatorBraces : public Operator
{
public:

  OperatorBraces(std::string _s_name, std::string _e_name, int _per):
    Operator(_s_name + _e_name, _per, OperatorType::braces, "none"),
    s_name(_s_name),
    e_name(_e_name),
    exp_start_index(0),
    exp_end_index(0)
  {
  };


  bool check_name(std::string str)
  {
    return (str == s_name) || (str == e_name);
  };

  bool check_start(std::string str)
  {
    return str == s_name;
  };


  bool check_end(std::string str)
  {
    return str == e_name;
  };







  /**
   * [append the start of the expresion index within the braces]
   */
  void append_exp_start(size_t i)
  {
    exp_start_index = i;
  };

  /**
   * [returns the start of the expresion index within the braces]
   */
  size_t get_exp_start()
  {
    return exp_start_index;
  };

  bool check_exp_start(size_t i)
  {
    return i == exp_start_index;
  };





  /**

   * [append the end of the expresion index within the braces]
   */
  void append_exp_end(size_t i)
  {
    exp_end_index = i;
  };

  /**
   * [returns the end of the expresion index within the braces]
   */
  size_t get_exp_end()
  {
    return exp_end_index;
  };


  bool check_exp_end(size_t i)
  {
    return i == exp_end_index;
  };

  bool check_exp_end_changed()
  {
    return exp_end_index != 0;
  };



  OperatorBraces * clone()
  {
    return new OperatorBraces(s_name, e_name, periority);
  }

private:


  std::string s_name; // the start of the braces
  std::string e_name; // the end of the braces

  size_t exp_start_index; // the start of the expresion index within the braces
  size_t exp_end_index; // the end of the expresion index within the braces

};

#endif /*OPERATOR_H*/
