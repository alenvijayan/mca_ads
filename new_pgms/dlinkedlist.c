#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* head=NULL;
node* tail=NULL;

node* createNode(int value)
{
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insertAtBeginning(int value)
{
    node* newNode=createNode(value);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    printf("%d inserted at beginning\n",value);

}
void insertAtEnd(int value)
{
    node* newNode=createNode(value);
    if(tail==NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else
    {
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
    printf("%d inserted at end\n",value);

}
void deleteFromBeginning()
{
    if(head==NULL)
    {
        printf("UNDERFLOW.\n");
        return;
    }
    node* temp=head;
    printf("%d deleted from beginning\n",temp->data);
    head=head->next;
    free(temp);
    if(head!=NULL)
    {
        head->prev=NULL;
    }
    else
    {
        tail=NULL;
    }
}
void deleteFromEnd()
{
    if(tail==NULL)
    {
        printf("UNDERFLOW.\n");
        return;
    }
    node* temp=tail;
    printf("%d deleted from end\n",temp->data);
    tail=tail->prev;
    free(temp);
    if(tail!=NULL)
    {
        tail->next=NULL;
    }
    else
    {
        head=NULL;
    }
}
void displayFromBeginning()
{
    if(head==NULL)
    {
        printf("list empty.\n");
        return;
    }
    node* temp=head;
    printf("Elements from beginning: ");
    while(temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void displayFromEnd()
{
    if(tail==NULL)
    {
        printf("list empty.\n");
        return;
    }
    node* temp=tail;
    printf("Elements from end: ");
    while(temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
}
void countElements()
{
    int count=0;
    node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("count=%d",count);

}
int main()
{
    int value,ch;
    while(1)
    {
        printf("\n---Doubly Linked List---\n1.Insert at beginning\n2.Insert at end\n3.Delete from beginning\n4.Delete from end\n5.Display from beginning\n6.Display from end\n7.Count\n8.exit\nEnter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d",&value);
            insertAtBeginning(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d",&value);
            insertAtEnd(value);
            break;
        case 3:
            deleteFromBeginning();
            break;
        case 4:
            deleteFromEnd();
            break;
        case 5:
            displayFromBeginning();
            break;
        case 6:
            displayFromEnd();
            break;
        case 7:
            countElements();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid Choice.\n");
            break;
        }
    }
    return 0;
}