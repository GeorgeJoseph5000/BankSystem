#ifndef SERVER_H
#define SERVER_H
#include <stdbool.h>
#include "../card/card.h"


typedef struct Account {
  int id;
  int expirationDate[3];
  int pan;
  char holderName[50];
  bool valid;
  int lastTransactionDate[3];
  int pin;
  int money;
} Account;

typedef struct Transaction {
  int type;
  int amount;
  int notWorking;
  int date[3];
} Transaction;

Account *getAccounts();

Account getAllCardData(Card card);

bool isValidAccount(Account account);

bool isAmountAvailable(Transaction transaction, Account account);

bool saveTransaction(Transaction transaction, Card card, Account account);

#endif