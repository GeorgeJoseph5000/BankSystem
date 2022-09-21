#include <stdio.h>
#include <stdbool.h>
#include "terminal/terminal.h"

int main(void) {
  bool repeat = true;
  while(repeat){
    Card card;
    int pan;
    int pin;
    int type;
    int amount;
    printf("Enter your PAN: ");
    scanf("%d", &pan);
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    printf("Insert(0) or Withdraw(1): ");
    scanf("%d", &type);
    printf("Amount: ");
    scanf("%d", &amount);
    
    
    card.pan = pan;
    card.enteredPIN = pin;
    Account account = getAllCardData(card);
    strcpy(card.holderName, account.holderName);
    card.expirationDate[0] = account.expirationDate[0];
    card.expirationDate[1] = account.expirationDate[1];
    card.expirationDate[2] = account.expirationDate[2];
    
  
    saveTransaction(getTransactionAmount(type, amount, card), card, account) ? printf("Total Amount: %d\n", getAllCardData(card).money) : printf("");
  
    int repeatNo;
    printf("Repeat (0) => NO (1) => YES: ");
    scanf("%d", &repeatNo);
    repeat = (repeatNo != 0);
      
    //printf("%d", getAllCardData(card).lastTransactionDate[2]);
  }
  return 0;
}
