#include <bits/stdc++.h>

using namespace std;

double wartosc;

int pojemnosc , n;
pair<double , double> tab[1000000];

bool por (pair<double , double> a , pair<double , double> b)
{
    return a.first > b.first;
}

int main ()
{
    cin >> n >> pojemnosc;

    for (int i = 0; i < n; i++)
    {
        cin >> tab[i].second;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> tab[i].first;
        tab[i].first /= tab[i].second;
    }

    sort (tab , tab + n , por);


    int tym = 0;

    while (pojemnosc != 0)
    {
        if (tym == n)
        {
            break;
        }

        if (tab[tym].second > pojemnosc)
        {
            wartosc += tab[tym].first * pojemnosc;
            break;
        }

        wartosc += tab[tym].first * tab[tym].second;
        pojemnosc -= tab[tym].second;
        tym++;
    }

    cout << setprecision (9) << wartosc;
}