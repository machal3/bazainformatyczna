#include<bits/stdc++.h>
using namespace std;

int k;
string slowo;
int n;
int maksdlugosc = 0;
int tab[26] = { 0 };  // zainicjuj tablicę zerami, 26 dla alfabetu a-z
int rozne = 0;

int p = 0;
int ko = 0;

int main ()
{
    cin >> k;
    cin >> slowo;
    n = slowo.length ();

    while (ko < n)
    {
        if (tab[slowo[ko] - 'a'] == 0)
        {
            rozne++;
        }

        tab[slowo[ko] - 'a']++;

        while (rozne > k)
        {
            tab[slowo[p] - 'a']--;
            if (tab[slowo[p] - 'a'] == 0)
            {
                rozne--;
            }
            p++;
        }

        maksdlugosc = max (maksdlugosc , ko - p + 1);
        ko++;
    }

    cout << maksdlugosc;
}
