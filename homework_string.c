/* 주석 코드가 실행되게 만들 것
#include <stdio.h>

int StrLen(const char *str);                        // 문자열의 길이 반환 : strlen 함수와 기능 동일
void StrCpy(char *str1, const char *str2);    // str2 문자열을 str1 문자열로 복사 : strcpy 함수와 기능 동일

int main(void)
{
	char str1[30] = "Donald Trump";
	char str2[30] = "Joe Biden";

	printf("str1 : %s, 길이 : %d \n", str1, StrLen(str1));
	printf("str2 : %s, 길이 : %d \n", str2, StrLen(str2));

	StrCpy(str1, str2);

	printf("str1 : %s, 길이 : %d \n", str1, StrLen(str1));
	printf("str2 : %s, 길이 : %d \n", str2, StrLen(str2));

	return 0;
}

/* 위  main 함수의 실행 결과는 다음과 같음
str1 : Donald Trump, 길이 : 12
str2 : Joe Biden, 길이 : 9
str1 : Joe Biden, 길이 : 9
str2 : Joe Biden, 길이 : 9
*/


#include <stdio.h>

int StrLen(const char *str);                        // 문자열의 길이 반환 : strlen 함수와 기능 동일
void StrCpy(char *str1, const char *str2);    // str2 문자열을 str1 문자열로 복사 : strcpy 함수와 기능 동일

int main(void)
{
	char str1[30] = "Donald Trump";
	char str2[30] = "Joe Biden";

	printf("str1 : %s, 길이 : %d \n", str1, StrLen(str1));
	printf("str2 : %s, 길이 : %d \n", str2, StrLen(str2));

	StrCpy(str1, str2);

	printf("str1 : %s, 길이 : %d \n", str1, StrLen(str1));
	printf("str2 : %s, 길이 : %d \n", str2, StrLen(str2));

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



/* 위  main 함수의 실행 결과는 다음과 같음
str1 : Donald Trump, 길이 : 12
str2 : Joe Biden, 길이 : 9
str1 : Joe Biden, 길이 : 9
str2 : Joe Biden, 길이 : 9
*/