//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <string>
#include <iostream>

 const int  GAME_ENDED =1;
/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
 */
enum class GameStatus
{
    Win,
    Loss,
    MidGame
};


class Mtmchkin
{
public:
    /**
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
     */
    Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards);
    /**
     * @brief Destroy the Mtmchkin object
     * 
     */
    ~Mtmchkin ();
    /**
     * @brief Construct a new Mtmchkin object
     * 
     * @param game the game we want to copy
     * @return the new copied game
     */
    Mtmchkin(const Mtmchkin& game);
    /**
     * @brief assignment function for game 
     * 
     * @param game the game that is assigned to the current game (*this)
     * @return the current game (*this)
     */
   Mtmchkin&  operator=(const Mtmchkin& game );
    /**
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
     */
    void playNextCard();

    /**
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;

    /**
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;


private:
    string m_playerName;
    Card *m_cards;
    int m_numOfCards;
    GameStatus m_status;
    int m_currentCard;
    Player m_player;
};

#endif // EX2_GAME_H
