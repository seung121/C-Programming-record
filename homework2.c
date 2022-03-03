#include <stdio.h>
int func(int input)
{
    int sum = 0;
    for (int i = 1; i <= input; i++)
    {
        if (input % i == 0)
            sum += i;
    }
    printf("# %d의 약수의 합은 %d입니다.\n", input, sum);
    return 0;
}
int main(void)
{
    int input = 1;
    while (1)
    {
        printf(">>> 0 이상의 정수 입력 :");
        scanf("%d", &input);
        if (input == 0)
        {
            printf("프로그램이 종료되었습니다.\n");
            break;
        }
        func(input);
    }
    return 0;
}