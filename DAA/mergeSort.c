#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
        // printArray(arr,r+1);
    } 
} 
  
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
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
    printf("\n----------MERGE SORT----------\n");
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
                mergeSort(a,0,input[i]-1);
                t=clock() - t;
                timeTaken = (double)t/CLOCKS_PER_SEC;
                printf("\nFor %d inputs, Merge Sort took %f seconds\n",input[i],timeTaken);
            }
        break;
        case 2:
            printf("Enter the number of inputs:");
            scanf("%d",&n);
                int *a = (int *)calloc(n, sizeof(int));
            for(j=0;j<n;j++)
                {
                    a[j]=input[i]-j;
                }
            t=clock();
            mergeSort(a,0,n-1);
            t=clock() - t;
            timeTaken = (double)t/CLOCKS_PER_SEC;
            printf("\nFor %d inputs, Merge Sort took %f seconds\n",n,timeTaken);
        break;
    }
}