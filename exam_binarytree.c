#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}node;

node *root=NULL;

node* create()
{
    int x;
    printf("Enter value(-1 for no node):");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    printf("Enter left child of %d:",x);
    newNode->left=create();
    printf("Enter right child of %d:",x);
    newNode->right=create();
    return newNode;
}
void inorder(node* root)
{
    if(!root)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(node* root)
{
    if(!root)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root)
{
    if(!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
node* findrightmost(node* curr)
{
    while(curr->right!=NULL)
    {
        curr=curr->right;
    }
    return curr;
}
node* deleteNode(node* root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==val)
    {
        if(root->left==NULL && root->right==NULL)
        {
            printf("%d deleted\n",root->data);
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            node* temp=root->right;
            printf("%d deleted\n",root->data);
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp=root->left;
            printf("%d deleted\n",root->data);
            free(root);
            return temp;
        }
        else
        {
            node *lsubtree=root->left;
            node *rsubtree=root->right;
            node* rightmost=findrightmost(lsubtree);
            printf("%d deleted\n",root->data);
            rightmost->right=rsubtree;
            free(root);
            return lsubtree;

        }
    }
    root->left=deleteNode(root->left,val);
    root->right=deleteNode(root->right,val);
    return root;
}
int findNode(node *root,int value)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==value)
    {
        return 1;
    }
   return findNode(root->left,value) || findNode(root->right,value);

}
int main()
{
    int ch,val,result;
    while(1)
    {
        printf("\n1.Create\n2.inorder\n3.preorder\n4.postorder\n5.delete node\n6.find Node\n7.Exit\nEnter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                root=create();
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                printf("Enter value to delete:\n");
                scanf("%d",&val);
                root=deleteNode(root,val);
                break;
            case 6:
                printf("Enter value to find:");
                scanf("%d",&val);
                result=findNode(root,val);
                if(result)
                {
                    printf("%d found",val);
                }
                else
                {
                    printf("%d not found",val);
                }
                break;
            case 7:
                exit(0);
            default:
                printf("INVALID\n");
        }
    }
    return 0;
}