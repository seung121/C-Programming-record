#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int input = 1;
	int sum = 0;
	int size = 1;

	int *ary = (int*)malloc(sizeof(int) * 1);

	while (1) {
		printf(">>> 자연수 입력 : ");
		scanf("%d", &input);
		
		if (input == 0)		// input값이 0이라면
			break;
		sum += input;
		ary = (int*)realloc(ary, sizeof(int) * ++size);
		ary[size - 1] = input;
	}
	printf(">> 합계 : %d", sum);
	return 0;

}
