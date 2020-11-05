#ifndef PARAMETER_H
#define PARAMETER_H







enum class ParameterType {oprand, operate,
  infix, single_postfix, single_prefix, braces};




class Parameter
{
public:
  Parameter(){};

  ~Parameter(){};


  ParameterType type;
};





class Oprand : public Parameter
{
public:

  Oprand()
  {
    type = ParameterType::oprand;
  };


  ~Oprand(){};
};
#endif /* PARAMETER_H */
