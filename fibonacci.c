// print fibonacci series upto n terms
#include<stdio.h>
void main()
{
    int i, next, t1 = 0, t2 = 1, num;
    printf("Enter the no. of term: ");
    scanf("%d", &num);
    next = t1 + t2;
    printf("Fibonacci series are: %d,%d",t1,t2);
    for (i = 2; i < num; i++)
    {
        printf(",%d",next);
        t1 = t2; 
        t2 = next;
        next = t1 + t2;
    }
}