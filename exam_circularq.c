#include<stdio.h>
#include<stdlib.h>
int front=-1;
int rear=-1;
void enq(int q[],int n,int val)
{
    if(front==(rear+1)%n)
    {
        printf("OVERFLOW\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        printf("%d inserted\n",val);
        q[rear]=val;
    }
    else
    {
        rear=(rear+1)%n;
        printf("%d inserted\n",val);
        q[rear]=val;
    }
}
void deq(int q[],int n)
{
    if(front==-1 && rear==-1)
    {
        printf("UNDERFLOW\n");
    }
    else if(front==rear)
    {
        printf("%d deleted\n",q[front]);
        front=rear=-1;
    }
    else
    {
        printf("%d deleted\n",q[front]);
        front=(front+1)%n;
    }
}
void display(int q[],int n)
{
    if(front==-1 && rear==-1)
    {
        printf("EMPTY\n");
        return;
    }
    int i=front;
    while(i!=rear)
    {
        printf("%d ",q[i]);
        i=(i+1)%n;
    }
    printf("%d",q[i]);
}
void count(int q[],int n)
{
    int count=0;
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("count=0\n");
        return;
    }
    while(i!=rear)
    {
        count++;
        i=(i+1)%n;
    }
    printf("count=%d",count+1);
}
int main()
{
    int ch,val,n;
    printf("Enter size of queue:");
    scanf("%d",&n);
    int q[n];
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Count\n5.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter value:");
                scanf("%d",&val);
                enq(q,n,val);
                break;
            case 2:
                deq(q,n);
                break;
            case 3:
                display(q,n);
                break;
            case 4:
                count(q,n);
                break;
            case 5:
                exit(0);
            default:
                printf("INVALID\n");
        }
    }
    return 0;
}