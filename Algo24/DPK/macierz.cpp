#include <bits/stdc++.h>
using namespace std;

int tab[3][200001];
long long odp[3][200001];

long long maksi (long long a , long long b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

int n;

int main ()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tab[0][i] >> tab[1][i] >> tab[2][i];
    }

    odp[0][0] = tab[0][0];
    odp[1][0] = tab[1][0];
    odp[2][0] = tab[2][0];


    for (int i = 1; i < n; i++)
    {
        odp[0][i] = maksi (odp[1][i - 1] , odp[2][i - 1]) + tab[0][i];
        odp[1][i] = maksi (odp[0][i - 1] , odp[2][i - 1]) + tab[1][i];
        odp[2][i] = maksi (odp[1][i - 1] , odp[0][i - 1]) + tab[2][i];
    }

    cout << maksi (maksi (odp[1][n - 1] , odp[0][n - 1]) , odp[2][n - 1]);
}