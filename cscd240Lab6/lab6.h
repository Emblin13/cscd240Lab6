#ifndef LAB_6
#define LAB_6

#include <stdio.h>
#include <stdlib.h>

int readInitialLength();
int *createAndFill(int length);
int menu();
void printSortedArray(int *array, int length);
int *addItem(int *length, int *array);
int readValue();
void printIfFound(int value, int * array, int length);
void cleanUp(int *array);

#endif 
