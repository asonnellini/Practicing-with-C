#include"stringFunctions.h"

BOOL storeStringDyn() {
	
	BOOL success = TRUE;

	char InitInput[50];
	//char test[6] = "Hello";
	int i;
	char* dynStr;


	i = 0;

	if (InitInput != NULL) {

		printf("Type a string \n");

		scanf("%s", InitInput);
		printf("You typed %s", InitInput);

			
		while (InitInput[i] != 0) {
			i++; // i will return the number of char in the string, without considering /0

		}
		printf("\nThe string has %d charachters (Null not counted).", i);


		DynAlloc(&dynStr, i); //DynAlloc requires the number of characters of the string without the Null; it automatically adds one position for the Null 

		strcpy(dynStr, InitInput);

		printf("\n String copied in the heap: %s", dynStr);

		DeallocateString(&dynStr);

	}
	else
	{
		success = FALSE;
		
	}

	return success;
	

}

BOOL DynAlloc(char** ppStr, int NumCh) {
	BOOL success = TRUE;

	if (ppStr != NULL) {
		if (*ppStr != NULL) {
			*ppStr = (char*)malloc(sizeof(char) * (NumCh + 1));

		}
		else
		{
			success = FALSE
		}
	}
	else
	{
		success = FALSE;
	}

	return success;

}

BOOL DeallocateString(char** ppString) {

	BOOL success = TRUE;

	if (ppString != NULL) {

		if (*ppString != NULL) {

			memset(*ppString,0,sizeof(char)*strlen(*ppString));
			free(*ppString);
		}
		else
		{
			success = FALSE;
		}

	}
	else
	{
		success = FALSE;

	}

	return success;

}
