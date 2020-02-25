#include<stdio.h>
#include<math.h>
int max(int,int);
void warshall(int p[10][10],int n) 
{
    int i,j,k;
    for (k=1;k<=n;k++)
    {
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            p[i][j]=max(p[i][j],p[i][k]&&p[k][j]);
        }
    }
}
int max(int a,int b) 
{
    if(a>b)
        return(a); 
    else
        return(b);
}
void main() {
    int n,e,u,v,i,j,p[10][10]= {0};
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the number of edges:");
    scanf("%d",&e);
    for (i=1;i<=e;i++) 
    {
        printf("\nEnter the end vertices of edge %d:",i);
        scanf("%d%d",&u,&v);
        p[u][v]=1;
    }
    printf("\nMatrix of input data: \n");
    for (i=1;i<=n;i++) 
    {
        for (j=1;j<=n;j++)
            printf("%d\t",p[i][j]);
        printf("\n");
    }
    warshall(p,n);
    printf("\nTransitive closure: \n");
    for (i=1;i<=n;i++) 
    {
        for (j=1;j<=n;j++)
            printf("%d\t",p[i][j]);
        printf("\n");
    }
}