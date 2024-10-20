#include <stdio.h>
#include <stdlib.h>
#define INF 9999

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyd(int graph[][100], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
    int n, graph[100][100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use -1 for no path):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == -1)
                graph[i][j] = INF;
        }

    floyd(graph, n);

    printf("Shortest distances between vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%s\t", (graph[i][j] == INF) ? "INF" : "%d", graph[i][j]);
        printf("\n");
    }

    return 0;
}
