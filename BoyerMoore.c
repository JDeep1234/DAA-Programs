#include <stdio.h>
#include <string.h>

#define LEN 256

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void badCharHeuristic(char *str, int size, int badchar[LEN])
{
    int i;
    for (i = 0; i < LEN; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

int search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int badchar[LEN];
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            // printf("Pattern occurs at shift = %d\n", s);
            return s;
        }
        else
            s += max(1, j - badchar[(int)txt[s + j]]);
    }
    return -1; // Pattern not found
}

int main()
{
    char txt[100], pat[20];
    int pos;
    printf("Enter the text: ");
    scanf("%s", txt);
    printf("Enter the pattern: ");
    scanf("%s", pat);
    pos = search(txt, pat);
    if (pos < 0)
        printf("Pattern not found\n");
    else
        printf("Pattern found at position %d\n", pos);
    return 0;
}


