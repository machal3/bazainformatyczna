#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n , k;

vector<int> bfs (const vector<vector<int>>& adj , int start)
{
    vector<int> distance (adj.size () , -1);
    queue<int> q;

    distance[start] = 0;
    q.push (start);

    while (!q.empty ())
    {
        int u = q.front ();
        q.pop ();

        for (int v : adj[u])
        {
            if (distance[v] == -1)
            {
                distance[v] = distance[u] + 1;
                q.push (v);
            }
        }
    }

    return distance;
}

int main ()
{
    ios::sync_with_stdio (0);
    cin.tie (0);

    cin >> n >> k;

    vector<vector<int>> adj (n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back (v);
        adj[v].push_back (u);
    }

    // Zawartość funkcji minimizeMaxDistance
    vector<int> distance = bfs (adj , 1);

    // Zbieramy pokoje i ich odległości od pokoju 1
    vector<pair<int , int>> pokoje;
    for (int i = 2; i <= n; ++i)
    {
        pokoje.emplace_back (distance[i] , i);
    }

    sort (pokoje.rbegin () , pokoje.rend ());

    for (int i = 0; i < k && i < (int)pokoje.size (); ++i)
    {
        int room = pokoje[i].second;
        adj[1].push_back (room); // Dodajemy bezpośrednie połączenie z pokojem 1
        adj[room].push_back (1);
    }

    // Obliczamy ponownie maksymalną odległość po modyfikacjach
    vector<int> newDistance = bfs (adj , 1);

    cout << *max_element (newDistance.begin () , newDistance.end ()) << "\n";

    return 0;
}
