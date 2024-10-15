#include <stdio.h>
#include <stdlib.h>
int x[10];
static int c = 1;
void printBoard(int n)
{

    int i, j;
    printf("Solution %d:\n", c++);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i] == j)
                printf("Q\t");
            else
                printf("-\t");
        }
        printf("\n");
    }
}
int place(int k, int i)
{
    int j;
    for (j = 1; j < k; j++)
    {
        if ((x[j] == i) || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}
void nQueens(int k, int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                printf("\n");
                printBoard(n);
            }
            else
                nQueens(k + 1, n);
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of queens:\n");
    scanf("%d", &n);
    nQueens(1, n);
    if (c == 1)
        printf("No solutions!");
}