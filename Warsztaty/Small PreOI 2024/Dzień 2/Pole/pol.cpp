#include <bits/stdc++.h>

using namespace std;

int wysokosc;
int odp;
int n;
int w;

long long wieksza (long long a , long long b)
{
    return a > b ? a : b;
}

int policz (vector<int>& wysokosci)
{
    stack<int> stos;
    odp = 0;
    n = wysokosci.size ();

    for (int i = 0; i < n; ++i)
    {
        while (!stos.empty () && wysokosci[stos.top ()] > wysokosci[i])
        {
            w = wysokosci[stos.top ()];
            stos.pop ();

            if (stos.empty ())
            {
                wysokosc = i;
            }
            else
            {
                wysokosc = i - stos.top () - 1;
            }

            odp = wieksza (odp , w * wysokosc);
        }
        stos.push (i);
    }

    while (!stos.empty ())
    {
        int h = wysokosci[stos.top ()];
        stos.pop ();

        if (stos.empty ())
        {
            wysokosc = n;
        }
        else
        {
            wysokosc = n - stos.top () - 1;
        }

        odp = wieksza (odp , h * wysokosc);
    }

    return odp;
}

int rek (const vector<vector<int>>& pole)
{
    int dlugosc = pole.size ();

    if (dlugosc == 0)
    {
        return 0;
    }


    vector<int> wysokosc (dlugosc , 0);

    int odp = 0;

    for (int i = 0; i < dlugosc; i++)
    {
        for (int j = 0; j < dlugosc; j++)
        {
            wysokosc[j] = (pole[i][j] == 0) ? wysokosc[j] + 1 : 0;
        }

        odp = wieksza (odp , policz (wysokosc));
    }

    return odp;
}

int main ()
{
    int n;
    cin >> n;

    vector<vector<int>> tab (n , vector<int> (n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> tab[i][j];
        }
    }

    cout << rek (tab);
}
