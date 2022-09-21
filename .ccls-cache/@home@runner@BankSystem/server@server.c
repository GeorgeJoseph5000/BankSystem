#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "server.h"

Account accounts[] = {
  {0, {2022, 9, 22}, 45, "George", true, {2022, 5, 28}, 1234, 50}, 
  {1, {2023, 5, 28}, 50, "Sam", false, {2022, 5, 28}, 4321, 100},
};

Account *getAccounts(){
  return accounts;
}

Account getAllCardData(Card card){
  int i;
  for (i = 0; i < sizeof(getAccounts()); i++) {
    if(card.pan == getAccounts()[i].pan){
      //printf("%d\n", getAccounts()[i].money);
      return getAccounts()[i];
    }
  }  
}


bool isValidAccount(Account account){
  return account.valid;
}

bool isAmountAvailable(Transaction transaction, Account account){
  return account.money >= transaction.amount;
}

bool saveTransaction(Transaction transaction, Card card, Account account){
  if(transaction.notWorking == 0){
    return false;
  }
  if(card.enteredPIN == account.pin){
    if(isValidAccount(account)){
      if(transaction.type == 1 && isAmountAvailable(transaction, account)){
        accounts[account.id].money -= transaction.amount;
  
        accounts[account.id].lastTransactionDate[0] = transaction.date[0];
        accounts[account.id].lastTransactionDate[1] = transaction.date[1];
        accounts[account.id].lastTransactionDate[2] = transaction.date[2];
        return true;
      }else if(transaction.type == 1 && !isAmountAvailable(transaction, account)){
        printf("Funds are insufficient \n");
      }
      if(transaction.type == 0){
  
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        accounts[account.id].money += transaction.amount;
        
        accounts[account.id].lastTransactionDate[0] = tm.tm_year;
        accounts[account.id].lastTransactionDate[1] = tm.tm_mon;
        accounts[account.id].lastTransactionDate[2] = tm.tm_mday;
        return true;
      }
    }else{
      printf("Card is invalid \n");
    }
  }else{
    printf("Invalid PIN\n");
  }
  return false;
}