#include<stdio.h>
#include<stdlib.h>
int front=-1;
int rear=-1;
void enq(int ar[],int val,int n)
{
    if(front==(rear+1)%n) 
    {
        printf("OVERFLOW\n");
    }  
    else if (front==-1 && rear==-1)
    {
        front=rear=0;
        ar[rear]=val;
    }
    else
    {
        rear=(rear+1)%n;
        ar[rear]=val;
    }
}
void dq(int ar[],int n)
{
    if (front==-1 && rear==-1)
    {
        printf("UNDERDLOW\n");
    }
    else if (front==rear)
    {
        printf("%d deleted",ar[front]);
        front=rear=-1;
    }
    else
    {
        printf("%d deleted",ar[front]);
        front=(front+1)%n;
    }
    
    
}
void display(int ar[],int n)
{
    if (front==-1 && rear==-1)
    {
        printf("Empty\n");
        return;
    }
    int i = front;
    while(i!=rear)
    {
        printf("%d ",ar[i]);
        i=(i+1)%n;
    }
    printf("%d ",ar[i]);
}
void count(int n)
{
    int count=0;
    if(front==-1 && rear==-1)
    {
        printf("count=0.\n");
        return;
    }
    int i = front;
    while(i!=rear)
    {
        count++;
        i=(i+1)%n;
    }
    printf("count=%d\n",count+1);

}
int main()
{
    int val,ch,n;
    printf("Enter Size of the cqueue:");
    scanf("%d",&n);
    int ar[n];
    while(1)
    {
        printf("1.enq\n2.dq\n3.display\n4.count\n5.exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Value to insert at rear:");
                scanf("%d",&val);
                enq(ar,val,n);
                break;
            case 2:
                dq(ar,n);
                break;
            case 3:
                display(ar,n);
                break;
            case 4:
                count(n);
                break;
            case 5:
                exit(0);
            default:
                printf("invalid\n");
            

        }
    }
    return 0;
}