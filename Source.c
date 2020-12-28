#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include <locale.h>
#include "windows.h"
void randArray(int* Arr, int n)
{
	int a, b;
	printf("Введите границы массива\n");
	scanf_s("%d %d", &a, &b);
	int i;
	for (i = 0; i < n; i++)
		Arr[i] = rand() % (b - a ) + a;
}

void notRandArray(int* Arr, int n)
{
	int i;
	printf("Введите элементы массива\n");
	for (i = 0; i < n; i++) 
		scanf_s("%d ", &Arr[i]);
} 

void print(int* B, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
	printf("\n");
}

void linearSearch(int* Arr, int size)
{
	int i, key;
	printf("Введите искомый элемент\n ");
	scanf_s("%d", &key);

	for (i = 0; i < size; i++) {
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


void binarysearch(int* Arr, int n)
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
	if (flag)
		printf(" В массиве существует искомый элемент ");
	else
		printf(" В массиве не существует искомого элемента ");
}

void BubbleSort(int* Arr, int n, int x[], int y[])
{
	int x1 = 0;
	int y1 = 0;

	int i, j;
	int tmp;
	bool flag = false;
	for (i = 0; i < n; i++) {
		if ((i != 0) && (flag == false)) {
			return;
		}

		for (j = 0; j < n - i - 1; j++)
		{
			x1++;
			if (Arr[j] > Arr[j + 1])
			{
				x1++;
				y1++;
				tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;
				flag = true;
			}
		}
		if (!flag)
			flag = false;
	}
	x[0] = x1;
	y[0] = y1;
}

void InsertionSort(int* Arr, int n, int x[], int y[]) {
	int key;
	int i, j;
	int x1 = 0;
	int y1 = 0;
	for (i = 1; i < n; i++) {
		key = Arr[i];
		y1++;
		j = i;
		while (j > 0 && Arr[j - 1] > key) {
			x1++;
			y1++;
			Arr[j] = Arr[j - 1];
			j--;
		}
		Arr[j] = key;
		y1++;
	}
	x[1] = x1;
	y[1] = y1;
}


void CountSort(int* a, int n, int x[], int y[])
{
	int x1, y1;
	x1 = 0;
	y1 = 0;
	
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			x[2]++;
			y[2]++;
			max = a[i];
		}
		if (a[i] < min) {
			x[2]++;
			y[2]++;
			min = a[i];
		}
	}
	int z = max + 1 - min;
	int* c = 0;
	c =(int*)malloc(sizeof(int)*(z));
	int i;
	for (i = 0; i < z; i++) {
		c[i] = 0;
	}
	for (i = 0; i < n; i++) {
		c[a[i] - min] = c[a[i] - min] + 1;
		y[2]++;
	}
	i = 0;
	for (int j = min; j < max + 1; j++) {
		x[2]++;
		while (c[j - min] != 0) {
			x[2]++;
			y[2]++;
			a[i] = j;
			c[j - min]--;
			i++;
		}
	} 
}




void QS(int* Arr, int begin, int end, int* x, int* y)     
{
	/*int i = first, j = last;
	double tmp, x = Arr[(first + last) / 2];

	do {
		while (Arr[i] < x)
			i++;
		while (Arr[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		QS(Arr, i, last);
	if (first < j)
		QS(Arr, first, j);*/
	
	int l = begin, r = end;
	int v = Arr[(l + r) / 2];
	int tmp = 0;
	do 
	{
		(*x)++;
		while (Arr[l] < v) {
			l++;
			(*x)++;
		}
		while (Arr[r] > v) {
			r--;
			(*x)++;
		}
			
		if (l <= r)
		{
			(*x)++;
		     tmp = Arr[l];
			Arr[l] = Arr[r];
			Arr[r] = tmp;
			(*y)++;
			l++;
				r--;
		}
	} while (l <= r);
	if (begin < r)
		QS(Arr, begin, r, x, y);
	if (l < end) {
		QS(Arr, l, end, x, y);
	}
} 

void merge(int* a, int num, int* b, int x[], int y[])
{
	int rght, rend;
	int i, j, m;
	int x1 = 0;
	int y1 = 0;
	for (int k = 1; k < num; k *= 2)
	{
		for (int left = 0; left + k < num; left += k * 2)
		{
			rght = left + k;
			rend = rght + k;
			if (rend > num)
				rend = num;
			x1++;
			m = left; 
			i = left; 
			j = rght;
			while (i < rght && j < rend)
			{
				if (a[i] <= a[j])
				{
					b[m] = a[i]; 
					i++;
					x1++;
					y1++;
				}
				else
				{
					b[m] = a[j]; 
					j++;
					y1++;
				}
				m++;
			}
			while (i < rght)
			{
				b[m] = a[i];
				i++; 
				m++;
				y1++;
			}
			while (j < rend)
			{
				b[m] = a[j];
				j++; 
				m++;
				y1++;
			}
			for (m = left; m < rend; m++)
			{
				a[m] = b[m];
				y1++;
			}
		}
	}
	x[3] = x1;
	y[3] = y1;
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
	printf("7. Сортировка слиянием\n");
	printf("8. Сортировка Хоара\n");
	printf("9. Линейный поиск элемента\n");
	printf("10. Бинарный поиск элемента(только в отсортированном массиве)\n");
	printf("0. Exit\n");
}
copy(int* A, int* B, int size) {
	int i;
	for (i = 0; i < size; i++) {
		B[i] = A[i];
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int sizeArr = 0;
	printf("Введите размер массива\n");
	scanf_s("%d", &sizeArr);
	int* Arr;
	int t = 100;
	int l = 0;
	int r = 0;
	Arr = (int*)malloc(sizeArr * sizeof(int));
	bool wasInput = false;
	bool sort = false;
	printf("start\n");
	srand(2000000);
	double timeSort[5];
	int comp[5];
	int swapSort[5];
	for (int i = 0; i < 5; i++) {
		timeSort[i] = 0;
		comp[i] = 0; 
		swapSort[i] = 0;
		
} 
	int counterComp = 0;
	int counterSwap = 0;
	double time = 0;
	LARGE_INTEGER freq;
	LARGE_INTEGER  start, finish; 
	QueryPerformanceFrequency(&freq); // 1 раз на программу
	while (t != 0) 
	{
		menu(); 
		scanf_s("%d", &t); 
		switch (t)
		{
		case 1: {
			randArray(Arr, sizeArr);
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
				int* Arr4;
				Arr4 = (int*)malloc(sizeArr * sizeof(int));
				copy(Arr, Arr4, sizeArr);
			
	
			
				QueryPerformanceCounter(&start);

				BubbleSort(Arr4, sizeArr, comp, swapSort );
				
				QueryPerformanceCounter(&finish); // конец замера
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				timeSort[0] = time;
				printf("\n% f\n", time);
				time = 0;
				//print(Arr4, sizeArr);
				free(Arr4);
				sort = true;
			}
			else
				printf("Please, input array\n");
			break;
		}
		case 5: {
			if (wasInput)
			{
				int* Arr5;
				Arr5 = (int*)malloc(sizeArr * sizeof(int));
				copy(Arr, Arr5, sizeArr);
				

				
				QueryPerformanceCounter(&start);
				InsertionSort(Arr5, sizeArr, comp, swapSort);
				QueryPerformanceCounter(&finish); // конец замера
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				timeSort[1] = time;
				//printf("\n% f\n", time);
				time = 0;
  			print(Arr5, sizeArr);
			free(Arr5);
				sort = true;
			}
			else printf("Please, input array\n");
			break;
		}
		case 6: {
			if (wasInput)
			{
				int* Arr6;
				Arr6 = (int*)malloc(sizeArr * sizeof(int));
				copy(Arr, Arr6, sizeArr);
				

				
				QueryPerformanceCounter(&start);

				CountSort(Arr6, sizeArr, comp, swapSort);

				QueryPerformanceCounter(&finish); // конец замера
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				timeSort[2] = time;
				printf("\n% f\n", time);
				time = 0;
				//print(Arr6, sizeArr);
				free(Arr6);
				sort = true; 
			}
			else printf("Please, input array\n");
			break;
		}
		case 7: {
			if (wasInput)
			{
				int* Arr7;
				Arr7 = (int*)malloc(sizeArr * sizeof(int));
				copy(Arr, Arr7, sizeArr);
				
				
				int* c;
			 c = (int*)malloc(sizeArr * sizeof(int));

			
				QueryPerformanceCounter(&start);

				merge(Arr7, sizeArr, c, comp, swapSort);

				QueryPerformanceCounter(&finish); // конец замера
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				timeSort[3] = time;
				printf("\n% f\n", time);
				time = 0;
				print(Arr7, sizeArr);
				sort = true;
			}
			else printf("Please, input array\n");
			break;
		}
		case 8: {
			if (wasInput)
			{
				int* Arr8;
				Arr8 = (int*)malloc(sizeArr * sizeof(int));
				copy(Arr, Arr8, sizeArr);

				
				QueryPerformanceCounter(&start);
				QS(Arr8, 0, sizeArr - 1, &counterComp, &counterSwap);           
				QueryPerformanceCounter(&finish); // конец замера
				comp[4] = counterComp;
				swapSort[4] = counterSwap;
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				timeSort[4] = time;
				printf("\n% f\n", time);
				time = 0;
				//print(Arr8, sizeArr);
				free(Arr8);
				sort = true;
			}
			else printf("Please, input array\n"); 
			break;
		}
		case 9: {
			linearSearch(Arr, sizeArr);
			break;
		}
		case 10: {
			if (sort)
				binarysearch(Arr, sizeArr);
			else printf("Пожалуйста, отсортируйте массив");
			break;
		}
		}

	}
	printf("Посмотрите, сколько времени выполнялись сортировки\n");
	printf("Сортировка пузырьком    Сортировка вставками    Сортировка подсчётом    Сортировка слиянием    Быстрая сортировка\n");
	int i;
	for (i = 0; i < 5; i++)
		printf("%f                  ", timeSort[i]);
	printf("\n");

	printf("\nПосмотрите, сколько было сравнений\n");
	printf("Сортировка пузырьком    Сортировка вставками    Сортировка подсчётом    Сортировка слиянием    Быстрая сортировка\n");
	for (i = 0; i < 5; i++)
		printf("%d                  ", comp[i]);
	printf("\n");

	printf("\nПосмотрите, сколько перестановок\n");
	printf("Сортировка пузырьком    Сортировка вставками    Сортировка подсчётом    Сортировка слиянием    Быстрая сортировка\n");
	for (i = 0; i < 5; i++)
		printf("%d                  ", swapSort[i]);
	printf("\n");
	
}