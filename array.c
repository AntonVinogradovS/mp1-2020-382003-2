#include"stdio.h"
#include"locale.h"

void main() {
    int a[10] = { 1,2,3,4,4,6,2,6,10,23 };
    int b[10] = { 1,2,3,4,5,7,3,4,3,9 };
    int c[20];
    int i = 0;
    int j = 0;
    int k = 0;
    int s = 20;
    int tmp = 0;

    for (i = 0; i < 10; i++) {
        c[i] = a[i];
    }

    for (j = 10; j < 20; j++) {
        c[j] = b[j - 10];
    }

    for (i = 0; i < s; i++)
    {
        for (j = 0; j < s - i - 1; j++)
        {
            if (c[j] > c[j + 1])
            {
                tmp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = tmp;
            }
        }
    }

    for (k = 0; k < 20; k++)
        printf("%d ", c[k]);
    printf("\n");
}

