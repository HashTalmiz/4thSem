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
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
    printf("Sorted Array:\t");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
    printf("\n");
} 
void bubbleSort(int a[], int n)
{
	int temp,i,j;
	// int n = sizeof(a)/sizeof(int);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Sorted Array:\t");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
    printf("\n");
}
void main()
{
    int i,n;
    clock_t start, end;
    double timeTaken;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int *a=(int*)calloc(n,sizeof(int));
    a=randomGenerator(n,0,100000);
    
    // int *a=(int*)calloc(1000000,sizeof(int));
    // for(i=2;i<=100000;i*=5)
    // {
        // a=randomGenerator(i,0,1000000);
        start=clock();
        selectionSort(a,n);
        // bubbleSort(a,n);
        end=clock();
        timeTaken=((double)end-start)/CLOCKS_PER_SEC;
        printf("The function took %f seconds to execute \n", timeTaken);

    // }

}
