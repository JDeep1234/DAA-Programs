#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
int count = 0;
void merge(int a[SIZE], int l, int m, int r)
{
    int i, j, k;
    i = l;
    j = m + 1;
    k = l;
    int b[SIZE];
    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
            count++;
        }
        else
        {
            b[k++] = a[j++];
            count++;
        }
    }

    while (i <= m)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
    for (i = l; i < k; i++)
        a[i] = b[i];
}

void mergeSort(int a[SIZE], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int a[SIZE], x[SIZE], y[SIZE], z[SIZE];
    int n, i, j, c1, c2, c3;
    printf("\nEnter the size of the array :");
    scanf("%d", &n);
    printf("\nRead the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n - 1);
    printf("\nSorted array : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    printf("\nCount = %d\n", count);
    printf("\nSize\tASC\tDESC\tRAND\n");
    for (i = 16; i < SIZE; i *= 2)
    {
        for (j = 0; j < i; j++)
        {
            x[j] = j;
            y[j] = i - j - 1;
            z[j] = rand() % i;
        }
        count = 0;
        mergeSort(x, 0, i - 1);
        c1 = count;
        count = 0;
        mergeSort(y, 0, i - 1);
        c2 = count;
        count = 0;
        mergeSort(z, 0, i - 1);
        c3 = count;
        printf("%d\t%d\t%d\t%d\n", i, c1, c2, c3);
    }
    return 0;
}