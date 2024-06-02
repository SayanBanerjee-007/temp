#include <stdio.h>
#include<stdlib.h>

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void swap(int *first, int *second)
{
    *first = *first + *second - (*second = *first);
}

// int partition(int arr[], int low, int high){
//     int pivot = arr[low];
//     int i = low + 1, j = high;
//     do
//     {
//         while (arr[i] < pivot)
//         {
//             i++;
//         }
//         while (arr[j] > pivot)
//         {
//             j--;
//         }
//         if (i < j)
//         {
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     while (i < j);
//     swap(&arr[low], &arr[j]);
//     return j;
// }

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = high+1;
    for(int j = high;j>low;j--){
        if(arr[j]>pivot){
            i--;
            swap(&arr[j],&arr[i]);
        }
    }
    i--;
    swap(&arr[low],&arr[i]);
    return i;
}

// int partition(int arr[], int low, int high){
//     int pivot = arr[high];
//     int i = low-1;
//     for(int j = low;j<high;j++){
//         if(arr[j]<pivot){
//             i++;
//             swap(&arr[j],&arr[i]);
//         }
//     }
//     i++;
//     swap(&arr[high],&arr[i]);
//     return i;
// }

void QuickSort(int arr[], int low, int high){
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        QuickSort(arr, low, partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, high);
    }
}

void main()
{
    int length,i;
    printf("Enter length of array:\n");
    scanf("%d",&length);
    int *arr = (int *)malloc(length * sizeof(int));
    printf("Enter array elements:\n");
    for(i=0; i<length; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Before sorting :\n");
    display(arr, length);

    QuickSort(arr, 0, length - 1);

    printf("\nAfter sorting :\n");
    display(arr, length);

}
