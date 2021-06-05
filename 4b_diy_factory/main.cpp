#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct grocery{
  string label;
  float unitPrice;
  int unitCount;
};

struct groceryFactory: grocery{
  float totalPrice {0};
  ostringstream oss;
  grocery create_grocery(string label, float unitPrice, int unitCount)
  {
    float subtotal = unitPrice*unitCount;
    oss << label << " - " << unitPrice << " - " <<unitCount << " - subtotal: " << subtotal << "\n";
    totalPrice += subtotal;
    return grocery{label, unitPrice, unitCount };
  }
  
  void str() const { 
    std::cout<< oss.str(); 
    std::cout << "total: " << totalPrice << "\n"; }
};

int main() {
  groceryFactory gf;
  auto celery = gf.create_grocery("celery", 3.f, 3);
  auto carrot = gf.create_grocery("carrot", 1.7, 4);
  auto cariot = gf.create_grocery("cariot", 20.f, 1);
  gf.str();
  return 0;
}