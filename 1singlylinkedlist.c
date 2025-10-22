#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *head=NULL;
node* createNode(int val)
{
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
void insertNodeB(int val)
{
    node *newNode=createNode(val);
    newNode->next=head;  
    head=newNode;
        
}
void insertNodeE(int val)
{
    node *newNode=createNode(val);
    if(head==NULL) 
        head=newNode;
    else
    {
        node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
    
        
}
void deleteNode(int val)
{
    if(head==NULL)
    {
        printf("list empty!\n");
        return;
    }
    node *temp=head;
    node *prev=NULL;
    if(head->data==val)
    {
        head=head->next;
        free(temp);
        printf("%d deleted\n",val);
        return;
    }
    while(temp!=NULL && temp->data!=val)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("%d not found in list.\n",val);
        return;
    }
    prev->next=temp->next;
    free(temp);
    printf("%d deleted\n",val);

}
void display()
{
    node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("list empty\n");
        return;
    }
        
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }  
    printf("NULL\n");
}
void count()
{
    node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("count=%d\n",count);
        

}
int main()
{
    int val,ch;
    while(1)
    {
        printf("1.InsertBeginning\n2.End\n3.delete\n4.display\n5.count\n6.exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Value to insert at beginning:");
                scanf("%d",&val);
                insertNodeB(val);
                break;
            case 2:
                printf("Enter Value to insert at end:");
                scanf("%d",&val);
                insertNodeE(val);
                break;
            case 3:
                printf("Enter value to delete:");
                scanf("%d",&val);
                deleteNode(val);
                break;
            case 4:
                display();
                break;
            case 5:
                count();
                break;
            case 6:
                exit(0);
            default:
                printf("invalid\n");
            

        }
    }
    return 0;
}