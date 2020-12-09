#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include <memory.h>
#include <locale.h>
void randArray(int Arr[], int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		Arr[i] = rand() % (b - a) + a;
}

void notRandArray(int Arr[], int n)
{
	int i;
	printf("Введите элементы массива ");
		for (i = 0; i < n; i++) {
			scanf_s("%d ", &Arr[i]);
		}
}
void print(int B[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
	printf("\n");
}

void linearSearch(int Arr[], int size)
{
	int i, key;
	printf("Введите искомый элемент\n ");
	scanf_s("%d", & key);
	
	for (i = 0; i < size; i++){
		if (Arr[i] == key) {
		printf(" В массиве существует искомый элемент ");
		break;
		}
		else {
			if (i == size) {
			printf(" В массиве нет искомого элемента");
			}
		}
	}
		
}

void binarysearch(int Arr[], int n)
{
	int low, high, middle, key;
	low = 0;
	high = n - 1;
	bool flag = false;
	printf("Введите искомый элемент\n ");
	scanf_s("%d", &key);
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (key < Arr[middle])
			high = middle - 1;
		else if (key > Arr[middle])
			low = middle + 1;
		else {
			flag = true;
			break;
		}
	}
	if(flag)
	printf(" В массиве существует искомый элемент ");
	else
	printf(" В массиве не существует искомого элемента ");
}

void BubbleSort(int Arr[], int n)
{
	int i, j;
	int tmp;
	bool flag = false;
	for (i = 0; i < n; i++) {
		if ((i != 0) && (flag == false)){
			return;
		}
	
		for (j = 0; j < n - i - 1; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;
				flag = true;
			}
		}
		if (!flag)
		flag = false;
		 
	}
}

void InsertionSort(int a[], int n) {
	int mid = n / 2; 
	if (n % 2 == 1)
		mid++;
	int h = 1; 
	int* c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   
		int j = mid; 
		int k = 0;  
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{
				if (a[i] < a[j])
				{
					c[k] = a[i];
					i++; k++;
				}
				else {
					c[k] = a[j];
					j++; k++;
				}
			}
			while (i < step)
			{
				c[k] = a[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j < n))
			{ 
				c[k] = a[j];
				j++; k++;
			}
			step = step + h; 
		}
		h = h * 2;
		for (i = 0; i < n; i++)
			a[i] = c[i];
	}
} 

void Merge(int Arr[], int n)
{
	int* B; 
	B = (int*)malloc(n * sizeof(int));
	int i; 
	int j;
	int c; 
	for (i = 0; i < n; i++) {
		B[i] = 0;
	}
	for (i = 0; i < 10; i++) {
		B[Arr[i]] = B[Arr[i]] + 1;
	}
	for (c = 0; c < 10; c++) {
		for (j = 0; j < B[c]; j++)
			printf("%d ", c);
	}
	 
	
}


void QS(int Arr[], int first, int last)
{ 
	int i = first;
	int j = last;
	int x = Arr[(first + last) / 2];
	int tmp = 0;
	do {
		while (Arr[i] < x) i++;
		while (Arr[j] > x) j--;

		if (i <= j) {
			if (Arr[i] > Arr[j]) {
				tmp = Arr[j];
				Arr[j] = Arr[i];
				Arr[i] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		QS(Arr, i, last);
	if (first < j)
		QS(Arr, first, j);
}

void menu()
{
	printf("\nMENU:\n");
	printf("1. Автоматический способ заполнения массива\n");
	printf("2. Ручной способ заполнения массива\n");
	printf("3. Печать массива\n");
	printf("4. Сортировка пузырьком\n");
	printf("5. Сортировка вставками\n");
	printf("6. Сортировка подсчётом\n");
	printf("7. Сортировка Хоара\n");
	printf("8. Линейный поиск элемента\n");
	printf("9. Бинарный поиск элемента(только в отсортированном массиве)\n");
	printf("0. Exit\n");
}


void main()
{
		setlocale(LC_ALL, "Rus");
	int sizeArr = 0;
	int last, firste;
	printf("Введите размер массива\n");
	scanf_s("%d", &sizeArr);
	printf("Введите границы массива\n");
	scanf_s("%d %d", &firste, &last);
	int* Arr; 
	int t = 10;
	int l = 0;
	int r = 0;
	Arr = (int*)malloc(sizeArr * sizeof(int));
	bool wasInput = false;
	bool sort = false;
	printf("start\n");
	srand(1000);

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1: {
			randArray(Arr, sizeArr, firste, last);
			wasInput = true;
			break;
		}
		case 2: {
			notRandArray(Arr, sizeArr);
			wasInput = true;
			break;
		}
		case 3: {
			if (wasInput)
				print(Arr, sizeArr);
			else printf("Please, input array\n");
			break;
		}
		case 4: {
			if (wasInput)
			{
				BubbleSort(Arr, sizeArr);
				print(Arr, sizeArr);
				sort = true;
			}
			else 
				printf("Please, input array\n");
			break;
		}
		case 5: {
			if (wasInput)
			{
				Merge(Arr, sizeArr);
				print(Arr, sizeArr);
				sort = true;
			}
			else printf("Please, input array\n");
			break;
		}
		case 6: {
			if (wasInput)
			{
				InsertionSort(Arr, sizeArr);
				sort = true;
			}
			else printf("Please, input array\n");
			break;
		}
		case 7: {
			if (wasInput)
			{
				QS(Arr, firste, last);
				print(Arr, sizeArr);
				sort = true;
			}
			else printf("Please, input array\n");
			break;
		}
		case 8: {
			linearSearch(Arr, sizeArr);
			break;
		}
		case 9: {
			if (sort)
				binarysearch(Arr, sizeArr);
			else printf("Пожалуйста, отсортируйте массив");
			break;
		}
		}

	}
}   