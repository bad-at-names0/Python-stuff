#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

int Partition(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[l]);
    return j;
}

void QuickSort(int *arr, int l, int h)
{
    if (l < h)
    {
        int j = Partition(arr, l, h);
        QuickSort(arr, l, j);
        QuickSort(arr, j + 1, h);
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // int n = 5;
    // // Selection Sort

    // // case 1
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     printf("enter the %d element\n", i + 1);
    //     scanf("%d", &arr[i]);
    // }
    // // for (int i = 0; i < n; i++)
    // // {
    // //     arr[i] = i + 1;
    // // }
    // clock_t start1, end1;
    // start1 = clock();
    // SelectionSort(arr, n);
    // end1 = clock();
    // // printf("Over a sorted list %f\n", ((double)end1 - start1) / CLOCKS_PER_SEC);
    // print(arr, n);

    // // case 2
    // // int arr1[5] = {5, 4, 3, 2, 1};
    // int arr1[n];
    // for (int i = 0; i < n; i++)
    // {
    //     printf("enter the %d element\n", i + 1);
    //     scanf("%d", &arr1[i]);
    // }
    // clock_t start2, end2;
    // start2 = clock();
    // SelectionSort(arr1, n);
    // end2 = clock();
    // // printf("Over a reverse sorted list %f\n", ((double)end2 - start2) / CLOCKS_PER_SEC);
    // print(arr1, n);

    // // case 2
    // int arr2[5];
    // for (int i = 0; i < n; i++)
    // {
    //     printf("enter the %d element\n", i + 1);
    //     scanf("%d", &arr2[i]);
    // }
    // clock_t start3, end3;
    // start3 = clock();
    // SelectionSort(arr2, n);
    // end3 = clock();
    // // printf("Over a random list %f\n", ((double)end3 - start3) / CLOCKS_PER_SEC);
    // print(arr2, n);

    // QuickSort
    printf("\nQuickSort\n");
    int n = 5;
    int arr3[5];
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element\n", i + 1);
        scanf("%d", &arr3[i]);
    }
    clock_t start4, end4;
    start4 = clock();
    QuickSort(arr3, 0, n - 1);
    end4 = clock();
    // printf("Over a sorted list %f\n", ((double)end1 - start1) / CLOCKS_PER_SEC);
    print(arr3, n);

    // case 2
    int arr4[5];
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element\n", i + 1);
        scanf("%d", &arr4[i]);
    }
    clock_t start5, end5;
    start5 = clock();
    QuickSort(arr4, 0, n - 1);
    end5 = clock();
    // printf("Over a reverse sorted list %f\n", ((double)end5 - start5) / CLOCKS_PER_SEC);
    print(arr3, n);

    // case 2
    int arr5[5];
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element\n", i + 1);
        scanf("%d", &arr5[i]);
    }
    clock_t start6, end6;
    start6 = clock();
    QuickSort(arr5, 0, n - 1);
    end6 = clock();
    // printf("Over a random list %f\n", ((double)end6 - start6) / CLOCKS_PER_SEC);
    print(arr5, n);
}