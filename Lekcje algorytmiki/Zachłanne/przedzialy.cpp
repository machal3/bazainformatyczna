#include <iostream>
#include <algorithm>
using namespace std;

int m;
pair <int , int> tab[200000];
int obecny;
int ostat;

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    cin >> m;



    for (int i = 0; i < m; i++)
    {
        cin >> tab[i].second >> tab[i].first;
    }

    sort (tab , tab + m);

    for (int i = 0; i < m; i++)
    {
        if (tab[i].second >= ostat)
        {
            obecny++;
            ostat = tab[i].first;
        }
    }

    cout << obecny;
}