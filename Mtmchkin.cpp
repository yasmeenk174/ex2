#include "Mtmchkin.h"
#include <string>

static Card* copyCardArray(const Card* current,int length);

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardArray, int numOfCards) : m_playerName(string(playerName))
, m_cards(copyCardArray(cardArray,numOfCards)), m_numOfCards(numOfCards), m_status(GameStatus::MidGame), m_currentCard(0),
 m_player(Player(m_playerName))
{
  
}

 Mtmchkin::~Mtmchkin()
 {
     delete[] m_cards;
 }
Mtmchkin::Mtmchkin(const Mtmchkin& game): m_playerName(game.m_playerName),
m_cards(copyCardArray(game.m_cards,game.m_numOfCards)),
m_numOfCards(game.m_numOfCards)
,m_status(game.m_status),m_currentCard(game.m_currentCard),
m_player(game.m_player)
{   
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& game )
{
    if(&game==this)
    {
        return *this;
    }
   
     m_status=game.m_status;
    m_playerName=game.m_playerName;
    m_player=game.m_player;
    m_numOfCards=game.m_numOfCards;
    m_currentCard=game.m_currentCard; 
    delete [] m_cards;
    m_cards=copyCardArray(game.m_cards,game.m_numOfCards);
    return *this;
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
bool Mtmchkin::isOver() const
{
    if (m_status == GameStatus::Win || m_status == GameStatus::Loss)
    {
        return GAME_ENDED;
    }
    return !GAME_ENDED;
}
static Card* copyCardArray(const Card* current,int length)
{
    Card* newArray=new Card[length];
    for(int i=0;i<length;i++)
    {
        newArray[i]=current[i];
    }
    return newArray;

}