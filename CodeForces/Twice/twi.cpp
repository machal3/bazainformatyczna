#include <bits/stdc++.h>

using namespace std;

int ilosc_prob;
int wczyt;

int odp[30];

int main ()
{
    cin >> ilosc_prob;

    for (int i = 0; i < ilosc_prob; i++)
    {
        int n;
        cin >> n;
        int wyczyt = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> wczyt;

            if (odp[wczyt] == 1)
            {
                wyczyt++;
                odp[wczyt] = 0;
            }
            else
                odp[wczyt] = 1;
        }

        for (int j = 1; j < n + 1; j++)
        {
            odp[j] = 0;
        }

        cout << wyczyt << "\n";
    }
}