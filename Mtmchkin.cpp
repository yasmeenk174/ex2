#include "Mtmchkin.h"
#include <string>

string m_playerName;
Card *m_cards;
int m_numOfCards;
GameStatus m_status;
int currentCard;

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardArray, int numOfCards):
     m_playerName(string(playerName)),m_numOfCards(numOfCards),m_status(GameStatus::MidGame),currentCard(0)
{
    for (int i = 0; i < numOfCards; i++)
    {
        m_cards[i]=cardArray[i];
    }
}

