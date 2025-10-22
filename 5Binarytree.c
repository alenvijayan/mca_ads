#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}node;
node *root=NULL;
int foundflag=0;     
node* create()
{
    int val;
    printf("Enter value(-1 for no node): ");
    scanf("%d",&val);
    if(val==-1)
    {
        return NULL;
    }
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=val;
    printf("Enter left child of %d: ",val);
    newNode->left=create();
    printf("Enter right child of %d: ",val);
    newNode->right=create(); 
    return newNode;
}
node* findrightmost(node* curr)
{
    while (curr->right!=NULL)
    {
        curr=curr->right;
    }
    return curr;
    
}
node* deleteNode(node *root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==val)
    {
        if(root->left==NULL && root->right==NULL)
        {
            printf("%d deleted",root->data);
            free(root);
            return NULL;
        }
        else if (root->right==NULL)
        {
            node* temp=root->left;
            printf("%d deleted",root->data);
            free(root);
            return temp;
        }
        else if (root->left==NULL)
        {
            node* temp=root->right;
            printf("%d deleted",root->data);
            free(root);
            return temp;
        }
        else
        {
            node* lsubtree=root->left;
            node* rsubtree=root->right;
            node* rightmost=findrightmost(lsubtree);
            rightmost->right=rsubtree;
            printf("%d deleted",root->data);
            free(root);
            return lsubtree;
        }
                
    }
    root->left=deleteNode(root->left,val);
    root->right=deleteNode(root->right,val);
    return root;
}

void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void find(node *root,int val)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==val)
    {
        printf("%d found in the tree\n",val); 
        foundflag=1;
        return;
    }
    find(root->left,val);
    find(root->right,val);

}
int main()
{
    int ch,val;
    while(1)
    {
        printf("\n---Binary Tree---\n1.create\n2.Delete\n3.inorder\n4.preorder\n5.postorder\n6.Find\n7.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            root=create();
            break;
        case 2:
            printf("Enter Value: ");
            scanf("%d",&val);
            root=deleteNode(root,val);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            printf("Enter value to find:");
            scanf("%d",&val);
            find(root,val);
            if(!foundflag)
                printf("Not found");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid!\n");
            break;
        }
    }
    
    return 0;
}