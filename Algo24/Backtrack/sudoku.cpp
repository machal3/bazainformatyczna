#include <bits/stdc++.h>
using namespace std;

int tab[9][9];
char wczyt;

bool sprawdzanie (int x , int y , int a)
{
    for (int i = 0; i < 9; i++)
    {
        if (tab[i][y] == a)
        {
            return 0;
        }

        if (tab[x][i] == a)
        {
            return 0;
        }
    }

    for (int i = 3 * (x / 3); i < 3 * (x / 3) + 3; i++)
    {
        for (int j = 3 * (y / 3); j < 3 * (y / 3) + 3; j++)
        {
            if (tab[i][j] == a)
            {
                return 0;
            }
        }
    }

    return 1;
}

void reku (int x , int y)
{
    if (x == 0 && y == 9)
    {
        for (int m = 0; m < 9; m++)
        {
            for (int n = 0; n < 9; n++)
            {
                cout << tab[n][m] << " ";
            }
            cout << "\n";
        }

        exit (0);
    }

    if (tab[x][y] == 0)
    {
        for (int h = 1; h < 10; h++)
        {
            if (sprawdzanie (x , y , h))
            {
                tab[x][y] = h;

                if (x == 8)
                {
                    reku (0 , y + 1);
                }

                else
                {
                    reku (x + 1 , y);
                }
            }
        }

        tab[x][y] = 0;
    }

    else if (x == 8)
    {
        reku (0 , y + 1);
    }

    else
    {
        reku (x + 1 , y);
    }

    return;

}

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j += 1)
        {
            cin >> wczyt;
            if (wczyt != '*')
            {
                tab[j][i] = int (wczyt) - 48;
            }
        }
    }

    reku (0 , 0);




}