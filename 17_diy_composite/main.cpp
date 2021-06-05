#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
struct Liquid;

template <typename Self>
struct SomeLiquid{
  string name;
  float amount;
  float  hpTotal;
  float hydrophobicity;
  ostringstream composition;
  
  template<typename T>
  void mix_in(T& other){ 
    amount += other.amount;
    hpTotal += other.hpTotal; 
    composition << other.name << "\n";
  };
  
  void printme(){
    cout << "composition: " << composition.str() << endl;
    cout << "amount: " <<  amount << endl;
  } 
};

struct Liquid: SomeLiquid<Liquid> {
  Liquid (string n, float h, float a){
    name=n;
    hydrophobicity=h;
    amount=a;
  }
  };

struct Emulsion : vector<Liquid>, SomeLiquid<Emulsion> {
  vector<Liquid> componentLiquids;
  Emulsion(string n, float a = 0, float h = 0) {
    name=n;
    amount=a;
    hydrophobicity=h;
    }
};


int main() {
  Liquid oil ("oil", 100.f, 1.f);
  Liquid milk ("milk", 20.f, 3.2);
  Liquid water ("water", 0.f, 1.5);
  
  Emulsion E1("mix");
  Emulsion E2("mix_2");
  
  
  E1.mix_in(oil);
  E1.mix_in(milk);
  
  E2.mix_in(water);
  
  E1.mix_in(E2);
  
  E1.printme();
  return 0;
}