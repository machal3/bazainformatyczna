#include <bits/stdc++.h>
using namespace std;

int n;
int p;
int tab[1000000];
int wczyt;

int wyszukiwanie_binarne_dolne (int x)
{
    int p = 0;
    int l = n - 1;
    int s = (p + l) / 2;

    while (p <= l)
    {
        if (tab[s] >= x)
        {
            l = s - 1;
        }
        else
        {
            p = s + 1;
        }

        s = (p + l) / 2;
    }

    return l;
}

int wyszukiwanie_binarne_gorne (int x)
{
    int r = 0;
    int l = n - 1;
    int s;

    while (r <= l)
    {
        s = (r + l) / 2;

        if (tab[s] <= x)
        {
            r = s + 1;
        }
        else
        {
            l = s - 1;
        }
    }

    return l;
}

int main ()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tab[i];
    }

    cin >> p;

    for (int i = 0; i < p; i++)
    {
        cin >> wczyt;
        cout << wyszukiwanie_binarne_gorne (wczyt) - wyszukiwanie_binarne_dolne (wczyt) << "\n";
    }



}