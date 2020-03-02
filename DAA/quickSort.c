#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1),j;  // Index of smaller element 
  
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high);
        printArray(arr,high+1); 
    } 
} 

void main()
{
    int i,j,ch;
    clock_t t;
    double timeTaken;
    srand(time(NULL));
    // clrscr();
    int input[]={5,10,100,1000,10000,20000,30000,40000,50000,60000,70000,80000,90000,100000};
    int n = sizeof(input)/sizeof(input[0]);
    printf("\n----------QUICK SORT----------\n");
    printf("Choose:\n1.Default Input Set\n2.Custom Number of Inputs\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            for(i=0;i<n;i++)
            {
                int *a = (int *)calloc(input[i], sizeof(int));
                for(j=0;j<input[i];j++)
                {
                    a[j]=rand();
                }
                t=clock();
                quickSort(a,0,input[i]-1);
                t=clock() - t;
                timeTaken = (double)t/CLOCKS_PER_SEC;
                printf("\nFor %d inputs, Quick Sort took %f seconds\n",input[i],timeTaken);
            }
        break;
        case 2:
            printf("Enter the number of inputs:");
            scanf("%d",&n);
                int *a = (int *)calloc(n, sizeof(int));
            for(j=0;j<n;j++)
                {
                    a[j]=rand();
                }
            t=clock();
            quickSort(a,0,n-1);
            t=clock() - t;
            timeTaken = (double)t/CLOCKS_PER_SEC;
            printf("\nFor %d inputs, Quick Sort took %f seconds\n",n,timeTaken);
        break;
    }
}
