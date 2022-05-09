#include "Card.h"


#define WIN 1

Card::Card(CardType type, const CardStats &stats) : m_effect(type),
                                                    m_stats(stats)
{
}

void Card::applyEncounter(Player &player) const
{
    if(m_effect==CardType::Battle)
    {
        if(m_stats.force<=player.getAttackStrength())
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
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
        player.addCoins(m_stats.loot);
    }
}

void Card::printInfo() const
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