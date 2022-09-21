#include <stdio.h>
#include "card/card.h"

int main(void) {
  Card george;
  george.expirationDate = {2002,5,5};
  george.pan = 5;
  strcpy(george.holderName, "George");
  printf("%s\n", getCardHolderName(george));
  
  return 0;
}