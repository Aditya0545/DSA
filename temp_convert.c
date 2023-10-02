// Farenheit to celcius 
#include<stdio.h>
void main()
{
    float f;
    printf("Enter the farenheit: ");
    scanf("%f", &f );
    float celcius = (f-32)*5/9;
    printf("%f farenheit = %f degree celcius\n",f,celcius);
}