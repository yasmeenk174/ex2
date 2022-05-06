#include "Card.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utilities.h"

int main()
{
   CardStats stats(2,3,4,6,6);
   CardStats temp(stats);
   Card card(CardType::Battle,stats);
   printf("%d\n",stats.hpLossOnDefeat);
   //Card card(CardType::Battle,stats);
   return 0; 

}