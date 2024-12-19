#include <bits/stdc++.h>
using namespace std;

long long modulo (long long a)
{
    return a < 0 ? -a : a;
}

long long mniejsza (long long a , long long b)
{
    return a < b ? a : b;
}

const long long duzo = 1e18;

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long a , b;
        cin >> n >> a >> b;

        vector<long long> x (n);

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        vector<long long> tab (n + 1 , duzo);
        vector<long long> tab2 (n + 1 , duzo);

        tab2[n] = 0;

        for (int i = 0; i < n; i++)
        {
            fill (tab.begin () , tab.end () , duzo);

            for (int j = 0; j <= n; j++)
            {
                if (tab2[j] == duzo) continue;

                long long teraz = (j == n) ? 0 : x[j];
                long long potem = b * modulo (teraz - x[i]);

                tab[j] = mniejsza (tab[j] , tab2[j] + potem);
                tab[i] = mniejsza (tab[i] , tab2[j] + potem + a * abs (teraz - x[i]));
            }

            tab2.swap (tab);
        }

        long long odp = duzo;
        for (int j = 0; j <= n; j++)
        {
            odp = min (odp , tab2[j]);
        }

        cout << odp << "\n";
    }
    return 0;
}