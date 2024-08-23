#include <stdio.h>
#include <stdlib.h>

void bfs(int a[][10], int n, int v[10], int source)
{
    int i, q[10], f = 0, r = -1, node;
    v[source] = 1;
    q[++r] = source;
    while (f <= r)
    {
        node = q[f++];
        for (i = 1; i <= n; i++)
        {
            if (!v[i] && (a[node][i] == 1))
            {
                q[++r] = i;
                v[i] = 1;
            }
        }
    }
}

int main()
{
    int n, a[10][10], i, v[10] = {}, j, count = 0;
    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    // the printing of the graph is optional
    printf("\nThe grpah is as follows :\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n"); 
    }

    for (i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            bfs(a, n, v, i);
            count++;
        }
    }
    if (count == 1)
        printf("\nThe graph is connected\n");
    else
        printf("\nThe graph is not connected and has %d componenets\n", count);
    return 0;
}
