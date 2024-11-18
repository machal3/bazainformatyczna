#include <stdio.h>
#include <stdlib.h>

int min (int a , int b)
{
    return a < b ? a : b;
}

int max (int a , int b)
{
    return a > b ? a : b;
}

int main ()
{
    int n , m , k;
    scanf ("%d %d %d" , &n , &m , &k);

    int** las = (int**)malloc (n * sizeof (int*));
    for (int i = 0; i < n; i++)
    {
        las[i] = (int*)malloc (m * sizeof (int));
    }

    for (int i = 0; i < n; i++)
    {
        char row[m + 1];
        scanf ("%s" , row);
        for (int j = 0; j < m; j++)
        {
            las[i][j] = row[j] - '0';
        }
    }

    int** prefix = (int**)malloc ((n + 1) * sizeof (int*));
    for (int i = 0; i <= n; i++)
    {
        prefix[i] = (int*)malloc ((m + 1) * sizeof (int));
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                prefix[i][j] = 0;
            }
            else
            {
                prefix[i][j] = las[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    int max_area = 0;

    for (int top = 1; top <= n; top++)
    {
        for (int bottom = top; bottom <= n; bottom++)
        {
            int left = 1;
            for (int right = 1; right <= m; right++)
            {
                int ones = prefix[bottom][right] - prefix[top - 1][right] - prefix[bottom][left - 1] + prefix[top - 1][left - 1];

                while (ones > k)
                {
                    left++;
                    ones = prefix[bottom][right] - prefix[top - 1][right] - prefix[bottom][left - 1] + prefix[top - 1][left - 1];
                }

                int area = (bottom - top + 1) * (right - left + 1);
                max_area = max (max_area , area);
            }
        }
    }

    printf ("%d\n" , max_area);

    for (int i = 0; i < n; i++)
    {
        free (las[i]);
    }
    free (las);

    for (int i = 0; i <= n; i++)
    {
        free (prefix[i]);
    }
    free (prefix);
}
