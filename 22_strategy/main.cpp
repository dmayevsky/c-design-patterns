#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
#include <math.h>
#include <memory>

using namespace std;

enum class Strategies{
  OrdinaryDiscriminantStrategy,
  RealDiscriminantStrategy
};

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant (double a, double b, double c) override {
      return (b*b)-(4*a*c);
    };
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
  double calculate_discriminant(double a, double b, double c) override {
    double result = (b*b)-(4*a*c);
    return result >= 0 ? result : NAN;
  };
};

class Calculator{
public:
  void select_strategy(const Strategies strategy){
    switch(strategy){
      case Strategies::OrdinaryDiscriminantStrategy:
        discriminantStrategy = make_unique<OrdinaryDiscriminantStrategy>();
        break;
      case Strategies::RealDiscriminantStrategy:
         discriminantStrategy = make_unique<RealDiscriminantStrategy>();
         break;
      default:
        throw runtime_error("Unsupported strategy.");
    };
  };
  
  void calculate(double a, double b, double c){
    if (discriminantStrategy == nullptr){
      result << " please select a strategy \n";
    }
    else {
      result << " a: " << a << " b: " << b << " c: " << c << " result: " << discriminantStrategy->calculate_discriminant(a, b, c) << "\n";
      };
    
    }  
  
  void display_results(){
    cout << result.str();
    }
  private:
    ostringstream result;
    unique_ptr<DiscriminantStrategy> discriminantStrategy {nullptr};
};

int main (){
  Calculator calculator;
  calculator.select_strategy(Strategies::OrdinaryDiscriminantStrategy);
  calculator.calculate(1.f, -5.f, 2.f);
  
    calculator.select_strategy(Strategies::RealDiscriminantStrategy);
  calculator.calculate(1.f, -5.f, 2.f);
  
  calculator.select_strategy(Strategies::OrdinaryDiscriminantStrategy);
  calculator.calculate(1.f, -2.f, 2.f);
  
  calculator.select_strategy(Strategies::RealDiscriminantStrategy);
  calculator.calculate(1.f, -2.f, 2.f);
  calculator.display_results();
  
  
  return 0;
  };