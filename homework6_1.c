#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size;
	int *arr;
	int sum = 0;

	printf(">>> 몇 개의 정수를 저장하시겠습니까? : ");
	scanf("%d", &size);

	arr = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
	}
	printf(">>> 배열 요소의 값들 : ");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
		sum += arr[i];
	}

	printf("\n>>> 배열 요소의 합 : %d ", sum);
	free(arr);

	return 0;
}
