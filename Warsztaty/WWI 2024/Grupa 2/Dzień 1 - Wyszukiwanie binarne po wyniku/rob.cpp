#include <bits/stdc++.h>
using namespace std;

int ilosc_drzew , ilosc_dni;

pair<int , int> drzewa[10000000];
bool dni_scinania[10000000];

priority_queue <pair<int , int>> kolejka;
priority_queue <pair<int , int>> kolejka2;

int mini (int a , int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

bool sprawdzanie (int wysokosc)
{
    kolejka2 = kolejka;

    for (int i = 0; i < ilosc_dni; i++)
    {
        dni_scinania[i] = 1;
    }

    for (int i = 0; i < mini (ilosc_dni , ilosc_drzew); i++)
    {
        if (kolejka2.top ().first < wysokosc)
        {
            return 1;
        }

        bool jest_ok = 0;

        for (int j = wysokosc / kolejka2.top ().second; j > -1; j--)
        {
            if (dni_scinania[j] == 1)
            {
                jest_ok = 1;
                dni_scinania[j] = 0;
                break;
            }
        }

        if (jest_ok == 0)
        {
            return 0;
        }

        kolejka2.pop ();
    }

    if (kolejka2.empty () == true)
    {
        return 1;
    }

    if (kolejka2.top ().first <= wysokosc)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void wysz_bin (int p , int k)
{
    if (p == k)
    {
        cout << p;
        return;
    }
    int s = (p + k) / 2;

    if (sprawdzanie (s) == 1)
    {
        wysz_bin (p , s);
    }
    else
    {
        wysz_bin (s + 1 , k);
    }

    return;
}

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);


    cin >> ilosc_drzew >> ilosc_dni;

    for (int i = 0; i < ilosc_drzew; i++)
    {
        pair<int , int> wczyt;
        cin >> wczyt.first >> wczyt.second;
        kolejka.push ({ wczyt.first * ilosc_dni + wczyt.second, wczyt.first });
    }

    wysz_bin (1 , 200000000000);

}
