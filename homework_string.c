/* �ּ� �ڵ尡 ����ǰ� ���� ��
#include <stdio.h>

int StrLen(const char *str);                        // ���ڿ��� ���� ��ȯ : strlen �Լ��� ��� ����
void StrCpy(char *str1, const char *str2);    // str2 ���ڿ��� str1 ���ڿ��� ���� : strcpy �Լ��� ��� ����

int main(void)
{
	char str1[30] = "Donald Trump";
	char str2[30] = "Joe Biden";

	printf("str1 : %s, ���� : %d \n", str1, StrLen(str1));
	printf("str2 : %s, ���� : %d \n", str2, StrLen(str2));

	StrCpy(str1, str2);

	printf("str1 : %s, ���� : %d \n", str1, StrLen(str1));
	printf("str2 : %s, ���� : %d \n", str2, StrLen(str2));

	return 0;
}

/* ��  main �Լ��� ���� ����� ������ ����
str1 : Donald Trump, ���� : 12
str2 : Joe Biden, ���� : 9
str1 : Joe Biden, ���� : 9
str2 : Joe Biden, ���� : 9
*/


#include <stdio.h>

int StrLen(const char *str);                        // ���ڿ��� ���� ��ȯ : strlen �Լ��� ��� ����
void StrCpy(char *str1, const char *str2);    // str2 ���ڿ��� str1 ���ڿ��� ���� : strcpy �Լ��� ��� ����

int main(void)
{
	char str1[30] = "Donald Trump";
	char str2[30] = "Joe Biden";

	printf("str1 : %s, ���� : %d \n", str1, StrLen(str1));
	printf("str2 : %s, ���� : %d \n", str2, StrLen(str2));

	StrCpy(str1, str2);

	printf("str1 : %s, ���� : %d \n", str1, StrLen(str1));
	printf("str2 : %s, ���� : %d \n", str2, StrLen(str2));

	return 0;
}

int StrLen(const char *str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

void StrCpy(char *str1, const char *str2) {
	int i = 0;
	while (str2[i] != '\0') {
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}



/* ��  main �Լ��� ���� ����� ������ ����
str1 : Donald Trump, ���� : 12
str2 : Joe Biden, ���� : 9
str1 : Joe Biden, ���� : 9
str2 : Joe Biden, ���� : 9
*/