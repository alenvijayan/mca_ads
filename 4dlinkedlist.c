#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next,*prev;
}node;
node *head=NULL;
node *createNode(int val)
{
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insertB(int val)
{
    node *newNode=createNode(val);
    if (head==NULL)
    {
        head=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    
}
void insertE(int val)
{
    node *newNode=createNode(val);
    if (head==NULL)
    {
        head=newNode;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void deleteB()
{
    if (head==NULL)
    {
        printf("EMPTY\n");
        return;
    }
    node *temp=head;
    if (head->next==NULL)   // only one node
    {
        printf("%d deleted\n",temp->data);
        head=NULL;         // or head=head->next
        free(temp);
        return;
    }
    
    head=head->next;
    head->prev=NULL;
    printf("%d deleted\n",temp->data);
    free(temp);
}
void deleteE()
{
    if (head==NULL)
    {
        printf("EMPTY\n");
        return;
    }
    node *temp=head;
    if (head->next==NULL)   // only one node
    {
        printf("%d deleted\n",temp->data);
        head=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    (temp->prev)->next=NULL;
    printf("%d deleted\n",temp->data);
    free(temp);

}
void displayB()
{
    if (head==NULL)
    {
        printf("EMPTY\n");
        return;
    }
    node *temp=head;
    printf("NULL<->");
    while(temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");

}
void displayE()
{
    if (head==NULL)
    {
        printf("EMPTY\n");
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)//to go to the last node.
        temp=temp->next;// at the last iteration temp points tothe last node
    printf("NULL<->");
    while(temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->prev;   //previous
    }
    printf("NULL\n");
}
void count()
{
    int count=0;
    node *temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("Count=%d\n",count);

}
int main()
{
    int value,ch;
    while(1)
    {
        printf("1.insert beginning\n2.insert end\n3.delete beginning\n4.delete end\n5.display beginning\n6.display end\n7.count\n8.exit\nEnter Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter value: ");
            scanf("%d",&value);
            insertB(value);       
            break;
        case 2:
            printf("enter value: ");
            scanf("%d",&value);
            insertE(value);       
            break;
        case 3:
            deleteB();
            break;
        case 4:
            deleteE();
            break;
        case 5:
            displayB();
            break;
        case 6:
            displayE();
            break;
        case 7:
            count();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid");
            break;
        }
    }
    return 0;
}