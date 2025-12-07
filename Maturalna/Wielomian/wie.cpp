#include <iostream>
#include <vector>
using namespace std;

long long odp;
long long tab[101];

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    long long stopien;
    long long z;

    cin >> stopien >> z;

    for (int i = 0; i <= stopien; i++)
    {
        cin >> tab[i];
    }
    odp = tab[stopien];

    for (int i = stopien - 1; i >= 0; i--)
    {
        odp = odp * z + tab[i];
    }

    cout << odp;

}