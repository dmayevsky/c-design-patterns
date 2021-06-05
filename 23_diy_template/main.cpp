#include <iostream>
#include <sstream>
#include <string>
#include <array>

using namespace std;


struct makeShawarma {
  
  ostringstream oss;

  virtual void bakeBread(ostringstream &oss){
    oss << "1. bake laffa\n";
    }
  virtual void cutVegetables(ostringstream &oss){
    oss << "2. cut cucumbers and tomatoes\n";
    }
  virtual void prepareMeat(ostringstream &oss){
    oss << "3. shave the doner and reheat the meat \n";
    }
  virtual void combine(ostringstream &oss){
    oss << "4. place meat, vegetables and suace in laffa then wrap it in paper \n";
  }
  virtual void serve(ostringstream &oss){
    oss << "5. give to customer \n";
  }

  void cook(){
    bakeBread(oss);
    cutVegetables(oss);
    prepareMeat(oss);
    combine(oss);
    serve(oss);
    }
    
  void print(){
    std::cout << oss.str();
  }  

};



struct makeLambShwarma : makeShawarma{
    void prepareMeat(ostringstream &oss) override {
    oss << "3. shave the LAMB doner and reheat the meat \n";
    }
    
};

struct makeChickenShawarma : makeShawarma{
    void prepareMeat(ostringstream &oss) override {
      oss << "3. shave the CHICKEN doner and reheat the meat \n";
    }
};

struct makeMelbourneShawarma : makeShawarma{
    void cutVegetables(ostringstream &oss) override {
      oss << "3. make tabouleh \n";
    }
};




int main() {
  makeLambShwarma s1;
  s1.cook();
  s1.print();
  
  makeChickenShawarma s2;
  s2.cook();
  s2.print();
  
  makeMelbourneShawarma s3;
  s3.cook();
  s3.print();
  
  return 0;
}