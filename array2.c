#include "stdio.h"
#include "locale.h"
#include "math.h"
#include <locale.h>

void main(){
	setlocale(LC_ALL, "Rus");
	int i;
	int size;
	int r = 0;
	printf("Введите количество точек\n");
	scanf_s("%d", &size);
	int* A = (int*)malloc(sizeof(int) * (size));
	printf("Введите координаты\n");
	for (i = 0; i < 2*size; i++)
	{
		scanf_s("%d", &A[i]);
	}
	int min = sqrt(A[0]*A[0] + A[1]*A[1]);
	int max = sqrt(A[0]*A[0] + A[1]*A[1]);
	setlocale(LC_ALL, "Rus");
	for (i = 2; i < 4; i = i + 2)
	{
		r = sqrt(A[i]* A[i] + A[i + 1] * A[i + 1]);                        
		if (r > max) {
			max = r;
		}
		else {
			if (r < min) {
				min = r;
			}
		}
	}
	printf("Максимальный радиус=%d\n", max);
	printf("Минимальный радиус=%d\n", min);
}