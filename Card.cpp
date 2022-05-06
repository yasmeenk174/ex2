#include "Card.h"

#define WIN 1

CardType m_effect;
CardStats m_stats;

Card::Card(CardType type, const CardStats &stats) : m_effect(type),
                                                    m_stats(stats)
{
}
Card::Card()
{
}
void applyEncounter(Player &player)
{
    if(m_effect==CardType::Battle)
    {
        if(m_stats.force<=player.getAttackStrength())
        {
            player.levelUp();
            player.addcoins(m_stats.loot);
            printBattleResult(WIN);
        }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(!WIN);
        }
    }
    if(m_effect==CardType::Heal)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
        }
    }
    if(m_effect==CardType::Buff)
    {
        if(player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
        }
    }
    if (m_effect==CardType::Treasure)
    {
        player.addcoins(m_stats.loot);
    }
}

void printInfo()
{
    switch (m_effect)
    {
    case CardType::Battle:
        printBattleCardInfo(m_stats);
        break;
    case CardType::Buff:
        printBuffCardInfo(m_stats);
        break;
    case CardType::Heal:
        printHealCardInfo(m_stats);
        break;
    case CardType::Treasure:
        printTreasureCardInfo(m_stats);
        break;
    }
}