#include "Mtmchkin.h"
#include <string>

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardArray, int numOfCards) : m_playerName(string(playerName)), m_cards(new Card[numOfCards]), m_numOfCards(numOfCards), m_status(GameStatus::MidGame), m_currentCard(0), m_player(Player(m_playerName))
{
    for (int i = 0; i < numOfCards; i++)
    {
        m_cards[i] = cardArray[i];
    }
}
void Mtmchkin::playNextCard()
{
    if (m_currentCard == m_numOfCards)
    {
        m_currentCard = 0;
    }
    Card currentCard = m_cards[m_currentCard];
    currentCard.printInfo();
    currentCard.applyEncounter(m_player);
    if (m_player.getLevel() == FINAL_LEVEL)
    {
        m_status = GameStatus::Win;
    }
    else
    {
        if (m_player.isKnockedOut())
        {
            m_status = GameStatus::Loss;
        }
    }
    m_player.printInfo();
    m_currentCard++;
}
GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}
bool Mtmchkin::isOver()
{
    if (m_status == GameStatus::Win || m_status == GameStatus::Loss)
    {
        return GAME_ENDED;
    }
    return !GAME_ENDED;
}
