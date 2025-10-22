#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}node;

node* root=NULL;
node* create(node* root,int val)
{
    if(root==NULL)
    {
        node* newNode=(node*)malloc(sizeof(node));
        newNode->data=val;
        newNode->left=NULL;
        newNode->right=NULL;
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
        printf("\n Duplicate!\n");
    }
    return root;
}
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);

}
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);    
}
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
node* findMin(node* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
node* deleteNode(node* root,int val)
{
    if(root==NULL)
    {
        printf("\nEMPTY!\n");
        return root;
    }
    if(val<root->data)
    {
        root->left=deleteNode(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=deleteNode(root->right,val);
    }
    else
    {
        if(root->left==NULL)
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
    node* temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
node* find(node* root, int val)
{
    if (root == NULL)
        return NULL;
    if (val == root->data)
        return root;
    else if (val < root->data)
        return find(root->left, val);
    else
        return find(root->right, val);
}
int main()
{
    int ch, val;
    while (1)
    {
        printf("\n---Binary Search Tree---\n");
        printf("1. Insert\n2. Preorder\n3. Postorder\n4. Inorder\n5. Delete\n6. Find\n7. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = create(root, val);
            break;
        case 2:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = deleteNode(root, val);
            break;
        case 6:
            printf("Enter value to find: ");
            scanf("%d", &val);
            if (find(root, val))
                printf("Value %d found in the tree.\n", val);
            else
                printf("Value %d not found in the tree.\n", val);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}