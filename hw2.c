#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include <malloc.h>
#include <locale.h>


bool comparison(int A[], int B[], int size) {
	int i, j, key;
	bool flag = false;
	for (i = 0; i < size; i++) {
		key = B[i];
		for(j = 0; j < size; j++){
			if (A[j] == key) {
				flag = true;
				B[i] = size + 1;
			    flag;
				break;
			} 
		}
	}
	return flag;
}

void main() {
	int n = 2;
	int Arr[2][2] = { 1, 2, 1, 2 };
	int B[2] = { 0,0 };
	int C[2] = { 0,0 };
	int Z[2] = { 0,0 };
	int i, j;
	bool flag1 = false;
	bool flag2 = false;
	for (i = 0; i < n; i++) {
		B[i] = i + 1;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C [i] = Arr[i][j];
			Z[i] = Arr[j][i];
		}
		flag1 = (comparison(C, B, n));
		flag2 = (comparison(Z, B, n));
	}
	if (flag1 && flag2)
		printf("Yes");
	else
		printf("No");
}