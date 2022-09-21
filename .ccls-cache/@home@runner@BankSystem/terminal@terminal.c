#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "terminal.h"


int maxAmount = 50;

int *getTransactionDate(){
  
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int currentDate[3] = {tm.tm_year, tm.tm_mon, tm.tm_mday};
  return currentDate;
}

bool isCardExpired(Card card){

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  if(tm.tm_year > getAllCardData(card).expirationDate[0]){
    return true;
  }else{
    if(tm.tm_mon > getAllCardData(card).expirationDate[1]){
      return true;
    }else{
      if(tm.tm_mday > getAllCardData(card).expirationDate[2]){
        return true;
      }else{
        return false;
      }
    }
  }
}

Transaction getTransactionAmount(int type, int amount, Card card){
  if(!isCardExpired(card)){ 
    if(isBelowMaxAmount(amount)){
      Transaction transaction = {
        type,
        amount,
        1,
        getTransactionDate()
      };
      return transaction;
    }else{
      printf("The amount is above max amount. \n");
      Transaction notworking = {0, 0, 0, {0, 0, 0}};
      return notworking;
    }
  }else{
    printf("Your card is expired. \n");
    Transaction notworking = {0, 0, 0, {0, 0, 0}};
      return notworking;
  }
}

bool isBelowMaxAmount(int amount){
  return amount < maxAmount;
}

void setMaxAmount(int max){
  maxAmount = max;
}
