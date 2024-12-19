#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int duzo_v2 = 500005;
const int duzo_v1 = 20;

int n , q;
vector<int> tab2[duzo_v2];
vector<int> tab;
bool czyzalane[duzo_v2];

int glebokosc[duzo_v2];
int tab3[duzo_v2][duzo_v1];

void dfs (int v , int p)
{
    tab3[v][0] = p;

    for (int i = 1; i < duzo_v1; i++)
    {
        tab3[v][i] = tab3[tab3[v][i - 1]][i - 1];
    }

    for (int u : tab2[v])
    {
        if (u != p)
        {
            glebokosc[u] = glebokosc[v] + 1;
            dfs (u , v);
        }
    }
}

int lca (int u , int v)
{
    if (glebokosc[u] < glebokosc[v])
    {
        swap (u , v);
    }

    for (int i = duzo_v1 - 1; i >= 0; --i)
    {
        if (glebokosc[u] - (1 << i) >= glebokosc[v])
        {
            u = tab3[u][i];
        }
    }

    if (u == v)
    {
        return u;
    }

    for (int i = duzo_v1 - 1; i >= 0; i--)
    {
        if (tab3[u][i] != tab3[v][i])
        {
            u = tab3[u][i];
            v = tab3[v][i];
        }
    }

    return tab3[u][0];
}

int oblicz (int u , int v)
{
    int w = lca (u , v);
    return glebokosc[u] + glebokosc[v] - 2 * glebokosc[w];
}

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    cin >> n >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int u , v;
        cin >> u >> v;
        tab2[u].push_back (v);
        tab2[v].push_back (u);
    }

    glebokosc[1] = 0;

    dfs (1 , 1);

    for (int i = 1; i <= n; i++)
    {
        czyzalane[i] = 1;
    }

    vector<int> niezalane;

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        czyzalane[x] = !czyzalane[x];

        if (czyzalane[x])
        {

            niezalane.erase (remove (niezalane.begin () , niezalane.end () , x) , niezalane.end ());
        }

        else
        {
            niezalane.push_back (x);
        }

        if (niezalane.empty () || niezalane.size () == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        int odp = 0;

        int czyzalane = niezalane[0];

        for (int j = 1; j < niezalane.size (); j++)
        {
            czyzalane = lca (czyzalane , niezalane[j]);
        }

        for (int miasto : niezalane)
        {
            odp += glebokosc[miasto] - glebokosc[czyzalane];
        }

        cout << odp << "\n";
    }
}