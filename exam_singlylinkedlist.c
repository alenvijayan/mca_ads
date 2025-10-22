#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void insertNodeB(int val)
{
    node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void insertNodeE(int val)
{
    node *newNode = createNode(val);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteNode(int val)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    node *temp = head;
    node *prev = NULL;
    if (head->data == val)
    {
        printf("%d deleted", head->data);
        head = head->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("%d not found in list\n",val);
        return;
    }
    prev->next = temp->next;
    printf("%d deleted\n", temp->data);
    free(temp);
}
void display()
{

    if (head == NULL)
    {
        printf("EMPTY\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void count()
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("count=%d\n", count);
}
int main()
{
    int ch, val;
    while (1)
    {
        printf("\n1.insertb\n2.inserte\n3.delete\n4.display\n5.count\n6.exit\nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to insert at beginning:");
            scanf("%d", &val);
            insertNodeB(val);
            break;
        case 2:
            printf("Enter value to insert at end:");
            scanf("%d", &val);
            insertNodeE(val);
            break;
        case 3:
            printf("Enter value to delete:");
            scanf("%d", &val);
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
            break;
        default:
            printf("INVALID\n");
        }
    }
    return 0;
}