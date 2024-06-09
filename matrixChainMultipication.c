#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter the dimensions of matrices: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int **dp = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int l = 2; l < n; l++)
    {
        for (int row = 0, col = l; row < n - l; row++, col++)
        {
            dp[row][col] = INT_MAX;
            for (int k = row + 1; k < col; k++)
            {
                int temp = dp[row][k] + dp[k][col] + arr[row] * arr[k] * arr[col];
                if (temp < dp[row][col])
                {
                    dp[row][col] = temp;
                }
            }
        }
    }
    free(arr);
    printf("Minimum number of multiplications required: %d\n", dp[0][n - 1]);
    for (int i = 0; i < n; i++)
    {
        free(dp[i]);
    }
}
