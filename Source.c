#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

void main() {
	int A[2][3] = { 2,4,6,3,7,2 };
	int i, j;
	int B[2] = { 0,0 }; // заменим 2 столбец в массиве A
	int n = 2;
	for (i = 0; i < 2; i++) {
		if (i != 0)
			printf("\n");
		for (j = 0; j < 3; j++) {
			printf("%d ", A[i][j]);
		}
	}

	for (i = 0; i < 2; i++) {
		A[i][n - 1] = B[i];
	}

	printf("\n\n");
	for (i = 0; i < 2; i++) {
		if (i != 0)
			printf("\n");
		for (j = 0; j < 3; j++) {
			printf("%d ", A[i][j]);
		}
	}

	
}