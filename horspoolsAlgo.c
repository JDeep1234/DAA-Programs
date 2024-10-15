#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 256

int Table[SIZE];

void shiftTable(char p[10])
{
    int i, m;
    m = strlen(p);
    for (i = 0; i < SIZE; i++)
        Table[i] = m;
    for (i = 0; i <= m - 2; i++)
        Table[p[i]] = m - 1 - i;
}

int Horspool(char t[250], char p[10])
{
    int i, j, k, m, n;
    m = strlen(p);
    n = strlen(t);
    shiftTable(p);
    i = m - 1;
    while (i <= n - 1)
    {
        k = 0;
        while (k < m && p[m - 1 - k] == t[i - k])
            k += 1;
        if (k == m)
            return i - m + 1;
        else
            i = i + Table[t[i]];
    }
    return -1;
}

int main()
{
    char t[250], p[10];
    printf("\nEnter the Text :");
    scanf("%s", t);
    printf("\nEnter the Pattern :");
    scanf("%s", p);
    int flag = Horspool(t, p);
    if (flag == -1)
        printf("\nPattern not present in the text\n");
    else
        printf("Pattern is found at index %d\n", flag);
    return 0;
}