#include <iostream>
#include <string>

using namespace std;

struct A{
  string name;
  A(string name): name(name); 
};



int main() {
  std::cout << "hello";
  A a("test");
  std::cout << a.name;
}