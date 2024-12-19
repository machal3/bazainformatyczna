#include <iostream>
#include <vector>
using namespace std;

const int duzo_v2 = 1e6 + 5;
vector<int> kraw[duzo_v2];
int wejscie[duzo_v2] , wyjscie[duzo_v2];
int drzewo[4 * duzo_v2];
int tym;

void dfs (int u , int rodzic)
{
    tym++;
    wejscie[u] = tym;

    for (int f : kraw[u])
    {
        if (f != rodzic)
        {
            dfs (f , u);
        }
    }

    wyjscie[u] = tym;
}

void odczyt (int punkt1 , int l , int p , int punkt)
{
    if (l == p)
    {
        drzewo[punkt1] = 1;
    }

    else
    {
        int s = (l + p) / 2;
        if (punkt <= s)
        {
            odczyt (2 * punkt1 , l , s , punkt);
        }
        else
        {
            odczyt (2 * punkt1 + 1 , s + 1 , p , punkt);
        }

        drzewo[punkt1] = drzewo[2 * punkt1] + drzewo[2 * punkt1 + 1];
    }
}

int funkcja (int punkt , int l , int p , int a , int b)
{
    if (l > b || p < a)
    {
        return 0;
    }
    if (l >= a && p <= b)
    {
        return drzewo[punkt];

    }

    int s = (l + p) / 2;

    return funkcja (2 * punkt , l , s , a , b) + funkcja (2 * punkt + 1 , s + 1 , p , a , b);
}

int main ()
{
    ios::sync_with_stdio (false);
    cin.tie (0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int a , b;
        cin >> a >> b;
        kraw[a].push_back (b);
        kraw[b].push_back (a);
    }

    dfs (1 , 0);

    for (int i = 1; i <= n; ++i)
    {
        int odp = funkcja (1 , 1 , n , wejscie[i] , wyjscie[i]);
        cout << odp << "\n";
        odczyt (1 , 1 , n , wejscie[i]);
    }
}