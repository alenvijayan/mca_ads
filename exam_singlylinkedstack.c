#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *top=NULL;
node* createNode(int val)
{
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
void push(int val)
{
    node* newNode=createNode(val);
    if(top==NULL)
    {
        top=newNode;
        printf("%d inserted\n",val);
        return;
    }
    newNode->next=top;
    top=newNode;
    printf("%d inserted\n",val);
}
void pop()
{
    if(top==NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    node* temp=top;
    printf("%d popped\n",temp->data);
    top=top->next;
    free(temp);
}
void display()
{
    if(top==NULL)
    {
        printf("EMPTY\n");
        return;
    }
    node* temp=top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void count()
{
    int count=0;
    node* temp=top;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("count=%d",count);
}
int main()
{
    int val,ch;
    while(1)
    {
        printf("1.Push\n2.Pop\n3.display\n4.count\n5.exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Value to insert at top:");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                count();
                break;
            case 5:
                exit(0);
            default:
                printf("invalid\n");
            

        }
    }
    return 0;
}