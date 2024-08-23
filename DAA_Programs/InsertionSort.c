#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void insertionSort(int a[SIZE], int n)
{
    int i, j, item;
    for (i = 1; i < n; i++)
    {
        item = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > item)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = item;
    }
}

int presortedElementUnique(int a[SIZE], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
            return 0;
    }
    return 1;
}

int main()
{
    int i, size, flag;
    printf("\nEnter the size of array: ");
    scanf("%d", &size);
    int a[size];
    printf("\nEnter the elements of the array: \n");
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);

    insertionSort(a, size);

    flag = presortedElementUnique(a, size);
    if (flag)
        printf("\nAll the elements are unique\n");
    else
        printf("\nElements are not unique\n");
    return 0;
}
