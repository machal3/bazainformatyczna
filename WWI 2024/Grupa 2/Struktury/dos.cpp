#include <bits/stdc++.h>
using namespace std;

long long ilosc_akcji;
long long wczyt_1 , wczyt_2;
long long suma_liczb;
long long ilosc_liczb_w_srodku;
long long ilosc_w_granicy;
long long ilosc_w_zbiorze;

bool pierwsze = 0;

multiset <int> zbior;

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    auto mniejsze = zbior.begin ();
    auto wieksze = zbior.end ();

    cin >> ilosc_akcji;

    for (int i = 0; i < ilosc_akcji; i++)
    {
        cin >> wczyt_1;

        if (wczyt_1 == 0)
        {
            if (ilosc_liczb_w_srodku == 0)
            {
                cout << 0;
            }
            else
            {
                long long tym = gcd (suma_liczb , ilosc_liczb_w_srodku);
                cout << suma_liczb / tym << "/" << ilosc_liczb_w_srodku / tym << "\n";
            }
        }

        else
        {
            cin >> wczyt_2;

            suma_liczb += wczyt_2;
            ilosc_liczb_w_srodku++;
            ilosc_w_zbiorze++;
            zbior.insert (wczyt_2);

            if (wczyt_2 == *wieksze && pierwsze != 0)
            {
                wieksze++;
            }

            if (pierwsze == 0)
            {
                mniejsze = zbior.begin ();
                wieksze = zbior.end ();
                wieksze--;
                pierwsze = 1;
            }

            if (wczyt_2 < *mniejsze)
            {
                mniejsze--;
                suma_liczb -= wczyt_2;
                suma_liczb += *mniejsze;
            }


            else if (wczyt_2 > *wieksze)
            {
                wieksze++;
                suma_liczb -= wczyt_2;
                suma_liczb += *wieksze;
            }

            if (ilosc_w_granicy < ilosc_w_zbiorze / 10)
            {
                ilosc_w_granicy++;
                ilosc_liczb_w_srodku -= 2;

                suma_liczb -= *mniejsze;
                suma_liczb -= *wieksze;

                mniejsze++;
                wieksze--;
            }

        }
    }
}
