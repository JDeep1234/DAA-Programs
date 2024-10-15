#include <stdio.h>
#include <stdlib.h>
int topo[10], k;

void dfs(int a[][10], int n, int v[], int source) {
    int i;

    v[source] = 1;

    for (i = 1; i <= n; i++) {
        if (!v[i] && (a[source][i])) {
            dfs(a, n, v, i);
        }
    }

    topo[++k] = source;
}

int main() {
    int n, a[10][10], i, v[10] = {}, j;

    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    // the printing of the graph is optional
    printf("\nThe grpah is as follows :\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }

    for (i = 1; i <= n; i++) {
        if (v[i] == 0)
            dfs(a, n, v, i);
    }

    printf("\nTopological Ordering is : ");

    for (i = k; i >= 1; i--)
        printf("%d ", topo[i]);

    printf("\n");

    return 0; 
}