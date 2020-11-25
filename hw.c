#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


void print(int B[], int n);

void BubbleSort1(int A[], int n)
{
	int i, j;
	int tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}
}
void InsertionSort(int A[], int n) {
	int i, j;
	int tmp;
	bool wasSwap;
	for (i = 1; i < n; i++) {
		tmp = A[i];
		for (j = i - 1; j >= 0; j--) {
			if (tmp > A[j])
				break;
			A[i] = A[j];
			tmp = A[j];
		}

	}
	
}




void BubbleSort(int A[], int n)
{
	int i, j;
	int tmp;
	bool wasSwap;

	for (i = 0; i < n; i++)
	{
		wasSwap = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				wasSwap = true;
			}
		}
		for (j = n - i - 2; j > 0; j--)
		{
			if (A[j] < A[j - 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				wasSwap = true;
			}
		
		if (!wasSwap) // wasSwap == false
		{
			break;
		}
	}

		print(A, n);
	}

	printf("i = %d\n", i);
}


void randArray(int B[], int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}

void sortedArray(int B[], int n)
{
	int i; int tmp;
	for (i = 0; i < n; i++)
		B[i] = i;

	tmp = B[n - 2];
	B[n - 2] = B[n - 1];
	B[n - 1] = tmp;
}

void print(int B[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
	printf("\n");
}

void menu()
{
	printf("\nMENU:\n");
	printf("1. Input array\n");
	printf("2. Print array\n");
	printf("3. BubbleSort\n");
	printf("4. InsertionSort\n");
	printf("0. Exit\n");
}

void main()
{
	int B[10];
	int n = 10;
	int t = 10;
	bool wasInput = false;

	printf("start\n");
	srand(1000);

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1: {
			//sortedArray(B, n);
			randArray(B, n, -10, 10);
			wasInput = true;
			break;
		}
		case 2: {
			if (wasInput)
				print(B, n);
			else printf("Please, input array\n");
			break;
		}
		case 3: {
			if (wasInput)
			{
				BubbleSort(B, n);
				print(B, n);
			}
		}
		case 4:{
			if (wasInput)
			{
				InsertionSort(B, n);
				print(B, n);
			}
			else printf("Please, input array\n");
			break;
		}
			  //default: printf("error\n");
			  //	break;
		}
	}
	//randArray(B, n, -10, 10);
	//print(B, n);
}