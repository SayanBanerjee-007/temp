#include <stdio.h>
#include <stdlib.h>

void main()
{
    int numberOfNodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numberOfNodes);
    int graph[numberOfNodes][numberOfNodes];
    printf("Enter the adjacency matrix of the graph: \n");
    for (int i = 0; i < numberOfNodes; i++)
    {
        for (int j = 0; j < numberOfNodes; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int visited[numberOfNodes], startingVertex, queue[numberOfNodes];
    int front = 0, rear = 0;
    for (int i = 0; i < numberOfNodes; i++)
    {
        visited[i] = 0;
    }
    printf("Enter starting vertex: ");
    scanf("%d", &startingVertex);
    visited[--startingVertex] = 1;
    queue[rear++] = startingVertex;
    printf("Sequence of visited vertex:\n");
    while (front < rear)
    {
        int currentNode = queue[front++];
        printf("%d\t", currentNode + 1);
        for (int i = 0; i < numberOfNodes; i++)
        {
            if (visited[i] == 0 && graph[currentNode][i] == 1)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}
