// factorial
#include<stdio.h>
int fact(int n)
{
    int val = 1;
    for(int i = n; i >= 1; i--)
    {
        val = val * i;
    }
    return val;
}
void main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    int factorial = fact(n);
    printf("\nFactorial of %d is %d\n",n,factorial);
}