#include <bits/stdc++.h>
using namespace std;

int ilosc_liczb;
long long maks_liczba = 1e7 + 1;

bool czy_finobaczi[11000000];
bool czy_zlozona[11000000];
int liczby[11000000];

bool por (int a , int b)
{
    if (czy_zlozona[a] == 0 && czy_zlozona[b] == 1)
    {
        return 1;
    }
    else if (czy_zlozona[a] == 1 && czy_zlozona[b] == 0)
    {
        return 0;
    }
    else if (czy_zlozona[a] == 0 && czy_zlozona[b] == 0)
    {
        return a < b;
    }

    else if (czy_finobaczi[a] == 1 && czy_finobaczi[b] == 0)
    {
        return 1;
    }

    else if (czy_finobaczi[a] == 0 && czy_finobaczi[b] == 1)
    {
        return 0;
    }
    else if (czy_finobaczi[a] == 1 && czy_finobaczi[b] == 1)
    {
        return b < a;
    }
    else
    {
        return b > a;
    }
}

int main ()
{
    cin >> ilosc_liczb;

    for (int i = 0; i < ilosc_liczb; i++)
    {
        cin >> liczby[i];
    }

    //sito
    czy_zlozona[1] = 1;
    czy_zlozona[0] = 1;
    for (int i = 2; i < maks_liczba; i++)
    {
        if (czy_zlozona[i] == 0)
        {
            for (int j = i * 2; j < maks_liczba; j += i)
            {
                czy_zlozona[j] = 1;
            }
        }
    }

    //fino
    int a = 1;
    int b = 1;
    while (true)
    {
        czy_finobaczi[a] = 1;
        b += a;
        czy_finobaczi[b] = 1;
        a += b;

        if (a > maks_liczba)
        {
            break;
        }
    }

    //sort
    sort (liczby , liczby + ilosc_liczb , por);

    //wyczyt
    for (int i = 0; i < ilosc_liczb; i++)
    {
        cout << liczby[i] << " ";
    }

}
