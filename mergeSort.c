#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Merge(int arr[], int left, int mid, int right)
{
    int *tempArr = (int *)malloc((right - left + 1) * sizeof(int));
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            tempArr[k++] = arr[i++];
        }
        else if (arr[j] <= arr[i])
        {
            tempArr[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        tempArr[k++] = arr[i++];
    }
    while (j <= right)
    {
        tempArr[k++] = arr[j++];
    }
    for (int i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = tempArr[k];
    }
    free(tempArr);
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void main()
{
    int length, i;
    printf("Enter length of array:\n");
    scanf("%d", &length);
    int *arr = (int *)malloc(length * sizeof(int));
    printf("Enter array elements:\n");
    for (i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting :\n");
    display(arr, length);

    MergeSort(arr, 0, length - 1);

    printf("\nAfter sorting :\n");
    display(arr, length);
}
