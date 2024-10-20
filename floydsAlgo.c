#include <stdio.h>
#include <stdlib.h>
#define INF 9999

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyd(int graph[10][10], int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
    int n, graph[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix :\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
            scanf("%d", &graph[i][j]);
            
        

    floyd(graph, n);

    printf("Shortest distances between vertices:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++){
            printf("%d\t", graph[i][j]);}
        printf("\n");
    }

    return 0;
}
