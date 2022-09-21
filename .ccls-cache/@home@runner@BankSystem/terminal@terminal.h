#ifndef TERMINAL_H
#define TERMINAL_H
#include "../server/server.h"


int *getTransactionDate();

bool isCardExpired(Card card);
Transaction getTransactionAmount( int type, int amount, Card card);
void setMaxAmount(int max);
bool isBelowMaxAmount(int amount);

#endif