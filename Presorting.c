#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void insertionSort(int a[SIZE], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int eleUniqueness(int a[SIZE], int n)
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
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);
    insertionSort(a, size);
    flag = eleUniqueness(a, size);
    if (flag == 1)
        printf("The elements of the array are unique\n");
    else
        printf("The elements of the array are not unique\n");
    return 0;
}