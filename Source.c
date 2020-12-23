#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <malloc.h>
#include < string.h >

void main()
{
	char Str[128]; // не стал делать динамический, потому что, мне кажется, странно спрашивать пользователя, строку какой длины он хочет ввести
	int i, j;
	char StrTmp[1];
	gets(Str);
	int rez = atoi(Str);
	int tmp = 0;
	j = 0;
	for (i = 2; Str[i] != 0; i++) {
		StrTmp[0] = Str[i];
		tmp = atoi(StrTmp);
			if (Str[i - 1] == '+') {
				rez += tmp;
			}
			else {
				rez -= tmp;
			}

		}
	printf("%d\n", rez);

	}
