#include <stdio.h>
#include <stdlib.h>

#define INF 999

void prims(int n, int cost[10][10])
{
    int i, j, min, u, v, visited[10], mincost = 0, e = 1;
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    visited[1] = 1;
    while (e < n)
    {
        min = INF;
        for (i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                for (j = 1; j <= n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (!visited[v])
        {
            printf("\n Edge %d: (%d %d) cost: %d", e++, u, v, min);
            mincost += min;
            visited[v] = 1;
        }
        cost[u][v] = cost[v][u] = INF;
    }
    printf("\n Total cost = %d", mincost);
}

int main()
{
    int n, i, j, cost[10][10];
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        printf("\n Enter the elements of row %d\n", i);
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
    prims(n, cost);
    return 0;
}
