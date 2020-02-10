/* NOTE: This program is amazing in its clean OUTPUT but it is quite long and 
therefore it is not reccomended to be written in the Lab manual, nor to be "learnt" for exams.
Things like callbacks and array returns are beyond the scope of DAA.
But I made it for fun :P 
And for quick plotting
*/
// void clrscr()
// {
//     system("@cls||clear");
// }

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int a[],int n)
{
    printf("Sorted Array:\t");
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}
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
  
int* selectionSort(int arr[], int n) 
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
    return arr;
} 
int* bubbleSort(int a[], int n)
{
	int temp,i,j;
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
    return a;
}
double timed(int* (*p)(int[], int),int n)
{
    clock_t start, end;
    double timeTaken;
    

    int *a=(int*)calloc(n,sizeof(int));
    a=randomGenerator(n,1,n); //Randomly generate an array with distinct elements

    start = clock();
    int *x= (*p)(a,n); //Callback to passed function, returns ref to sorted array
    end = clock();

    timeTaken = ((double)end - start) / CLOCKS_PER_SEC;
    
    // printArray(x,n); //Comment this line out if you dont want to print out the sorted elements
    return timeTaken;
}
int main()
{
    int algoCh,inputCh,n;
        int input[] = {5, 10, 100, 1000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    printf("TIME ANALYSIS\nChoose your Algorithm:\n1.Bubble Sort\n2.Selection Sort\n");
    scanf("%d",&algoCh);
    printf("Choose:\n1.Default Input Set\n2.Custom Input\n");
    scanf("%d",&inputCh);
    switch(inputCh)
    {
        case 1:
            n = sizeof(input) / sizeof(input[0]);
            for(int i=0;i<n;i++)
                printf("\nFor %d inputs, Bubble Sort took %f seconds\n", input[i], timed(bubbleSort,input[i]));
            break;
        case 2:
            switch (algoCh)
            {
            case 1:
                printf("Enter the number of elements:");
                scanf("%d", &n);
                printf("Please Wait...\n");
                printf("The Bubble sort took %f seconds to execute \n", timed(bubbleSort, n));
                break;
            case 2:
                printf("Enter the number of elements:");
                scanf("%d", &n);
                printf("Please Wait...\n");
                printf("The Selection Sort took %f seconds to execute \n", timed(selectionSort, n));
                break;
            default:
                printf("Incorrect Choice\n");
                break;
            }
            break;
    }
}
