 // Switch Program for stack 
#include<stdio.h>
#define MAX 5
int stack_arr[MAX];
int pushed_item;
int top = -1;
int main()
{
    int ch;
    while(1)
    {
    printf("\nEnter Your Choice- 1:disp, 2:push, 3:pop, 4:pop all, 5:exit, 6:push all  :  ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nSwitch 1 is processing");
        disp();
        break;
    case 2:
        printf("\nSwitch 2 is processing");
        push();
        break;
    case 3:
        printf("\nSwitch 3 is processing");
        pop();
        break;
    case 5:
        printf("\nSwitch 5 is processing");
        exit(0);
        break;
    case 4:
        printf("\nSwitch 4 is processing");
        pop_all();
        break;
    case 6:
        printf("\nSwitch 6 is processing");
        push_all();
        break;
    default:
        printf("Wrong choise");
        break;
    }
}
}
void disp()
{
    if(top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        int i;
        printf("\nElements are: ");
        for(i = top; i>= 0; i--)
        {
            printf("%d,", stack_arr[i]);
        }
    }
}
void push()
{
    if(top == (MAX-1))
    {
        printf("\nStack is overflow");
    }
    else
    {
        printf("\nEnter the element: ");
        scanf("%d", &pushed_item);
        top = top + 1;
        stack_arr[top] = pushed_item;
    }
}
void pop()
{
    if(top == -1)
    {
        printf("\nStack is underflow");
    }
    else
    {
        printf("\nDeleted an element is %d\n",stack_arr[top]);
        top = top-1;
    }
}
void pop_all()
{
    for(int i=MAX; i>=0; i--)
    pop();
    disp();
}
void push_all()
{
    if(top == (MAX)-1)
    {
        printf("Stack is overflow");
    }
    else
    {
        int i;
        for(i=0; i<MAX; i++)
        {
        printf("\nEnter the element: ");
        scanf("%d", &pushed_item);
        top = top + 1;
        stack_arr[top] = pushed_item;
        }
    disp();
    }
}
