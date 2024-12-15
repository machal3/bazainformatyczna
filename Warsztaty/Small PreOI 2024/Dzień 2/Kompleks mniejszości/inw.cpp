#include <iostream>
#include <vector>
using namespace std;


vector<int> krawedzie[1000001];
int odp[1000000];
int tab[1000000];

void dfs (int p , int rodzic)
{
    tab[p] = 1;
    for (int j : krawedzie[p])
    {
        if (j != rodzic)
        {
            dfs (j , p);
            tab[p] += tab[j];
        }
    }

    odp[p] = 0;
    for (int j : krawedzie[p])
    {
        if (j != rodzic && j < p)
        {
            odp[p] += tab[j];
        }
    }
}

int main ()
{
    ios::sync_with_stdio (0);
    cin.tie (0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        krawedzie[a].push_back (b);
        krawedzie[b].push_back (a);
    }

    dfs (1 , -69);

    for (int i = 1; i <= n; i++)
    {
        cout << odp[i] << "\n";
    }
}
