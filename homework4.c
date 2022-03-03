#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 11

int main(void)
{
	srand(time(NULL));
	int data[MAX][MAX];
	int row, col;
	int temp = 0;

	do
	{
		// 단계1 : 사용자로부터 row, col 값을 입력받는다.
		printf("row, col 입력 : ");
		scanf("%d %d", &row, &col);

		// 단계2 : row, col 값이 각각 1~10 범위 내의 값이면 다음 수행, 아니면 종료
		if (row < 1 || row > 10 || col < 1 || col > 10) {
			printf("프로그램을 종료합니다.");
			break;
		}

		// 단계3 : 해당 요소들의 값을 1~100 사이의 난수값으로 채운다.
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
			{
				data[i][j] = rand() % 100 + 1;
				temp += data[i][j];
			}
			data[i][col] = temp;	// 해당 행 가로합을 저장
			temp = 0;
		}

		// 쓰레기값 방지 초기화
		data[row][col] = 0;

		// 단계4 : 세로합, 총합을 계산하여 결과값을 그 다음 요소들에 각각 저장한다.
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++)
				temp += data[j][i];
			data[row][i] = temp;
			data[row][col] += temp;
			temp = 0;
		}

		// 단계5 : 결과를 행렬 형태로 출력한다.
		for (int i = 0; i <= row; i++) {
			for (int j = 0; j <= col; j++)
				printf("%4d", data[i][j]);
			printf("\n");
		}
	} while (1); // 단계6 : 단계1부터 다시 수행한다.
}
