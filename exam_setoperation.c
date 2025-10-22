#include<stdio.h>
#include<stdlib.h>
#define size 8

void inputSet(int *set)
{
    int x;
    printf("Enter elements between 0 an %d(-1 to stop):",size-1);
    while(1)
    {
        scanf("%d",&x);
        if(x==-1)
            break;
        if(x>=0 && x<size)
            *set|=(1<<x);
        else
            printf("invalid input.\n");
    }

}
void displaySet(int set)
{
    printf("{");
    for(int i=0;i<size;i++)
    {
        if(set & (1<<i))
            printf("%d ",i);
    }
    printf("}\n");
}

int main()
{
    int setA=0,setB=0,result,ch;
    printf("Enter set A:\n");
    inputSet(&setA);
    printf("Set A:");
    displaySet(setA);

    printf("Enter Set B:\n");
    inputSet(&setB);
    printf("Set B = ");
    displaySet(setB);

    while (1)
    {
        printf("\n1.Union\n2.Intersection\n3.Diff(A-B)\n4.Diff(B-A)\n5.Display\n6.exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                result=setA | setB;
                printf("Union=");
                displaySet(result);
                break;
            case 2:
                result=setA & setB;
                printf("Intersection=");
                displaySet(result);
                break;
            case 3:
                result=setA & ~setB;
                printf("A-B=");
                displaySet(result);
                break;
            case 4:
                result=setB & ~setA;
                printf("B-A=");
                displaySet(result);
                break;
            case 5:
                printf("Set A:\n");
                displaySet(setA);
                printf("Set B:\n");
                displaySet(setB);
                break;
            case 6:
                exit(0);
            default:
                printf("INVALID\n");

        }
    }
    return 0;
    
}