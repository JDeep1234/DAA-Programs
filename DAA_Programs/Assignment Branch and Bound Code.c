/*
Aim: Let there be N workers and N jobs.
Any worker can be assigned to perform any job,
incurring some cost that may vary depending on the work-job assignment.
It is required to perform all jobs by assigning exactly one worker to each job and
exactly one job to each agent in such a way that the total cost of the assignment is minimized.
*/

// Program to solve Job Assignment problem
// using Branch and Bound
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define N 4

struct Node
{
    struct Node *parent;
    int pathCost;
    int cost;
    int workerID;
    int jobID;
    bool assigned[N];
};

struct Node *newNode(int x, int y, bool assigned[], struct Node *parent)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    for (int j = 0; j < N; j++)
        node->assigned[j] = assigned[j];
    node->assigned[y] = true;

    node->parent = parent;
    node->workerID = x;
    node->jobID = y;

    return node;
}

int calculateCost(int costMatrix[N][N], int x, int y, bool assigned[])
{
    int cost = 0;
    bool available[N];
    for (int i = 0; i < N; i++)
        available[i] = true;

    for (int i = x + 1; i < N; i++)
    {
        int min = INT_MAX, minIndex = -1;

        for (int j = 0; j < N; j++)
        {
            if (!assigned[j] && available[j] && costMatrix[i][j] < min)
            {
                minIndex = j;
                min = costMatrix[i][j];
            }
        }

        cost += min;
        available[minIndex] = false;
    }

    return cost;
}

void printAssignments(struct Node *min)
{
    if (min->parent == NULL)
        return;

    printAssignments(min->parent);
    printf("Assign Worker %c to Job %d\n", min->workerID + 'A', min->jobID);
}

int findMinCost(int costMatrix[N][N])
{
    struct Node *pq[N * N];
    int pqSize = 0;

    bool assigned[N] = {false};
    struct Node *root = newNode(-1, -1, assigned, NULL);
    root->pathCost = root->cost = 0;
    root->workerID = -1;

    pq[pqSize++] = root;

    while (pqSize > 0)
    {
        int minIndex = 0;
        for (int i = 1; i < pqSize; i++)
        {
            if (pq[i]->cost < pq[minIndex]->cost)
                minIndex = i;
        }

        struct Node *min = pq[minIndex];
        pq[minIndex] = pq[--pqSize];

        int i = min->workerID + 1;
        if (i == N)
        {
            printAssignments(min);
            return min->cost;
        }

        for (int j = 0; j < N; j++)
        {
            if (!min->assigned[j])
            {
                struct Node *child = newNode(i, j, min->assigned, min);
                child->pathCost = min->pathCost + costMatrix[i][j];
                child->cost = child->pathCost + calculateCost(costMatrix, i, j, child->assigned);

                pq[pqSize++] = child;
            }
        }
    }
}

// Display with labels for rows and columns
void display(int costMatrix[N][N])
{
    printf("\nCost Matrix:\n");

    printf("\t");
    for (int i = 0; i < N; i++)
        printf("Job %d\t", i + 1);
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        printf("%c\t", i + 'A');
        for (int j = 0; j < N; j++)
            printf("%d\t", costMatrix[i][j]);
        printf("\n");
    }

    printf("\n");
}

int main()
{
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}};

    display(costMatrix);

    printf("\nOptimal Cost is %d\n", findMinCost(costMatrix));

    return 0;
}

/*
OUTPUT:
Cost Matrix:
        Job 1   Job 2   Job 3   Job 4
A       9       2       7       8
B       6       4       3       7
C       5       8       1       8
D       7       6       9       4

Assign Worker A to Job 1
Assign Worker B to Job 0
Assign Worker C to Job 2
Assign Worker D to Job 3

Optimal Cost is 13
*/
