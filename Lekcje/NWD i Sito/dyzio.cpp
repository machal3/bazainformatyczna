#include <iostream>
using namespace std;

int tab[1000001];
int ilosc;
pair <int , int> przedzial;
//0 - piersza; 1 - niepierwsza;

int main ()
{
    //linijki
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    cin >> ilosc;
    int odp[ilosc];

    //sito
    tab[0] = 1;
    tab[1] = 1;

    for (int i = 4; i < 1000001; i += 2)
    {
        tab[i] = 1;
    }

    for (int i = 3; i < 1000001; i += 2)
    {
        if (tab[i] == 0)
        {
            for (int j = 2 * i; j < 1000001; j = j + i)
            {
                tab[j] = 1;
            }
        }
    }


    //sumy prefixowe
    int sum_pref[1000002];

    sum_pref[0] = 0;

    for (int i = 0; i < 1000002; i++)
    {
        sum_pref[i + 1] = sum_pref[i] + tab[i];
    }

    //obliczenie
    for (int i = 0; i < ilosc; i++)
    {
        cin >> przedzial.first >> przedzial.second;
        odp[i] = przedzial.second - przedzial.first + 1 - sum_pref[przedzial.second + 1] + sum_pref[przedzial.first];
    }

    //wyczytywanie
    for (int i = 0; i < ilosc; i++)
    {
        cout << odp[i] << endl;
    }
}