#include"card.h"


#define CURRENT_YEAR 22
#define MAXIMUM_EXPIRY_YEARS 20

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	printf("Enter The Card Holder Name: ");
	scanf("%s", cardData->cardHolderName);
	if (cardData->cardHolderName != NULL && strlen(cardData->cardHolderName) >= 20 && strlen(cardData->cardHolderName) <= 24) {
		for (uint8_t i = 0; i < strlen(cardData->cardHolderName); i++) {
			if (cardData->cardHolderName[i] >= '0' && cardData->cardHolderName[i] <= '9')
				return WRONG_NAME;
		}
		return OK;
	}
	return WRONG_NAME;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	printf("Enter The Card Expiry Date: ");
	scanf("%s", cardData->cardExpirationDate);
	if (cardData->cardExpirationDate == NULL || strlen(cardData->cardExpirationDate) > 5)
		return WRONG_EXP_DATE;

	if (cardData->cardExpirationDate[2] != '/')
		return WRONG_EXP_DATE;

	int monthINT = 0;
	int yearINT = 0;
	char month[2] = { cardData->cardExpirationDate[0], cardData->cardExpirationDate[1] };
	char year[2] = { cardData->cardExpirationDate[3], cardData->cardExpirationDate[4] };

	sscanf(month, "%d", &monthINT);
	sscanf(year, "%d", &yearINT);

	if (monthINT <= 0 || monthINT > 12) {
		printf("%s", "George");
		return WRONG_EXP_DATE;

	if (yearINT < CURRENT_YEAR || yearINT > (CURRENT_YEAR + MAXIMUM_EXPIRY_YEARS)) {
		return WRONG_EXP_DATE;
	}

	return OK;
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	printf("Enter The Card Card Pan: ");
	scanf("%s", cardData->primaryAccountNumber);

	if (strlen(cardData->primaryAccountNumber) < 16 || strlen(cardData->primaryAccountNumber) > 19)
		return WRONG_PAN;

	for (uint8_t i = 0; i < strlen(cardData->primaryAccountNumber); i++) {
		if (cardData->primaryAccountNumber[i] < '0' || cardData->primaryAccountNumber[i]>'9')
			return WRONG_PAN;
		}
	return OK;
}
