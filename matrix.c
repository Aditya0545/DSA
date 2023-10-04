// Matrix Multiplication

#include<stdio.h>
void main()
{
    int a[2][2], b[2][2], result[2][2];
    printf("\nEnter the elements of 1st matrix: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("Enter a%d%d: ", i+1,j+1);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nEnter the elements of 2nd matrix: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("Enter b%d%d: ", i+1,j+1);
            scanf("%d", &b[i][j]);
        }
    }
    
    // calculation 
    for(int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }

    printf("\nMultiplication of two matrix is: \n");
    for(int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\t", result[i][j]);
            if (j == 1)
            {
                printf("\n");
            }
        }
    }
}