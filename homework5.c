#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1차원 배열의 요소들의 값을 min ~max 사이의 값들로 채운다.min은 max보다 작은 것으로 가정한다.
void Init(int *ary, int count, int min, int max) {
	for (int i = 0; i < count; i++) {
		ary[i] = rand() % (max - min + 1) + min;
	}
}

// 1차원 배열의 요소들 중 가장 큰 값을 반환한다.
int Max(int *ary, int count) {
	int max = 0;
	for (int i = 0; i < count; i++)
	{
		if (ary[i] > max)
			max = ary[i];
	}
	return max;
}

// value가 처음으로 나오는 곳의 index를 반환한다. value가 없다면 ?1을 반환한다.
int Find(int *ary, int count, int value) {
	for (int i = 0; i < count; i++) {
		if (value == ary[i])
			return i;
	}
	return -1;
}

// ary의 값들을 역순으로 재정렬한다.
void Reverse(int *ary, int count) {
	int temp = 0;
	int half = count / 2;

	for (int i = 0; i < count / 2; i++)
	{
		temp = ary[i];
		ary[i] = ary[count - 1 - i];
		ary[count - 1 - i] = temp;
	}
}

// ary의 값들을 출력한다.
void Print(int *ary, int count) {
	for (int i = 0; i < count; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
}

int main(void)
{
	srand(time(NULL));
	int ary1[10];

	Init(ary1, 10, 1, 10);
	Print(ary1, 10);
	printf("최대값 : %d\n", Max(ary1, 10));
	printf("5는 어디에 : %d\n", Find(ary1, 10, 5));

	Reverse(ary1, 10);
	Print(ary1, 10);
}


