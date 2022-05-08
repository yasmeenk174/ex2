#include "Player.h"

Player::Player(const string name, int Max_HP, int force)
:m_name(name),m_maxHP(Max_HP>0?Max_HP:DEFAULT_MAXHP),m_force(force>0?force:DEFAULT_FORCE),m_coins(DEFAULT_COINS),m_level(DEFAULT_LEVEL),m_HP(m_maxHP)
{
}

void Player::printInfo()
{
   printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}
void Player::levelUp()
{
   if (m_level < FINAL_LEVEL)
   {
      m_level++;
   }
}
int Player::getLevel()
{
   return m_level;
}

void Player::buff(const int &additionalForce)
{
   if (additionalForce > 0)
   {
      m_force += additionalForce;
   }
}
void Player::heal(const int &additionalHP)
{
   if (m_HP == m_maxHP)
   {
      return;
   }
   if (additionalHP > 0)
   {
      m_HP += additionalHP;
      if (m_HP > m_maxHP)
      {
         m_HP = m_maxHP;
      }
   }
}
void Player::damage(const int &damage)
{
   if (damage < 0)
   {
      return;
   }
   if (m_HP < damage)
   {
      m_HP = 0;
      return;
   }
   m_HP -= damage;
}
bool Player::isKnockedOut()
{
   return (m_HP == 0);
}
void Player::addCoins(const int &additionalCoins)
{
   if (additionalCoins > 0)
   {
      m_coins += additionalCoins;
   }
}
bool Player::pay(const int &price)
{
   if (price <= m_coins && price > 0)
   {
      m_coins -= price;
      return true;
   }
   return false;
}
int Player::getAttackStrength()
{
   return m_force + m_level;
}
