#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* randomGenerator(int n, int ll, int ul)
{
    int i,j,flag;
    int *a=(int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        flag=0;
        int r = rand() % (ul-ll+1) + ll;
        for(j=0;j<i;j++)
        {
            if(a[j]==r)
            {
                i--;
                flag++;
                break;
            }
        }
        if(flag==0)
            a[i]=r;
    }
    return a;
}

int main()
{
    int r;

    // Initialize Random
    srand(time(NULL));
    // To gennerate random number between 0 and x then rand() % (x+1)
    int x = 10;
    int y = 20;
    r = rand() % (y-x+1) + x;
    printf("The Random Number: %d\n",r);
    
    
    // The Rando Generator!
    int *b=randomGenerator(10,0,10);
    for(int i=0;i<10;i++)
        printf("%d ",b[i]);
    printf("\n");
}
