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
int timed(int* (*p) (int a,int b,int c))
{
    clock_t start, end;
    double timeTaken;
    start = clock();
    int *x = (*p)(a,b,c);
    end = clock();
    timeTaken = ((double)end - start) / CLOCKS_PER_SEC;
    return timeTaken;
}

int main()
{
    clock_t start,end;
    double timeTaken;

    // Initialize Random
    srand(time(NULL));

    // To gennerate random number between 0 and x then rand() % (x+1)

    // int x = 10;
    // int y = 20;
    // int r = rand() % (y-x+1) + x;
    // printf("The Random Number: %d\n",r);
    
    
    // The Rando Generator!
    // start=clock();
    // int *b=randomGenerator(10,0,10);
    // end=clock();
    // timeTaken=((double)end-start)/CLOCKS_PER_SEC;
    // for(int i=0;i<10;i++)
    //     printf("%d ",b[i]);
    // printf("\n");
    // printf("The function took %f seconds to execute \n", timeTaken);



    // int* (*ptr)(int,int,int)=&randomGenerator;
    timeTaken = timed(randomGenerator(10,0,10));
}
