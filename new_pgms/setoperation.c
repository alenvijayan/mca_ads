#include<stdio.h>
#include<stdlib.h>
#define size 8

void display(int set[],int n)
{
    printf("{");
    for(int i=0;i<n;i++)
    {
        if(set[i]==1)
        {
            printf("%d ",i);
        }
    }
    printf("}\n");
}
void unionSet(int a[],int b[],int result[],int n)
{
    for(int i=0;i<n;i++)
    {
        result[i]=a[i]|b[i];
    }

}
void interSet(int a[],int b[],int result[],int n)
{
    for(int i=0;i<n;i++)
    {
        result[i]=a[i]&b[i];
    }
}
void diffSet(int a[],int b[],int result[],int n)
{
    for(int i=0;i<n;i++)
    {
        result[i]=a[i]&(~b[i]);
    }
}
int main()
{
    int A[size]={0},B[size]={0};
    int result[size];
    int ch,n,element;
    printf("UNIVERSAL SET U={0,1,2,...%d}\n",size-1);

    printf("Enter number of elements in set A: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&element);
        if(element>=0 && element<size)
        {
            A[element]=1;
        }
    }
    printf("Enter number of elements in set B: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&element);
        if(element>=0 && element<size)
        {
            B[element]=1;
        }
    }
    printf("\nSet A= ");
    display(A,size);
    printf("Set B= ");
    display(B,size);

    while(1)
    {
        printf("\n---Set operations---\n1.Union\n2.Intersection\n3.Diff(A-B)\n4.Diff(B-A)\n5.exit\nEnter ur Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                unionSet(A,B,result,size);
                printf("A u B:");
                display(result,size);
                break;
            case 2:
                interSet(A,B,result,size);
                printf("A n B:");
                display(result,size);
                break;
            case 3:
                diffSet(A,B,result,size);
                printf("A - B:");
                display(result,size);
                break;
            case 4:
                diffSet(B,A,result,size);
                printf("B - A:");
                display(result,size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid");
        }
    }
    return 0;

}
