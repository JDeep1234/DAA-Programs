#include <stdio.h>
#include <stdlib.h>

int n, W, w[10], v[10], V[10][10], x[10] = {};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void display()
{
    int i, j;
    i = n;
    j = W;
    while (i > 0 || j > 0)
    {
        if (V[i][j] != V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        i = i - 1;
    }
}

int main()
{
    int i, j;
    printf("\nRead number of obj :");
    scanf("%d", &n);
    printf("\nRead the weights :\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("\nRead the profits :\n ");
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    printf("\nRead the knapsack capacity : ");
    scanf("%d", &W);
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                V[i][j] = 0;
            else
                V[i][j] = ((j - w[i]) < 0) ? V[i - 1][j] : max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
        }
    }
    display();
    printf("\nMax profit  = %d", V[n][W]);
    printf("\nObjects included are : \n");
    for (i = 1; i <= n; i++)
        if (x[i])
            printf("%d object included\n", i);
    return 0;
}