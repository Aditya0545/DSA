#include<stdio.h>
#include<stdlib.h>

# define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
int item;

void insert();
void delete();
void display();

void insert()
{
    if((front==0 && rear==MAX-1) || (front==rear+1) || (front == (MAX-1) && rear==0))
    {
        printf("\nQueue is full\n");
        return;
    }
    else
    {
        if(front==-1)
            front=0;
        if(rear==(MAX-1))
            rear=0;
        else
            rear=rear+1;
        printf("\nEnter the element to be inserted: ");
        scanf("%d",&item);
        queue[rear]=item;
    }
}

void delete()
{
    if(front==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        item=queue[front];
        printf("\nDeleted element is = %d\n",item);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(front==MAX-1)
            front=0;
        else
            front++;
    }
}

void display()
{
    int i;
    if(front==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        printf("\nElements in the queue are: ");
        for(i=front;i!=rear;i=(i+1)%MAX)
            printf("%d,",queue[i]);
        printf("%d\n",queue[i]);
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("******************");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        printf("******************");
        switch(ch)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2: 
            {
                delete();
                break;
            }
            case 3:
            {       
                display();
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}