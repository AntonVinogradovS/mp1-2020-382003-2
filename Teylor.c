#include "stdio.h"
#include "math.h"
#include <locale.h>
double PI = 3.14159265358979323846;

double Arccos(double x, double eps, int*i)
{
	int k = 1;
	double x1 = x, x2, n = 1.0 * (k) / (k + 1), N = x * x * x, sum = x;
	x2 = N * n / (k + 2);

	while (fabs(x2 - x1) >= eps)
	{
		if ((k + 1) / 2 >= (*i)) {  
			break; }
		sum += x2;
		(k) += 2;
		n *= 1.0 * (k) / (k + 1);
		N *= x * x;
		x1 = x2;
		x2 = N * n / (k + 2);
	}
	if (((k + 1) / 2) <= (*i)) (*i) = (k + 1) / 2;
	else (*i) -= (k + 1) / 2;

	return PI*0.5 - sum;
} 

double Csc(double x, double eps, int* count)
{
	double sum = 0; 
	double z = 1;
	int n = 0;
	while (fabs(z) > eps)
	{
		sum += z;
		if (n >= (*count))  
			break; 
		n++;
		z *= -x * x / (2.0 * n - 1.0) / (2.0 * n);
	}
	if ((n != 1) && (n <= (*count)))
		(*count) = n;
	else 
		(*count) -= (n);
	if (n == 1) 
		(*count) = n;

	return sum;
}

void Input(double* x, int* y, double* eps) {
	printf("\nВведите значение X:");
	scanf_s("%lf", x);
	printf("\nВведите кол-во членов:");
	scanf_s("%d", y);
	printf("\nВведите погрешность:");
	scanf_s("%lf", eps);
}

void menu()
{
	printf("Выберите функцию для разложения по Тейлору:\n");
	printf("1. Arccos(x) \n");
	printf("2. Csc(x)\n");
	printf("0. Выход\n\n");
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	double x = 0;
	double eps = 0;
	int t = 3;
	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			double x;
			double rez = 0;    
			double eps; 
			int count;   
			Input(&x, &count, &eps);
			rez = Arccos(x, eps, &count);
			printf("Моё значение %10.8f       Кол-во членов %d       Arccos(x)  %10.8f  \n", rez, count, acos(x));
			/*printf("%14.13f         %5d          %16.13f    \n", rez, count, acos(x));*/
			printf("\nРазница: %10.8f\n", (rez - acos(x)));
			break;
		}
		case 2:
		{
			double x;   
			double rez = 0;      
			double eps;
			int count;  
			Input(&x, &count, &eps);
			rez = Csc(x, eps, &count);
			printf("Моё значение %10.8f       Кол-во членов %d        Csc(x) %10.8f         \n",1 / rez, count, 1 / cos(x));
			/*printf("%10.8f         %5d          %14.8f    \n", 1/rez, count, 1/cos(x));*/
			printf("\nРазница: %10.8f\n", (1 / rez - 1 / cos(x)));
			break; 
		}
		}
	}
	}

