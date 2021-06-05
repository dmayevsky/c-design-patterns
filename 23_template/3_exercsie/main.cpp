#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct Creature
{
    int attack, health;

    Creature(int attack, int health) : attack(attack), health(health) {}
};

struct CardGame
{
    vector<Creature> creatures;

    CardGame(const vector<Creature> &creatures) : creatures(creatures) {}

    // return the index of the creature that won (is a live)
    // example:
    // - creature1 alive, creature2 dead, return creature1
    // - creature1 dead, creature2 alive, return creature2
    // - no clear winner: return -1
    
    virtual void determine_winner() = 0;
    
    int combat()
    {
      hit(creatures.at(0), creatures.at(1));
      hit(creatures.at(1), creatures.at(0));
      
      int creature_idx = 0;
      int survivors = 2;
      
      for(auto &creature : creatures){
        creature_idx ++;
        if (creature.health > 0)
          {std::cout << "creature" << creature_idx << " alive,";
          }
        else {
          std::cout << "creature" << creature_idx << " dead,";
          survivors -= 1;
          }
        } 
    return survivors;
    }

    virtual void hit(Creature& attacker, Creature& other) = 0;
};

struct TemporaryCardDamageGame : CardGame
{
    TemporaryCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

    void hit(Creature &attacker, Creature &other) override {
      if (other.health <= attacker.attack){
        other.health -= attacker.attack;
        }
    }
    void determine_winner() override {
      int survivors = combat();
      std::cout << " survivors: "  << survivors << std::endl;
    }
};

struct PermanentCardDamageGame : CardGame
{
    PermanentCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

    void hit(Creature &attacker, Creature &other) override
    {
      other.health -= attacker.attack;
    }
    void determine_winner() override {
    int round {0};
    int survivors = 2;
    while (survivors > 0){
      round++;
      survivors = combat();
      std::cout << "round: " << round << " survivors: "  << survivors << std::endl;
    }
    }
    
};

int main(){
  
  TemporaryCardDamageGame temporaryCardDamageGame1(vector<Creature> {Creature(1, 2), Creature(1, 3)});
  temporaryCardDamageGame1.determine_winner();
  TemporaryCardDamageGame temporaryCardDamageGame2(vector<Creature> {Creature(2, 2), Creature(2, 2)});
  temporaryCardDamageGame2.determine_winner();
  
  PermanentCardDamageGame permanentCardDamageGame1(vector<Creature> {Creature(1, 2), Creature(1, 3)});
  permanentCardDamageGame1.determine_winner();
  PermanentCardDamageGame permanentCardDamageGame2(vector<Creature> {Creature(2, 2), Creature(2, 2)});
  permanentCardDamageGame2.determine_winner();
  
  return 0;
  }
