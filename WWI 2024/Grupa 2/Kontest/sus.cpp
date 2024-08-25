#include <bits/stdc++.h>
using namespace std;

int ilosc_graczy , ilosc_pytan;
int a , b;
char c;
int tym1 , tym2;
struct G
{
    vector<int> krawedzie;
    bool odwiedzone;
};

int odp;
G graf[3000000];

void DFS (int punkt)
{
    graf[punkt].odwiedzone = 1;
    if (punkt < ilosc_graczy)
    {
        graf[punkt + ilosc_graczy].odwiedzone = 1;
    }
    else
    {
        graf[punkt - ilosc_graczy].odwiedzone = 1;
    }

    for (auto j : graf[punkt].krawedzie)
    {
        if (graf[j].odwiedzone == 0)
        {
            if (j > ilosc_graczy)
            {
                tym1++;
            }

            else
            {
                tym2++;
            }

            DFS (j);
        }

    }
}

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    cin >> ilosc_graczy >> ilosc_pytan;

    for (int i = 0; i < ilosc_pytan;i++)
    {
        cin >> a >> b >> c;
        if (c == 'h')
        {
            graf[a].krawedzie.push_back (b + ilosc_graczy);
            graf[b + ilosc_graczy].krawedzie.push_back (a);
            graf[a + ilosc_graczy].krawedzie.push_back (b);
            graf[b].krawedzie.push_back (a + ilosc_graczy);
        }
        else
        {
            graf[a].krawedzie.push_back (b);
            graf[b].krawedzie.push_back (a);
            graf[a + ilosc_graczy].krawedzie.push_back (b + ilosc_graczy);
            graf[b + ilosc_graczy].krawedzie.push_back (a + ilosc_graczy);
        }
    }

    for (int i = 1; i < ilosc_graczy + 1; i++)
    {
        if (graf[i].odwiedzone == 0)
        {
            tym1 = 0;
            tym2 = 1;
            DFS (i);
            odp += (max (tym1 , tym2));
        }
    }

    cout << odp;
}
