#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graf;
vector<int> stopien (0 , 0);

int n , m;


void DFSEuler (int v , stack<int>& stos)
{
    while (!graf[v].empty ())
    {
        int u = graf[v].back ();
        graf[v].pop_back ();
        for (int i = 0; i < graf[u].size (); i++)
        {
            if (graf[u][i] == v)
            {
                graf[u].erase (graf[u].begin () + i);
                break;
            }
        }
        DFSEuler (u , stos);
    }
    stos.push (v);
}

int main ()
{
    cin >> n >> m;

    graf.resize (n + 1);
    stopien.resize (n + 1);

    for (int i = 0; i < m; i++)
    {
        int u , v;
        cin >> u >> v;
        graf[u].push_back (v);
        graf[v].push_back (u);
        stopien[u]++;
        stopien[v]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (stopien[i] % 2 != 0)
        {
            cout << "NIE" << endl;
            return 0;
        }
    }

    int poczontek = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!graf[i].empty ())
        {
            poczontek = i;
            break;
        }
    }

    stack<int> stosik;

    DFSEuler (poczontek , stosik);

    for (int i = 1; i <= n; i++)
    {
        if (!graf[i].empty ())
        {
            cout << "NIE";
            return 0;
        }
    }

    cout << "TAK\n";
    stosik.pop ();

    while (!stosik.empty ())
    {
        cout << stosik.top () << " ";
        stosik.pop ();
    }
}
