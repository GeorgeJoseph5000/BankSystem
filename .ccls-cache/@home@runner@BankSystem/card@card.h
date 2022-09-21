#ifndef CARD_H
#define CARD_H

typedef struct Card {
  int expirationDate[3];
  int pan;
  char holderName[50];
  int enteredPIN; 
} Card;

char *getCardHolderName(Card c);
int *getCardExpiryDate(Card c);
int getCardPAN(Card c);

#endif
