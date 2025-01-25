#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
vector<int> adj[MAX_N + 1];  // Lista sąsiedztwa
vector<int> degree (MAX_N + 1); // Stopień wierzchołka

// DFS do sprawdzenia spójności grafu
void dfs (int v , vector<bool>& visited)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
        {
            dfs (u , visited);
        }
    }
}

int main ()
{
    int n , m;
    cin >> n >> m;

    // Inicjalizacja grafu
    for (int i = 0; i < m; ++i)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back (v);
        adj[v].push_back (u);
        degree[u]++;
        degree[v]++;
    }

    // Sprawdzanie, czy wszystkie wierzchołki mają parzysty stopień
    for (int i = 1; i <= n; ++i)
    {
        if (degree[i] % 2 != 0)
        {
            cout << "NIE\n";
            return 0;
        }
    }

    // Sprawdzanie spójności grafu - robimy DFS od dowolnego wierzchołka
    vector<bool> visited (n + 1 , false);
    dfs (1 , visited);
    for (int i = 1; i <= n; ++i)
    {
        if (degree[i] > 0 && !visited[i])
        {
            cout << "NIE\n";
            return 0;
        }
    }

    // Algorytm Hierholzera do znalezienia cyklu Eulera
    stack<int> path;
    vector<int> cycle;
    path.push (1);  // Zaczynamy od wierzchołka 1

    while (!path.empty ())
    {
        int v = path.top ();
        if (degree[v] > 0)
        {
            // Znajdujemy krawędź do przejścia
            for (int i = 0; i < adj[v].size (); ++i)
            {
                int u = adj[v][i];
                if (degree[u] > 0)
                {
                    // Usuwamy krawędź u-v z grafu
                    degree[v]--;
                    degree[u]--;
                    adj[v].erase (remove (adj[v].begin () , adj[v].end () , u) , adj[v].end ());
                    adj[u].erase (remove (adj[u].begin () , adj[u].end () , v) , adj[u].end ());
                    path.push (u);
                    break;
                }
            }
        }
        else
        {
            cycle.push_back (v);
            path.pop ();
        }
    }

    reverse (cycle.begin () , cycle.end ());
    cout << "TAK\n";
    for (int v : cycle)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
