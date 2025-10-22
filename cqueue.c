#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front=-1,rear=-1;
void enqueue(int value)
{
    if((rear+1)%N==front)
    {
        printf("OVERFLOW.\n");
    }
    else if (front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=value;
        printf("%d inserted",value);
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=value;
        printf("%d inserted",value);
    }
    
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("UNDERFLOW.\n");
    }
    else if(front==rear)
    {
        printf("%d deleted",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("%d deleted",queue[front]);
        front=(front+1)%N;
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
    while(i!=rear)
    {
        printf("%d ",queue[i]);
        i=(i+1)%N;
    }
    printf("%d\n",queue[i]);
    

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
        i=(i+1)%N;
    }
    printf("count=%d\n",count+1);


}
int main()
{
    int value,ch;
    while(1)
    {
        printf("\n---Circular Queue---\n1.Enqueue\n2.Dequeue\n3.Display\n4.Count\n5.exit\nEnter Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter value: ");
            scanf("%d",&value);
            enqueue(value);       
            break;
        case 2:
            dequeue();       
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
            printf("Invalid");
            break;
        }
    }
    return 0;
}
