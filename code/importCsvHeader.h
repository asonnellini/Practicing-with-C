#pragma once
#include"tools.h"

typedef struct sCSVData
{
	int x;
	int y;
	char name[10];
}CSVData;

int importcsv();

BOOL AllocateCSVDataVec(CSVData**, int);