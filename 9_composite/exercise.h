#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct ContainsIntegers
{
  virtual void print() = 0;
  virtual int total() = 0;
};

struct SingleValue : ContainsIntegers
{
  int value{ 0 };

  SingleValue() = default;

  explicit SingleValue(const int value)
    : value{value}
  {
  }
  
  int total() override {
    return value;
  }
  
  void print() override {
    cout << "single_value: " << value <<endl;
  }
};

struct ManyValues : vector<int>, ContainsIntegers
{
  void add(const int value)
  {
    push_back(value);
  }
  
  void print() override {
    cout << "["; 
      for (auto n: *this){
        cout << n << ", ";
      }
      cout << "]" << endl;
    }
    
  int total() override{
      return accumulate(this->begin(), this->end(), 0);
  }
};

int sum(const vector<ContainsIntegers*> items);