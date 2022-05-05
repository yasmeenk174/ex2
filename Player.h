#ifndef EX2_Player_H
#define EX2_Player_H

#include <string>
#include "utilities.h"
using namespace std;

class Player
{
    public:
    Player(const string name, int Max_HP=100,  int force=5);
    Player(const Player& Player);
    ~Player();
    Player& operator=(const string&);
    void printInfo();
    void levelUp();
    int getLevel();
    void buff(const int& additionalForce);
    void heal(const int& additionalHP);
    void damage(const int& damage);
    bool isKnockedOut();
    void addcoins(const int& additionalCoins);
    bool pay(const int& price);
    int getAttackStrength();

 
   private:
   string m_name;
   int m_level;
   int m_force;
   const int m_maxHP;
   int m_HP;
   unsigned int m_coins;

};

#endif
