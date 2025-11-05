#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *left,*right;
    int data;
}node;

node* root=NULL;

node* create(node* root, int val)
{
    if(root==NULL)
    {
        node* newNode=(node*)malloc(sizeof(node));
        newNode->left=newNode->right=NULL;
        return newNode;
    }
    if(val<root->data)
    {
        root->left=create(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=create(root->right,val);
    }
    else
    {
        printf("\nDuplicate!\n");
    }
}
node* deleteNode(node* root,int val)
{
    if(root==NULL)
    {
        printf("\nEmpty\n");
        return NULL;
    }
    if(val<root->data)
    {
        root->left=deleteNode(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=deleteNode(root->right,val);
    }

}
