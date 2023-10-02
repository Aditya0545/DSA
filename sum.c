// Add two numbers
#include<stdio.h>
void main()
{
    int num1,num2;
    printf("\nEnter the value of num1 and num2: \n");
    scanf("%d%d", &num1, &num2);
    int sum = num1 + num2;
    printf("\n%d + %d = %d\n",num1,num2,sum);
}