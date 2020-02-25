// Read: https://brilliant.org/wiki/floyd-warshall-algorithm/
#include<stdio.h>
#include<math.h>
int max(int,int);
void floyd(int p[10][10],int n) 
{
    int i,j,k;
    for (k=1;k<=n;k++)
    {
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
                p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
        }
    }
}
int min(int a,int b) 
{
    if(a<b)
        return(a); 
    return(b);
}
void main() {
    int n,e,u,v,i,j,p[10][10]= {0};
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the number of edges:");
    scanf("%d",&e);
    printf("\nEnter the adjacency Matrix(-1 for no path):");
    for (i=1;i<=n;i++) 
    {
        for(j=1;j<=n;j++)
            scanf("%d",&p[i][j]);
    }
    printf("\nMatrix of input data: \n");
    for (i=1;i<=n;i++) 
    {
        for (j=1;j<=n;j++)
            printf("%d\t",p[i][j]);
        printf("\n");
    }
    floyd(p,n);
    printf("\nTransitive : \n");
    for (i=1;i<=n;i++) 
    {
        for (j=1;j<=n;j++)
            printf("%d\t",p[i][j]);
        printf("\n");
    }
}