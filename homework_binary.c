#include <stdio.h>

// 텍스트기반 입출력

/*
int main(void) 
{
	int input, temp, eof;
	FILE *fp = fopen("data.txt", "wt");
	printf(">>> 입력할 값의 수 : ");
	scanf("%d", &input);
	for (int i = 0; i < input; i++) {
		temp = rand() % 100 + 1;
		fprintf(fp, "%d \n", temp);
	}
	fclose(fp);

	FILE *fpr = fopen("data.txt", "r");
	
	while (1)
	{
		eof = fscanf(fpr, "%d", &temp);
		if (eof == EOF)
			break;
		printf("%d \n", temp);
	}
	fclose(fpr);
}
*/


// 바이너리 기반 입출력
int main(void)
{
	int input, temp, ch;

	FILE *fp = fopen("data.txt", "wb");
	printf(">>> 입력할 값의 수 : ");
	scanf("%d", &input);
	for (int i = 0; i < input; i++) {
		temp = rand() % 100 + 1;
		fwrite(&temp, sizeof(int),1,fp);
	}
	fclose(fp);

	FILE *fpr = fopen("data.txt", "rb");
	
	while ((ch = fgetc(fpr)) != EOF) {
		if (ch == 0)
			continue;
		printf("%d ", ch);
	}

	fclose(fpr);
}