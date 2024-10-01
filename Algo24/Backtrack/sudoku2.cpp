#include <bits/stdc++.h>
using namespace std;

int tab[9][9];
char wczyt;
bool użyte_rzędy[9][9] = { false };
bool użyte_kolumny[9][9] = { false };
bool użyte_kwadraty[9][9] = { false };

pair<int , int> znajdznajmniejsze ()
{
    int minimum = 10;
    pair<int , int> best = { -1, -1 };

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (tab[i][j] == 0)
            {
                int options = 0;
                for (int num = 1; num <= 9; num++)
                {
                    if (!użyte_rzędy[i][num - 1] && !użyte_kolumny[j][num - 1] && !użyte_kwadraty[(i / 3) * 3 + j / 3][num - 1])
                    {
                        options++;
                    }
                }
                if (options < minimum)
                {
                    minimum = options;
                    best = { i, j };
                }
            }
        }
    }
    return best;
}

bool sprawdzanie (int x , int y , int a)
{
    return !użyte_rzędy[x][a - 1] && !użyte_kolumny[y][a - 1] && !użyte_kwadraty[(x / 3) * 3 + y / 3][a - 1];
}

void reku (pair<int , int> kordy)
{
    if (kordy.first == -1)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << tab[i][j] << " ";
            }
            cout << "\n";
        }
        exit (0);
    }

    int x = kordy.first;
    int y = kordy.second;

    for (int h = 1; h <= 9; h++)
    {
        if (sprawdzanie (x , y , h))
        {
            tab[x][y] = h;
            użyte_rzędy[x][h - 1] = true;
            użyte_kolumny[y][h - 1] = true;
            użyte_kwadraty[(x / 3) * 3 + y / 3][h - 1] = true;

            reku (znajdznajmniejsze ());

            tab[x][y] = 0;
            użyte_rzędy[x][h - 1] = false;
            użyte_kolumny[y][h - 1] = false;
            użyte_kwadraty[(x / 3) * 3 + y / 3][h - 1] = false;
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> wczyt;
            if (wczyt != '*' && wczyt != '0')
            {
                tab[i][j] = int (wczyt) - '0';
                użyte_rzędy[i][tab[i][j] - 1] = true;
                użyte_kolumny[j][tab[i][j] - 1] = true;
                użyte_kwadraty[(i / 3) * 3 + j / 3][tab[i][j] - 1] = true;
            }
        }
    }

    reku (znajdznajmniejsze ());
}
