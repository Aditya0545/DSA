// size of int, float, double, char
#include<stdio.h>
void main()
{
    int num1 = 5;
    float num2 = 4.5;
    char ch = 'G';
    double num3 = 5643456544;
    printf("Size of int is %d bytes\n",sizeof(int));
    printf("Size of float is %d bytes\n",sizeof(float));
    printf("Size of char is %d bytes\n",sizeof(char));
    printf("Size of double is %d bytes\n",sizeof(double));
}