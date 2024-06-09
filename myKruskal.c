/* #include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int weight;
    int vertices[2];
} Edge;

int compare(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void main()
{

    int numberOfVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &numberOfVertex);
    int *edges = (int *)malloc(numberOfVertex * sizeof(int));
    int **graph = (int **)malloc(numberOfVertex * sizeof(edges));
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < numberOfVertex; i++)
    {
        graph[i] = (int *)malloc(numberOfVertex * sizeof(int));
        for (int j = 0; j < numberOfVertex; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int maxNumberOfEdges = numberOfVertex * numberOfVertex / 2 + numberOfVertex;
    Edge *selectedEdges = (Edge *)malloc(maxNumberOfEdges * sizeof(Edge));
    int selectedEdgesCount = 0;
    for (int i = 0; i < numberOfVertex; i++)
    {
        for (int j = i; j < numberOfVertex; j++)
        {
            if (graph[i][j] != 0)
            {
                selectedEdges[selectedEdgesCount].weight = graph[i][j];
                selectedEdges[selectedEdgesCount].vertices[0] = i;
                selectedEdges[selectedEdgesCount].vertices[1] = j;
                selectedEdgesCount++;
            }
        }
    }
    qsort(selectedEdges, selectedEdgesCount, sizeof(Edge), compare);
    printf("Selected edges are: \n");
    for (int i = 0; i < selectedEdgesCount; i++)
    {
        printf("( %d , %d ) -> %d\n", selectedEdges[i].vertices[0], selectedEdges[i].vertices[1], selectedEdges[i].weight);
    }
    int *visitedVertices = (int *)malloc(numberOfVertex * sizeof(int));
    for (int i = 0; i < numberOfVertex; i++)
    {
        visitedVertices[i] = 0;
    }
    Edge *minimumSpanningTree = (Edge *)malloc(numberOfVertex * sizeof(Edge));
    int minimumSpanningTreeCount = 0;
    for (int i = 0; i < selectedEdgesCount; i++)
    {
        if (visitedVertices[selectedEdges[i].vertices[0]] == 0 || visitedVertices[selectedEdges[i].vertices[1]] == 0)
        {
            minimumSpanningTree[minimumSpanningTreeCount] = selectedEdges[i];
            minimumSpanningTreeCount++;
            visitedVertices[selectedEdges[i].vertices[0]] = 1;
            visitedVertices[selectedEdges[i].vertices[1]] = 1;
        }
    }
    free(graph);
    free(selectedEdges);
    free(visitedVertices);
    printf("The minimum spanning tree is: \n");
    for (int i = 0; i < minimumSpanningTreeCount; i++)
    {
        printf("( %d , %d ) -> %d\n", minimumSpanningTree[i].vertices[0], minimumSpanningTree[i].vertices[1], minimumSpanningTree[i].weight);
    }
    printf("Total weight of the minimum spanning tree is: %d\n", minimumSpanningTreeCount);
    free(minimumSpanningTree);
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int weight;
    int vertices[2];
} Edge;

int compare(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find(int parent[], int i)
{
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int rank[], int x, int y)
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else
    {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int main()
{
    int numberOfVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &numberOfVertex);
    int **graph = (int **)malloc(numberOfVertex * sizeof(int *));
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < numberOfVertex; i++)
    {
        graph[i] = (int *)malloc(numberOfVertex * sizeof(int));
        for (int j = 0; j < numberOfVertex; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int maxNumberOfEdges = numberOfVertex * (numberOfVertex - 1) / 2;
    Edge *selectedEdges = (Edge *)malloc(maxNumberOfEdges * sizeof(Edge));
    int selectedEdgesCount = 0;
    for (int i = 0; i < numberOfVertex; i++)
    {
        for (int j = i + 1; j < numberOfVertex; j++)
        {
            if (graph[i][j] != 0)
            {
                selectedEdges[selectedEdgesCount].weight = graph[i][j];
                selectedEdges[selectedEdgesCount].vertices[0] = i;
                selectedEdges[selectedEdgesCount].vertices[1] = j;
                selectedEdgesCount++;
            }
        }
    }

    qsort(selectedEdges, selectedEdgesCount, sizeof(Edge), compare);
    printf("Selected edges are: \n");
    for (int i = 0; i < selectedEdgesCount; i++)
    {
        printf("( %d , %d ) -> %d\n", selectedEdges[i].vertices[0], selectedEdges[i].vertices[1], selectedEdges[i].weight);
    }

    int *parent = (int *)malloc(numberOfVertex * sizeof(int));
    int *rank = (int *)malloc(numberOfVertex * sizeof(int));
    for (int i = 0; i < numberOfVertex; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge *minimumSpanningTree = (Edge *)malloc(numberOfVertex * sizeof(Edge));
    int minimumSpanningTreeCount = 0;
    for (int i = 0; i < selectedEdgesCount; i++)
    {
        int u = selectedEdges[i].vertices[0];
        int v = selectedEdges[i].vertices[1];

        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV)
        {
            minimumSpanningTree[minimumSpanningTreeCount] = selectedEdges[i];
            minimumSpanningTreeCount++;
            unionSets(parent, rank, setU, setV);
        }
    }

    printf("The minimum spanning tree is: \n");
    int totalWeight = 0;
    for (int i = 0; i < minimumSpanningTreeCount; i++)
    {
        printf("( %d , %d ) -> %d\n", minimumSpanningTree[i].vertices[0], minimumSpanningTree[i].vertices[1], minimumSpanningTree[i].weight);
        totalWeight += minimumSpanningTree[i].weight;
    }
    printf("Total weight of the minimum spanning tree is: %d\n", totalWeight);

    for (int i = 0; i < numberOfVertex; i++)
    {
        free(graph[i]);
    }
    free(graph);
    free(selectedEdges);
    free(parent);
    free(rank);
    free(minimumSpanningTree);

    return 0;
}
