#include"importCsvHeader.h"

int importcsv() {
	char filepath[] = "D:\\BIG_DATA\\DSTI\\OneDrive - Data ScienceTech Institute\\2020-04-06-Software-Engineering\\part1\\esercizio\\Esercizi\\file.csv";
	int x, y, n,i;
	int error=0;
	char test[10];
	FILE* pFile = fopen(filepath, "r");

	CSVData lineContent;

	CSVData* ArrayCsvVal, buffer;
	

	if (pFile != NULL) { 
		
		printf("\nFile open successfully"); 
		
		n = 0;
		

		while (feof(pFile) == 0 ) {

			AllocateCSVDataVec(&ArrayCsvVal, n);

			fscanf(pFile, "%d,%d,%s", &x, &y, test);
			lineContent.x = x;
			lineContent.y = y;
			strcpy(lineContent.name, test);

			ArrayCsvVal[n] = lineContent;

			n++;

		}	

		for (i = 0; i < n; i++) {

			printf("\nScanned values: %d %d %s", ArrayCsvVal[i].x, ArrayCsvVal[i].y, ArrayCsvVal[i].name);
		}
		printf("\n Good night!");
	}
	else
	{
		error = -1;
		printf("Error: %d - cannot open the file", error);
	}

	return error;
	
}


BOOL AllocateCSVDataVec(CSVData** ppArray, int n)
{
	BOOL success = TRUE;
	int i;
	CSVData* pBuffer;

	if (ppArray != NULL) {

		if (*ppArray != NULL) {

			pBuffer = (CSVData*)malloc(sizeof(CSVData) * (n+1));

			if (pBuffer != NULL) {

				for (i = 0; i < n; i++) {

					pBuffer[i] = (*ppArray)[i];
				}

				if(n != 0)	free(*ppArray);

				*ppArray = pBuffer;

			}

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
