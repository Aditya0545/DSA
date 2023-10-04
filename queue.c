#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int que[MAX];
int front = -1;
int rear = -1;
int pushed_item;

void insert()
{
    if (rear == (MAX-1))
    {
        printf("\nFull\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
    printf("\nEnter the element: ");
    scanf("%d", &pushed_item);
    rear = rear + 1;
    que[rear] = pushed_item;
    }
}

void delete()
{
    if ((front == -1) || (front > rear))
    {
        printf("\nEmpty\n");
    }
    else
    {
        printf("\nDeleted element is %d", que[front]);
        front = front + 1;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("\nEmpty\n");
    }
    else
    {
        printf("\nElements are: ");
        for (int i = front; i <= rear; i++)
        {
            printf(" %d", que[i]);
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n1. insert\n2. delete\n3. display\n4. exit\nEnter Your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert();
            break;

            case 2: delete();
            break;

            case 3: display();
            break;

            case 4: exit(0);
            break;

            default: printf("\nInvalid Input\n");
            break;
        }
    }
    return 0;
}