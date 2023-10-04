#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int dq[MAX];
int pushed_item;

int right = -1;
int left = -1;

void insert_left()
{
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("\nFull\n");
    }
    else if ((left == -1) && (right = -1))
    {
        left = 0;
        right = 0;
        printf("\nEnter the number: ");
        scanf("%d", &pushed_item);
        dq[left] = pushed_item;
    }
    else if (left == 0)
    {
        left = MAX - 1;
        printf("\nEnter the element: ");
        scanf("%d", &pushed_item);
        dq[left] = pushed_item;
    }
    else
    {
        left = left - 1;
        printf("\nEnter the element: ");
        scanf("%d", &pushed_item);
        dq[left] = pushed_item;
    }
}

void insert_right()
{
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("\nFull\n");
    }
    else if ((left == -1) && (right == -1))
    {
        right = 0;
        printf("\nEnter the element: ");
        scanf("%d", &pushed_item);
        dq[right] = pushed_item;
    }
    else if (right == MAX - 1)
    {
        right = 0;
        printf("\nEnter the element: ");
        scanf("%d", &pushed_item);
        dq[right] = pushed_item;
    }
    else
    {
        right = right + 1;
        printf("\nEnter the element: ");
        scanf("%d", &pushed_item);
        dq[right] = pushed_item;
    }
}

void delete_left()
{
    if ((left == -1) && (right == -1))
    {
        printf("\nEmpty\n");
    }
    else if (left == right)
    {
        printf("\nDeleted element is %d", dq[left]);
        left = -1;
        right = -1;
    }
    else if (left == MAX - 1)
    {
        printf("\nDeleted element is %d", dq[left]);
        left = 0;
    }
    else
    {
        printf("\nDeleted element is %d", dq[left]);
        left = left + 1;
    }
}

void delete_right()
{
    if ((left == -1) && (right == -1))
    {
        printf("\nEmpty\n");
    }
    else if (left == right)
    {
        printf("\nDeleted element is %d", dq[right]);
        left = -1;
        right = -1;
    }
    else if (right == 0)
    {
        printf("\nDeleted element is %d", dq[right]);
        right  = MAX - 1;
    }
    else 
    {
        printf("\nDeleted element is %d", dq[right]);
        right = right - 1;
    }
}

void display()
{
    int i = left;
    printf("\nElements are: ");
    while(i != right)
    {
        printf(" %d", dq[i]);
        i = (i+1) % MAX;
    }
    printf(" %d", dq[right]);
    
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1. insert using left\n2. insert using right\n3. delete using left\n4. delete using right\n5. display\n6. exit\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert_left();
            break;

            case 2: insert_right();
            break;

            case 3: delete_left();
            break;

            case 4: delete_right();
            break;

            case 5: display();
            break;

            case 6: exit(0);
            break;

            default: printf("\nInvalid Input\n");
        }
    }
    return 0;
}