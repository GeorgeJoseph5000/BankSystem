#ifndef SERVER_H
#define SERVER_H

typedef struct Account {
  int expirationDate[3];
  int pan;
  char holderName[50];
  bool valid;
  int lastTransactionDate[3];
  int pin;
} Account;

Account accounts[] = {
  {{2022, 9, 28}, 45, "George", true, {2022, 5, 28}, 1234}, 
  {{2023, 5, 28}, 45, "Sam", true, {2022, 5, 28}, 4321},
};




#endif