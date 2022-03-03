#include <stdio.h>
int main(void) {
    int num[5];
    int input = 0;
    
    while (!(10000 <= input && input <= 99999)) // 다섯자리 숫자가 아닐 경우 재입력
    {
        printf("다섯자리 자연수 입력 : ");
        scanf("%d", &input);
    }
    num[0] = input / 10000;
    input -= 10000 * num[0];
    
    num[1] = input / 1000;
    input -= 1000 * num[1];
    
    num[2] = input / 100;
    input -= 100 * num[2];
    
    num[3] = input / 10;
    input -= 10 * num[3];
    
    num[4] = input;
    
    for (int i = 0; i < 5; i++)
        printf("%d \n", num[i]);
    return 0;
}