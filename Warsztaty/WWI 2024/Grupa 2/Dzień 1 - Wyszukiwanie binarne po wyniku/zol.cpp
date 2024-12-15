#include <bits/stdc++.h>
using namespace std;

int obecna_dlugosc;
int ilosc_zolnierzy[1000000];
int ilosc_domow;
int w_obecnym_rzedzie;
int obecny_rzad;

bool sprawdzanie (int obecna_dlugosc)
{
    obecny_rzad = 1;
    w_obecnym_rzedzie = 0;

    for (int i = 0; i < ilosc_domow; i++)
    {
        if (obecna_dlugosc < ilosc_zolnierzy[i])
        {
            return 0;
        }

        if (obecna_dlugosc - w_obecnym_rzedzie >= ilosc_zolnierzy[i])
        {
            w_obecnym_rzedzie += ilosc_zolnierzy[i];
        }

        else
        {
            obecny_rzad++;
            w_obecnym_rzedzie = ilosc_zolnierzy[i];
        }
        if (obecny_rzad > obecna_dlugosc)
        {
            return 0;
        }
    }
    return 1;
}

void bin_search (int p , int k)
{
    if (p == k)
    {
        cout << p;
        return;
    }

    int s = (p + k) / 2;

    bool t = sprawdzanie (s);

    if (t == 1)
    {
        bin_search (p , s);
    }
    else
    {
        bin_search (s + 1 , k);
    }
}

int main ()
{
    cin >> ilosc_domow;

    for (int i = 0; i < ilosc_domow; i++)
    {
        cin >> ilosc_zolnierzy[i];
    }

    bin_search (1 , 1000000000);
}
