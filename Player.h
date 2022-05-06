#ifndef EX2_Player_H
#define EX2_Player_H

#include <string>
#include "utilities.h"
using namespace std;

class Player
{
public:
    /*
     * Player(constructor):
     *
     * @param playerName - The name of the player.
     * @param Max_HP- maximum health points for player.
     * @param force- players force.
     * @result
     *        builds a new player
     */
    Player(const string playerName, int Max_HP = 100, int force = 5);

    /*
     * Player(copy constructor):
     *
     * @param player-excisting player.
     * @result
     *       copying the excisting player into a new one.
     */
    Player(const Player &Player)=default;

    /*
     * Player(destructor):
     * @result
     *        deleting the player.
     */
    ~Player()=default;

    /*
     *operator=
     * @param an existing player.
     * @result
     *        coping the exsisting player into the player.
     */
    Player &operator=(const Player &)=default;

    /*
     * printInfo:
     * @result
     *       prints the players info
     */
    void printInfo();

    /*
     * levelUp:
     * @result
     *       icreases the players level.
     *
     */
    void levelUp();

    /*
     * getLevel:
     * @return
     *        returns the players level.
     */
    int getLevel();

    /*
     *buff
     * @param additionalForce- additional force to add to the player.
     * @result
     *       increasing the players force with the wanted amount.
     */
    void buff(const int &additionalForce);

    /*
     *heal
     *
     * @param additionalHP-amount of health points we want to add.
     * @result
     *        increasing the players health points with the wanted amount.
     */
    void heal(const int &additionalHP);

    /*
     *damage
     *
     * @param damage- the damage done to the player.
     * @result
     *        decreasing players health points .
     */
    void damage(const int &damage);

    /*
     *isKnockedOut
     * @return
     *  True if the player's health points are 0.
     * False if the player's health points aren't 0.
     */
    bool isKnockedOut();

    /*
     *addcoins
     *
     * @param additionalCoins- amount of coins to add.
     * @result
     *       adding the wanted amount of coins to the player.
     */
    void addcoins(const int &additionalCoins);

    /*
     *pay
     *
     * @param price- amount of coins to pay .
     * @return
     *        true if the payment was succesfull and the player has enugh money.
     *        flase if the payment has failed and the player doesn't have  enugh money.
     */
    bool pay(const int &price);

    /*
     *getAttackStrength
     * @return
     *       the players force plus it's level.
     */
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
