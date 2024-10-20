#include <stdio.h>

int main() {
    int n; // Number of items
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    int values[n], weights[n];
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    int capacity;
    printf("Enter capacity of the knapsack: ");
    scanf("%d", &capacity);

    double totalValue = 0;

    // Sort items based on value-to-weight ratio
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((double)values[i] / weights[i] < (double)values[j] / weights[j]) {
                int tempValue = values[i], tempWeight = weights[i];
                values[i] = values[j]; weights[i] = weights[j];
                values[j] = tempValue; weights[j] = tempWeight;
            }

    for (int i = 0; i < n; i++) {
        if (capacity == 0) break;
        if (weights[i] <= capacity) {
            totalValue += values[i]; capacity -= weights[i];
        } else {
            totalValue += values[i] * ((double)capacity / weights[i]); break;
        }
    }

    printf("Max value = %.2f\n", totalValue);
    return 0;
}
