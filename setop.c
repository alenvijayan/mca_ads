#include<stdio.h>
#include<stdlib.h>
#define size 8

void inputSet(int *set)
{
    int x;
    printf("Enter elements between 0 and %d(-1 to stop):",size-1);
    while(1)
    {
        scanf("%d",&x);
        if(x==-1)
            break;
        if(x>=0 && x<size)
            *set|=(1<<x);
        else
            printf("INVALID IP\n");
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
    printf("Enter Set A:\n");
    inputSet(&setA);
    printf("Set A=");
    displaySet(setA);

    printf("Enter Set B:\n");
    inputSet(&setB);
    printf("Set B=");
    displaySet(setB);

    while(1)
    {
        printf("\n1.u\n2.i\n3.A_B\n4.B_A\n5.Display\n6.exit\nENter ch:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                result=setA | setB;
                printf("U=");
                displaySet(result);
                break;
            case 2:
                result=setA & setB;
                printf("I=");
                displaySet(result);
                break;
            case 3:
                result=setA & ~setB;
                printf("A_B=");
                displaySet(result);
                break;
            case 4:
                result=setB & ~setA;
                printf("B_A=");
                displaySet(result);
                break;
            case 5:
                displaySet(setA);
                displaySet(setB);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid");

        }
    }
    return 0;
}