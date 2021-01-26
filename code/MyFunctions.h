#pragma once

#include "tools.h"

//Execute the exercise
void solveExercise();

BOOL RequestVectEl(int* pDimVect);

BOOL DynAllocVect(int** ppVec, int dimVector);

BOOL StoreVectVal(int** pVector, int numberElements, int NumbVect);

BOOL Score(int** pVect, int numberElements, int NumbVect);

BOOL FreeMem(int** ppVect, int numEl);
