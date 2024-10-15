#include <stdio.h>
#include <stdlib.h>
int w[10], x[10], d;
void sum_subset(int s, int k, int r)
{
    int i;
    static int b = 1;
    x[k] = 1;
    if (s + w[k] == d)
    {
        printf("SUBSET %d:\n", b++);
        for (i = 1; i <= k; i++)
        {
            if (x[i] == 1)
                printf("%d\t", w[i]);
        }
        printf("\n");
    }
    else if (s + w[k] + w[k + 1] <= d)
        sum_subset(s + w[k], k + 1, r - w[k]);
    if ((s + r - w[k] >= d) && (s + w[k + 1] <= d))
    {
        x[k] = 0;
        sum_subset(s, k + 1, r - w[k]);
    }
    if (b == 1)
    {
        printf("No solutions");
        exit(0);
    }
}
int main()
{
    int n, i, sum = 0;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter %d elements in increasing order:\n", n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    printf("Read the subset max value:\n");
    scanf("%d", &d);
    if (sum < d || w[1] > d)
    {
        printf("No solutions\n");
        exit(0);
    }
    sum_subset(0, 1, sum);
    return 0;
}
