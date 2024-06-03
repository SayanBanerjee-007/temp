#include <stdio.h>
#include <stdlib.h>

void main()
{
    int numberOfNodes;
    printf("Enter number of nodes in the graph: ");
    scanf("%d", &numberOfNodes);

    int graph[numberOfNodes][numberOfNodes];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numberOfNodes; i++)
    {
        for (int j = 0; j < numberOfNodes; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int visited[numberOfNodes], stack[numberOfNodes], startingVertex;
    int top = -1;

    for (int i = 0; i < numberOfNodes; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startingVertex);

    stack[++top] = --startingVertex;
    visited[startingVertex] = 1;

    printf("Sequence of visited vertex:\n%d\t", startingVertex + 1);

    while (top > -1)
    {
        int currentNode = stack[top];
        int i;
        for (i = 0; i < numberOfNodes; i++)
        {
            if (graph[currentNode][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
                printf("%d\t", i + 1);
                break;
            }
        }
        if (i == numberOfNodes)
        {
            top--;
        }
    }
}
