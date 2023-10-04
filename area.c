// Programming to calculate area of a circle and circumference of a circle
#include<stdio.h>
void main()
{
    float area, radius, circumference;
    printf("Enter the radius of circle: ");
    scanf("%f", &radius);                     
    circumference = 2 * 3.14 * radius;
    area = 3.14 * radius * radius;
    printf("Circumference of a circle is %f\n",circumference);
    printf("Area of a Circle is %f\n",area);
}