// Swap two numbers
#include<stdio.h>
void main()
{
    int num1,num2;
    printf("Enter the two number for swapping\n");
    scanf("%d%d",&num1, &num2);
    int temp = num1;
    num1 = num2;
    num2 = temp;
    printf("num1 = %d\nnum2 = %d\n",num1,num2);
}