#include <stdio.h>
#define INFINITY 999
void dijkstra(int cost[10][10], int n, int source, int v[10], int d[10])
{
    int min, i, j, u;
    v[source] = 1;
    for (i = 1; i <= n; i++)
    {
        min = INFINITY;
        for (j = 1; j <= n; j++)
        {
            if (v[j] == 0 && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }
        v[u] = 1;
        for (j = 1; j <= n; j++)
        {
            if (v[j] == 0 && (d[j] > (d[u] + cost[u][j])))
                d[j] = d[u] + cost[u][j];
        }
    }
}
int main()
{
    int n;
    int cost[10][10];
    int sourceNode;
    int v[10];
    int d[10];
    int i, j;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter Cost Adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    printf("Enter the source (%d to %d):\n", 1, n);
    scanf("%d", &sourceNode);
    for (i = 1; i <= n; i++)
    {
        d[i] = cost[sourceNode][i];
        v[i] = 0;
    }
    dijkstra(cost, n, sourceNode, v, d);
    printf("Shortest distance from %d\n\n", sourceNode);
    for (i = 1; i <= n; i++)
        printf("%d --> %d = %d\n\n", sourceNode, i, d[i]);
    return 0;
}