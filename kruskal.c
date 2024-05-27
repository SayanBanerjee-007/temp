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
