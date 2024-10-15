#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int optimalSolution[20], temporarySolution[20];
int marked[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int tempcount = 0, sum = INT_MAX;
int tempsum;

int minEdge(int arr[][20], int n, int v)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
        if (arr[v][i] != 0 && marked[i] == 0 && arr[v][i] < min)
            min = arr[v][i];
    return min;
}

int sumTwoMin(int arr[][20], int n, int ele)
{
    int min = 10000000, minSum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[ele][i] != 0 && minSum > (min + arr[ele][i]))
        {
            minSum = min + arr[ele][i];
            if (arr[ele][i] < min)
                min = arr[ele][i];
        }
    }
    return minSum;
}

int lowerbound(int graph[][20], int n)
{
    int lb = 0;
    for (int i = 0; i < n; i++)
    {
        if (marked[i] == 0)
            lb += sumTwoMin(graph, n, i);
    }
    return lb;
}


void TSP(int graph[][20], int n, int source)
{
    tempcount++;
    temporarySolution[tempcount - 1] = source;
    marked[source] = 1;

    if (tempcount == 1)
        tempsum = 0;

    if (tempcount == n && graph[source][temporarySolution[0]] != 0)
    {
        tempsum += graph[source][temporarySolution[0]];
        if (tempsum < sum) // if it is a better path
        {
            for (int i = 0; i < n; i++)
                optimalSolution[i] = temporarySolution[i];
            sum = tempsum;
        }
        tempsum -= graph[source][temporarySolution[0]];
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (marked[i] == 0 && graph[source][i] != 0)
            {
                marked[i] = 1;
                tempsum += graph[source][i];
                int bound = tempsum + (lowerbound(graph, n) + 1 + minEdge(graph, n, source) + minEdge(graph, n, temporarySolution[0])) / 2;

                if (bound < sum)
                    TSP(graph, n, i);
                tempsum -= graph[source][i];
                marked[i] = 0;
            }
        }
    }
    marked[source] = 0;
    tempcount--;
}

int main()
{
    int n;
    printf("Enter number of vertices in the graph:");
    scanf("%d", &n);
    int graph[20][20];
    printf("Enter the distance matrix of the graph:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    TSP(graph, n, 0);
    printf("\nShortest path:");
    for (int i = 0; i < n; i++)
        printf("\n%d", optimalSolution[i]);
    printf("\nshortest path distance:%d", sum);
    return 0;
}
