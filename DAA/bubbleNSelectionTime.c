#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// void clrscr()
// {
//     system("@cls||clear");
// }
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
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void bubbleSort(int a[], int n)
{
    int temp, i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(&a[j],&a[j+1]);
        }
    }
}
int main()
{
    int i,j;
    clock_t t;
    double timeTaken;
    srand(time(NULL));
    // clrscr();
    int input[]={5,10,100,1000,10000,20000,30000,40000,50000,60000,70000,80000,90000,100000};
    int n = sizeof(input)/sizeof(input[0]);
    printf("\n----------BUBBLE SORT----------\n");
    for(i=0;i<n;i++)
    {
        int *a = (int *)calloc(input[i], sizeof(int));
        for(j=0;j<input[i];j++)
        {
            a[j]=rand();
        }
        t=clock();
        bubbleSort(a,input[i]);
        t=clock() - t;
        timeTaken = (double)t/CLOCKS_PER_SEC;
        printf("\nFor %d inputs, Bubble Sort took %f seconds\n",input[i],timeTaken);
    }
    printf("\n----------SELECTION SORT----------\n");
    for (i = 0; i < n; i++)
    {
        int *a = (int *)calloc(input[i], sizeof(int));
        for (j = 0; j < input[i]; j++)
        {
            a[j] = rand();
        }
        t = clock();
        selectionSort(a, input[i]);
        t = clock() - t;
        timeTaken = (double)t / CLOCKS_PER_SEC;
        printf("\nFor %d inputs, Selection Sort took %f seconds\n", input[i], timeTaken);
    }
}