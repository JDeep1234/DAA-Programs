#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
int count = 0;

int partition(int a[SIZE], int l, int r)
{
    int pivot = a[l];
    int i = l + 1, j = r, temp;
    while (1)
    {
        while (pivot >= a[i] && i <= r)
        {
            i++;
            count++;
        }
        while (pivot < a[j] && j != l)
        {
            j--;
            count++;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            temp = a[j];
            a[j] = a[l];
            a[l] = temp;
            return j;
        }
    }
}

void quickSort(int a[SIZE], int l, int r)
{
    if (l < r)
    {
        int s = partition(a, l, r);
        quickSort(a, l, s - 1);
        quickSort(a, s + 1, r);
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
    quickSort(a, 0, n - 1);
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
        quickSort(x, 0, i - 1);
        c1 = count;
        count = 0;
        quickSort(y, 0, i - 1);
        c2 = count;
        count = 0;
        quickSort(z, 0, i - 1);
        c3 = count;
        printf("%d\t%d\t%d\t%d\n", i, c1, c2, c3);
    }
    return 0;
}