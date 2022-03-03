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
		// �ܰ�1 : ����ڷκ��� row, col ���� �Է¹޴´�.
		printf("row, col �Է� : ");
		scanf("%d %d", &row, &col);

		// �ܰ�2 : row, col ���� ���� 1~10 ���� ���� ���̸� ���� ����, �ƴϸ� ����
		if (row < 1 || row > 10 || col < 1 || col > 10) {
			printf("���α׷��� �����մϴ�.");
			break;
		}

		// �ܰ�3 : �ش� ��ҵ��� ���� 1~100 ������ ���������� ä���.
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
			{
				data[i][j] = rand() % 100 + 1;
				temp += data[i][j];
			}
			data[i][col] = temp;	// �ش� �� �������� ����
			temp = 0;
		}

		// �����Ⱚ ���� �ʱ�ȭ
		data[row][col] = 0;

		// �ܰ�4 : ������, ������ ����Ͽ� ������� �� ���� ��ҵ鿡 ���� �����Ѵ�.
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++)
				temp += data[j][i];
			data[row][i] = temp;
			data[row][col] += temp;
			temp = 0;
		}

		// �ܰ�5 : ����� ��� ���·� ����Ѵ�.
		for (int i = 0; i <= row; i++) {
			for (int j = 0; j <= col; j++)
				printf("%4d", data[i][j]);
			printf("\n");
		}
	} while (1); // �ܰ�6 : �ܰ�1���� �ٽ� �����Ѵ�.
}
