// pelindrome number
#include<stdio.h>
void main()
{
    int num, rem, sum = 0;
    printf("Enter the number: ");
    scanf("%d",  &num);
    int original = num;
    while ( num > 0)
    {
        rem = num % 10;
        sum = sum * 10 + rem;
        num = num / 10;
    }
    if (sum == original)
    {
        printf("%d is a pelindrome number\n",sum);
    }
    else{
        printf("%d is not a pelindrome number\n",sum);
    }
}