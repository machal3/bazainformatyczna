#include <bits/stdc++.h>
using namespace std;

int a1 , a2 , a3 , a4 , a5 , a6;
double punkt , wartosc;


bool czy_zero (double liczba)
{
    if (liczba <= 0.0000001 && liczba >= -0.0000001)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void bin_search (double p , double k)
{
    punkt = (p + k) / 2;
    wartosc = punkt * punkt * punkt * punkt * punkt * a1 + punkt * punkt * punkt * punkt * a2 + punkt * punkt * punkt * a3 + punkt * punkt * a4 + punkt * a5 + a6;

    if (czy_zero (wartosc) == 1)
    {
        cout << fixed << setprecision (8) << punkt;
        return;
    }
    else if (wartosc > 0)
    {
        bin_search (p , punkt);
        return;
    }
    else
    {
        bin_search (punkt , k);
        return;
    }
}

int main ()
{
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;

    if (a1 < 0)
    {
        a1 *= -1;
        a2 *= -1;
        a3 *= -1;
        a4 *= -1;
        a5 *= -1;
        a6 *= -1;
    }

    bin_search (-10 , 10);
}
