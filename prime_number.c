// Check prime number
#include<stdio.h>
void main()
{
    int i,num,count = 0; // count helps to count if block execution 
    printf("\nEnter the number to check it is prime or not: ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        printf("\n%d is a prime number\n",num);
    }
    else
    {
        printf("\n%d is not a prime number\n",num);
    }
}