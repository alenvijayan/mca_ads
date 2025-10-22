#include<stdio.h>
#include<stdlib.h>
int n;
int *q;
int front=-1;
int rear=-1;
void enq(int value)
{
    if((front==(rear+1)%n))
    {
        printf("OVERFLOW.\n");
    }
    else if (front==-1 && rear==-1)
    {
        front=rear=0;
        q[rear]=value;
        printf("%d inserted",value);
    }
    else
    {
        rear=(rear+1)%n;
        q[rear]=value;
    }
}
void dq()
{
    if(front==-1 && rear==-1)
    {
        printf("UNDERFLOW.\n");
    }
    else if (front==rear)
    {
        front=rear=-1;
        printf("%d deleted.\n",q[front]);
    }
    else
    {
        printf("%d deleted.\n",q[front]);
        front=(front+1)%n;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("EMPTY.\n");
        return;
    }
    int i=front;
    printf("Elements: ");
    while(i!=rear)
    {
        printf("%d ",q[i]);
        i=(i+1)%n;
    }
    printf("%d",q[i]);
}
void countElements()
{
    int count=0;
    if(front==-1 && rear==-1)
    {
        printf("count=0.\n");
        return;
    }
    int i=front;
    while(i!=rear)
    {
        count++;
        i=(i+1)%n;
    }
    printf("count=%d",count+1);
}
int main()
{
    int ch,value;
    printf("enter size: ");
    scanf("%d",&n);
    q=(int*)malloc(n*sizeof(int));
    while(1)
    {
        printf("\n---cqueue---\n1.enq\n2.dq\n3.display\n4.count\n5.exit\nEnter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter value: ");
            scanf("%d",&value);
            enq(value);
            break;
        case 2:
            dq();
            break;
        case 3:
            display();
            break;
        case 4:
            countElements();
            break;
        case 5:
            exit(0);
        default:
            printf("invalid choice!\n");
            break;
        }
    }
    return 0;
}
