#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minimum(int arr[], int length, int minimumValue)
{
    if (length == 0)
    {
        return minimumValue;
    }
    if (arr[length] < minimumValue)
        return minimum(arr, length - 1, arr[length]);
    return minimum(arr, length - 1, minimumValue);
}
int maximum(int arr[], int length, int maximumValue)
{
    if (length == 0)
    {
        return maximumValue;
    }
    if (arr[length] > maximumValue)
        return maximum(arr, length - 1, arr[length]);
    return maximum(arr, length - 1, maximumValue);
}

void main()
{
    int size;
    printf("Enter size of array:");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    int minimumValue = minimum(arr, size - 1, INT_MAX);
    int maximumValue = maximum(arr, size - 1, INT_MIN);

    printf("Minimum value is -> %d\n", minimumValue);
    printf("Maximum value is -> %d", maximumValue);
}
