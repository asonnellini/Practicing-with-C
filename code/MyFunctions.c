#include "MyFunctions.h"

/* Strategy:
1) Request user to type the dimension of the vectors
2) Request the user to type the elements of vector 1
3) Request the user to type the elements of vector 1
4) COmpare the 2 vectors and build a vector of 2 elements with the score 
5) Print this vector of Results
Techincal Notes:
- Ensure that you create dynamically a vector and then free it within solveExercise, i.e. you have to manage in solveExercise an int**

*/




void solveExercise()
{
	
	int dimVect;
	int i,j ;
	int* pVect = NULL;
	int NUM_ROW=2;
	BOOL RequestVectEl_success, DynAllocVect_success;


	//Request user the dimension of the vector
	RequestVectEl_success = RequestVectEl(&dimVect);
	
	if (RequestVectEl_success == 0) 
	{
		printf("There was an error in passing the address of the variable dimVect\n ");
	}

	//We assume that we can enter a pre-Defined number of vectors ==> MAX_ROW


	//dinamycally allocate the vector
	DynAllocVect_success = DynAllocVect(&pVect, dimVect, NUM_ROW);

	if (DynAllocVect_success == 0)
	{
		printf("There was an error in passing the pointer of the vector to the function DynAllocVect \n ");
	}

	StoreVectVal(&pVect, dimVect, NUM_ROW);

	//Compute the score
	Score(&pVect, dimVect, NUM_ROW);


	//Free memory
	FreeMem(&pVect, NUM_ROW);

}


BOOL RequestVectEl(int* pDimVect) {
	
	BOOL safety = TRUE;

	if (pDimVect != NULL)
	{
		printf("Please type the dimension of the vectors\n");

		scanf("%d", pDimVect);

		printf("You typed %d\n", *pDimVect);
	}
	else
	{
		safety = FALSE;
	}
	return safety;

}

BOOL DynAllocVect(int** ppVec, int dimVector, int numVect) {

	BOOL safety = TRUE;

	if (ppVec != NULL) 
	{
		if (*ppVec == NULL) 
		{
			*ppVec = (int*)malloc(sizeof(int) * dimVector * numVect);
		}
		else
		{
			safety = FALSE;
		}
		
	}
	else
	{
		safety = FALSE;
	}
	
	return safety;
}

BOOL StoreVectVal(int** pVector, int numberElements, int NumbVect) {
	BOOL success = TRUE;
	int i, j;

	for (i = 0; i <= numberElements * (NumbVect - 1); i = i + numberElements)
	{
		for (j = 0; j <= numberElements - 1; j++)
		{

			printf("Please type the element %d of the vector number %d \n", j + 1, i / numberElements + 1);
			scanf("%d", &((*pVector)[i + j]));
			
		}


	}

	for (i = 0; i <= numberElements * (NumbVect - 1); i = i + numberElements)
	{
		printf("Vector number %d is \n", i / numberElements + 1);
		for (j = 0; j <= numberElements - 1; j++)
		{
			printf("%d ", (*pVector)[i + j]);

		}
		printf("\n");

	}
	return success;
}

BOOL Score(int** ppVect, int numberElements, int NumbVect)
{
	BOOL success = TRUE; 
	int* scoreVect = NULL;
	int i,j;

	if ((ppVect != NULL) & (*ppVect != NULL))
	{
		success = DynAllocVect(&scoreVect, NumbVect, 1);

		if (success == 0) printf("Exception: Cannot create the vector to store the scores\n");
		else
		{
			scoreVect[0] = 0;
			scoreVect[1] = 0;
			for (i = 0; i < numberElements ; i++)
			{
				if ((*ppVect)[i] > (*ppVect)[i + numberElements]) scoreVect[0]++;
				else
				{
					if((*ppVect)[i] < (*ppVect)[i + numberElements]) scoreVect[1]++;
				}
				

			}
			printf("The score is :\n");

			for (j = 0; j < NumbVect; j++)
			{
				printf("%d ",scoreVect[j]);
			}
		}
	
	}
	else
	{
		success = FALSE;
	}

	 

	
}


BOOL FreeMem(int** ppVect, int numEl)
{
	BOOL success = TRUE;
	

	if ((ppVect != NULL) & (*ppVect != NULL))
	{
		memset(*ppVect, 0, sizeof(int) * numEl);
		free(*ppVect);
		*ppVect = NULL;
	}
	else
	{
		success = FALSE;
	}

	return success;
}
