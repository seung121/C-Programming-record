#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1���� �迭�� ��ҵ��� ���� min ~max ������ ����� ä���.min�� max���� ���� ������ �����Ѵ�.
void Init(int *ary, int count, int min, int max) {
	for (int i = 0; i < count; i++) {
		ary[i] = rand() % (max - min + 1) + min;
	}
}

// 1���� �迭�� ��ҵ� �� ���� ū ���� ��ȯ�Ѵ�.
int Max(int *ary, int count) {
	int max = 0;
	for (int i = 0; i < count; i++)
	{
		if (ary[i] > max)
			max = ary[i];
	}
	return max;
}

// value�� ó������ ������ ���� index�� ��ȯ�Ѵ�. value�� ���ٸ� ?1�� ��ȯ�Ѵ�.
int Find(int *ary, int count, int value) {
	for (int i = 0; i < count; i++) {
		if (value == ary[i])
			return i;
	}
	return -1;
}

// ary�� ������ �������� �������Ѵ�.
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

// ary�� ������ ����Ѵ�.
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
	printf("�ִ밪 : %d\n", Max(ary1, 10));
	printf("5�� ��� : %d\n", Find(ary1, 10, 5));

	Reverse(ary1, 10);
	Print(ary1, 10);
}


