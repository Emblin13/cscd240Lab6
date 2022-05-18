#include <stdio.h>
#include "lab6.h"

//Program written by Brendan Kendall for CSCD 240 with Professor Amack on 5/18/2022.
//This program performs various simple operations with arrays, like creating and filling arrays,
//	adding to arrays, printing arrays, etc.


int readInitialLength() {
	printf("Please enter your array length.\n");
	int length = 0;
	scanf("%d", &length);
	if (length <= 0) {
		length = 1;
	}

	return length;
}

int* createAndFill(int length) {
	printf("Please enter one integer at a time until the array has %d elements.\n", length);
	int* tempArr = (int*)calloc(length, sizeof(int));
	for (size_t i = 0; i < length; i++) {
		scanf("%d", tempArr + i);
	}

	return tempArr;
}

int menu() {
	printf("What would you like to do? Enter the number to select one of the options below:"
		"\n1) Print sorted array"
		"\n2) Add item to the array"
		"\n3) Read value from the array"
		"\n4) Quit\n");
	int choice;
	scanf("%d", &choice);
	while (choice > 4 || choice < 1) {
		printf("Not a valid option. Please enter 1, 2, 3, or 4\n");
		scanf("%d", &choice);
	}

	return choice;
}

void printSortedArray(int* array, int n)
{
	size_t i, j;
	int min;
	int* tempArr = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		tempArr[i] = array[i];
	}

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min = i;
		for (j = i + 1; j < n; j++)
			if (tempArr[j] < tempArr[min])
				min = j;

		// Swap the found minimum element with the first element
		int temp = tempArr[min];
		tempArr[min] = tempArr[i];
		tempArr[i] = temp;
	}

	for (i = 0; i < n; i++) {
		printf("Array[%d]: %d\n", i, tempArr[i]);
	}
}

int* addItem(int* length, int* array) {
	int size = *length;
	int i;
	int* tempArr = (int*)calloc(size + 1, sizeof(int));
	for (i = 0; i < size; i++) {
		tempArr[i] = array[i];
	}
	printf("Enter an integer to be added to the array.\n");
	scanf("%d", &tempArr[size]);

	cleanUp(array);
	*length = (size + 1);

	return tempArr;
}

int readValue() {
	printf("Enter an integer to be searched for in the array.\n");
	int value;
	scanf("%d", &value);
	return value;
}

void printIfFound(int value, int* array, int length) {
	for (int i = 0; i < length; i++) {
		if (array[i] == value) {
			printf("%d was found in the array at index %d\n", value, i);
			return;
		}
	}
	printf("%d was not found in the array\n", value);
}

void cleanUp(int* array) {
	free(array);
}