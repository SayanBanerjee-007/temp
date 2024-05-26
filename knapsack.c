#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int n, int *weights, int *values) {
    int **K = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        K[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    int result = K[n][W];

    for (int i = 0; i <= n; i++) {
        free(K[i]);
    }
    free(K);

    return result;
}

void printItems(int *weights, int *values, int n) {
    printf("Item\tWeight\tValue\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, weights[i], values[i]);
    }
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int *weights = (int *)malloc(n * sizeof(int));
    int *values = (int *)malloc(n * sizeof(int));

    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("ITEM : %d\n", i + 1);
        printf("\tWeight: ");
        scanf("%d", &weights[i]);
        printf("\tValue: ");
        scanf("%d", &values[i]);
    }

    printf("\nInput Items:\n");
    printItems(weights, values, n);

    int maxValue = knapsack(W, n, weights, values);
    printf("\nMaximum value in Knapsack = %d\n", maxValue);

    free(weights);
    free(values);

    return 0;
}
