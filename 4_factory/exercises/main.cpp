#include <string>
#include <iostream>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
  int id{0};
public:
  
  Person create_person(const string& name)
  {
    return {id++, name};
  }
};

int main(){
  PersonFactory factory;
  auto steve = factory.create_person("dave");
  auto oriya = factory.create_person("oriya");

  return 0;
  }