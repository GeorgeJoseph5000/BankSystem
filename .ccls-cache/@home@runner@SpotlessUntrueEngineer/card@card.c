#include <stdio.h>
#include "card.h"

char *getCardHolderName(Card c){
  return c.holderName;
}

int *getCardExpiryDate(Card c){
  return c.expirationDate;
}

int getCardPAN(Card c){
  return c.pan;
}