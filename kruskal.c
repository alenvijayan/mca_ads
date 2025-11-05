#include<stdio.h>
#define MAX 100

int parent[MAX];

int find(int i)
{
    while (parent[i]!=i)
    {
        i=parent[i];
    }
    return i;
    
}

void unionSets(int i,int j)
{
    int a = find(i);
    int b = find(j);
    parent[a]=b;
}

void kruskal(int cost[MAX][MAX],int n)
{
    int i, j, k=1, mincost=0;
    int a, b, u, v, min;
    int t[MAX][2];

    for(i=1;i<=n;i++)
    {
        parent[i]=i;
    }

    printf("\nEdges in Minimum cost spannning Tree:\n");

    while (k<n)
    {
        min = 9999;
        a = b = -1;

        for (i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j] < min && i != j){
                    min=cost[i][j];
                a=u=i;
                b=v=j;
                }
            }
        }
        u = find(u);
        v = find(v);

        if(u != v){
            t[k][0] = a;
            t[k][1] = b;
            printf("(%d, %d) cost: %d\n",a,b,min);
            mincost+=min;
            unionSets(u,v);
            k++;
        }

        cost[a][b]=cost[b][a]=9999;
    }
    printf("\nTotal Minimum Cost: %d\n",mincost);
}
int main()
{
    int n,i,j;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("\nEnter the cost adjacency matrix(enter 9999 for no edge):\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    kruskal(cost,n);
    return 0;
}