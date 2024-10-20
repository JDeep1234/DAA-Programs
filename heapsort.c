#include <stdio.h>
#include <time.h>  // Include the time.h header for time functions

void heapify(int arr[], int n)
{
    int i, j, k, v, flag;
    for (i = n / 2; i >= 1; i--)
    {
        k = i;
        v = arr[k];
        flag = 0;
        while (!flag && 2 * k <= n)
        {
            j = 2 * k;
            if (j < n)
            {
                if (arr[j] < arr[j + 1])
                    j++;
            }
            if (v >= arr[j])
                flag = 1;
            else
            {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }
}

void heapSort(int arr[], int n)
{
    int i, temp;
    heapify(arr, n);
    for (i = n; i >= 2; i--)
    {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapify(arr, i - 1);
    }
}

int main()
{
    int arr[100], n, i;
    clock_t start, end;
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);

    // Input validation for number of elements
    if (n < 1 || n > 100) {
        printf("Number of elements must be between 1 and 100.\n");
        return 1;  // Exit the program if invalid
    }

    printf("Enter the elements: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    start = clock(); 
    heapSort(arr, n);
    end = clock(); 

    double total_time_taken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;  // Time in milliseconds

    printf("The sorted array is: ");
    for (i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    printf("\nTime taken = %lf ms\n", total_time_taken);
    return 0;
}
