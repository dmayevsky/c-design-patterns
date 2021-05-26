#include "exercise.h"


using namespace std;
int sum(const vector<ContainsIntegers*> items)
{
  int total {0};
  for (auto item: items){
    total += item->total();
  }
  cout << "total is: " <<  total << endl;
  return 0;
}

int main(){
  SingleValue single_value { 1 };
  single_value.print();
  ManyValues other_values;
  other_values.add(2);
  other_values.add(3);
  other_values.print();
  
  
  sum({&single_value, &other_values});
  
  return 0;
}