#include<stdio.h>
#include<stdlib.h>


int Asize,Bsize,Rsize;

void display(int set[],int n)
{
    printf("{");
    for(int i=0;i<n;i++)
    {
        if(set[i]==1)
        {
            printf("%d",i);
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
   
    
    int ch,n,element;
    printf("UNIVERSAL SET U={0,1,2,...}\n");

    printf("Enter number of elements in set A: ");
    scanf("%d",&Asize);
    int A[Asize];
    for(int i=0;i<Asize;i++)
    {
        scanf("%d",&element);
        if(element>=0)
        {
            A[element]=1;
        }
    }
    printf("Enter number of elements in set B: ");
    scanf("%d",&Bsize);
    int B[Bsize];
    for(int i=0;i<Bsize;i++)
    {
        scanf("%d",&element);
        if(element>=0)
        {
            B[element]=1;
        }
    }
    if(Asize>=Bsize)
    {
        Rsize=Asize;
    }
    else
    {
        Rsize=Bsize;
    }
    int result[Rsize];
    printf("\nSet A= ");
    display(A,Asize);
    printf("Set B= ");
    display(B,Bsize);

    while(1)
    {
        printf("\n---Set operations---\n1.Union\n2.Intersection\n3.Diff(A-B)\n4.Diff(B-A)\n5.exit\nEnter ur Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                unionSet(A,B,result,Rsize);
                printf("A u B:");
                display(result,Asize);
                break;
            case 2:
                interSet(A,B,result,Rsize);
                printf("A n B:");
                display(result,Bsize);
                break;
            case 3:
                diffSet(A,B,result,Rsize);
                printf("A - B:");
                display(result,Rsize);
                break;
            case 4:
                diffSet(B,A,result,Rsize);
                printf("B - A:");
                display(result,Rsize);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid");
        }
    }
    return 0;

}
