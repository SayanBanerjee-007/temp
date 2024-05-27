# Dijkstra's Algorithm

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int V) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

void dijkstra(int **graph, int V, int src) {
    int *dist = (int *)malloc(V * sizeof(int));
    int *sptSet = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);
    free(dist);
    free(sptSet);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    printf("\nShortest paths from vertex %d:\n", src);
    dijkstra(graph, V, src);

    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

```

## output

```
Enter the number of vertices: 5
Enter the adjacency matrix (use 0 for no edge):
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0
Enter the source vertex: 0

Shortest paths from vertex 0:
Vertex  Distance from Source
0       0
1       10
2       50
3       30
4       60
```

# Job Sequencing with Deadlines

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;
}

void printJobs(Job *jobs, int n) {
    printf("ID\tDeadline\tProfit\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
}

void jobSequencing(Job *jobs, int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    int *timeSlots = (int *)malloc(maxDeadline * sizeof(int));
    for (int i = 0; i < maxDeadline; i++) {
        timeSlots[i] = -1;
    }

    int totalProfit = 0;
    printf("\nSelected Jobs:\nID\tDeadline\tProfit\n");
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (timeSlots[j] == -1) {
                timeSlots[j] = i;
                totalProfit += jobs[i].profit;
                printf("%d\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
                break;
            }
        }
    }

    printf("\nTotal Profit: %d\n", totalProfit);

    free(timeSlots);
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job *jobs = (Job *)malloc(n * sizeof(Job));

    printf("Enter job details (ID Deadline Profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    free(jobs);
    return 0;
}
```

## output

```
Enter the number of jobs: 4
Enter job details (ID Deadline Profit):
Job 1: 1 4 20
Job 2: 2 1 10
Job 3: 3 1 40
Job 4: 4 1 30

Selected Jobs:
ID      Deadline Profit
3       1       40
1       4       20

Total Profit: 60

```

# Knapsack Problem

```c
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
```

## output

```
Enter the number of items: 3
Enter the capacity of the knapsack: 50
Enter the weights and values of the items:
ITEM : 1
        Weight: 10
        Value: 60
ITEM : 2
        Weight: 20
        Value: 100
ITEM : 3
        Weight: 30
        Value: 120

Input Items:
Item    Weight  Value
1       10      60
2       20      100
3       30      120

Maximum value in Knapsack = 220
```

# Kruskal's Algorithm

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int V, E;
    Edge *edges;
} Graph;

typedef struct {
    int parent;
    int rank;
} Subset;

int find(Subset subsets[], int i);
void Union(Subset subsets[], int x, int y);
int compareEdges(const void *a, const void *b);
void KruskalMST(Graph *graph);
void printEdges(Edge edges[], int E);

Graph *createGraph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge *)malloc(graph->E * sizeof(Edge));
    return graph;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

void printEdges(Edge edges[], int E) {
    printf("Edge\tWeight\n");
    for (int i = 0; i < E; i++) {
        printf("%d - %d\t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

void KruskalMST(Graph *graph) {
    int V = graph->V;
    Edge *result = (Edge *)malloc((V - 1) * sizeof(Edge));
    int e = 0;
    int i = 0;
    int totalWeight = 0;

    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("\nMinimum Spanning Tree:\n");
    printEdges(result, e);

    for (int i = 0; i < e; i++) {
        totalWeight += result[i].weight;
    }
    printf("Total weight: %d\n", totalWeight);

    free(result);
    free(subsets);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int **adjMatrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = (int *)malloc(V * sizeof(int));
    }

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    int E = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjMatrix[i][j] != 0) {
                E++;
            }
        }
    }

    Graph *graph = createGraph(V, E);

    int k = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjMatrix[i][j] != 0) {
                graph->edges[k].src = i;
                graph->edges[k].dest = j;
                graph->edges[k].weight = adjMatrix[i][j];
                k++;
            }
        }
    }

    KruskalMST(graph);

    for (int i = 0; i < V; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    free(graph->edges);
    free(graph);

    return 0;
}

```

## output

```
Enter the number of vertices: 6
Enter the adjacency matrix (use 0 for no edge):
0 4 0 0 7 0
4 0 5 0 0 9
0 5 0 6 0 3
0 0 6 0 2 0
7 0 0 2 0 1
0 9 3 0 1 0

Minimum Spanning Tree:
Edge    Weight
4 - 5   1
3 - 4   2
2 - 5   3
0 - 1   4
1 - 2   5
Total weight: 15
```
