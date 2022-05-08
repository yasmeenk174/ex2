#include "Mtmchkin.h"
#include <string>


Mtmchkin::Mtmchkin(const char *playerName, const Card *cardArray, int numOfCards):
     m_playerName(string(playerName)),m_cards(new Card[numOfCards]),m_numOfCards(numOfCards),m_status(GameStatus::MidGame),m_currentCard(0),m_Player(Player(m_playerName))
{
    for (int i = 0; i < numOfCards; i++)
    {
        m_cards[i]=cardArray[i];
    }
}


