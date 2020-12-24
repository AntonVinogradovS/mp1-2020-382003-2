#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <malloc.h>
#include < string.h >
#include <Windows.h>
#include <stdbool.h>
#include <assert.h>
//#include <wchar.h>
//#include <wctype.h>

int Pos(char key) {
	char Rus[] = "абвгдеежзийклмнопрстуфхцчшщъыьэюя";
	int i = 0;
	char Key = tolower(key);
	while (Rus[i] != Key)
	{
		i++;
	}
	return i;
}
bool Tab(char key) {
	char tab[] = "?.,! ";
	bool flag = true;
	int i;
	for (i = 0; i < 5; i++) {
		if (tab[i] == key) {
			flag = false;
			break;
		}
	}
	return flag;
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	char Str[128];
    char Rus[] = "абвгдеежзийклмнопрстуфхцчшщъыьэюя";
	char tab[] = "?.,! ";
	int k = 0;
	int i;
	int pos = 0;
	int tmp = 0;
	for (i = 0; i < 128; i++) {
		Str[i] = "a";
	}
	printf("Введите строку\n");
	gets(Str);
	printf("Введите цифру, на которую следует сдвинуть каждую букву\n");
	scanf_s("%d", &k);
	 
	for (i = 0; Str[i] != 0; i++) {
		if (Tab(Str[i]) == true) {
			if (Str[i] != 'ё') {
				pos = Pos(Str[i]);
				if ((pos + k) > 32) {
					pos = pos + k - 33;
				}
				else {
					pos += k;
				}
				if (Str[i] != Rus[pos - 1]) {
					Str[i] = toupper(Rus[pos]);
				}
				else {
					Str[i] = Rus[pos];
				}
			}
		}
	}
	printf("Зашифрованная строка\n");
	puts(Str);
}
