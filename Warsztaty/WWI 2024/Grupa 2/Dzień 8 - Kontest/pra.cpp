#include <bits/stdc++.h>
using namespace std;

const long long inf = 2000000;

bool tab[3000000];
long long wczyt;
int ilosc_liczb;
long long punkt;

void bin_search (int p , int k)
{
    punkt = (p + k) / 2;
    if (punkt * punkt == wczyt)
    {
        if (tab[punkt] == 0)
        {
            cout << "TAK\n";
            return;
        }
        else
        {
            cout << "NIE\n";
        }
    }
    else if (p == k)
    {
        cout << "NIE\n";
    }

    else if (punkt * punkt > wczyt)
    {
        bin_search (p , punkt);
        return;
    }
    else
    {
        bin_search (punkt + 1 , k);
        return;
    }
}

int main ()
{
    tab[0] = 1;
    tab[1] = 1;

    for (int i = 2; i < inf; i++)
    {
        if (tab[i] == 0)
        {
            for (int j = i * 2; j < inf; j += i)
            {
                tab[j] = 1;
            }
        }
    }

    cin >> ilosc_liczb;

    for (int i = 0; i < ilosc_liczb; i++)
    {
        cin >> wczyt;
        bin_search (1 , 2000000);
    }

}
