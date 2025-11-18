#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

vector<int> kraw[100000];
bool odw[100000];

void dfs (int p)
{
    odw[p] = true;
    for (int u : kraw[p])
    {
        if (!odw[u])
        {
            dfs (u);
        }
    }
}

int main ()
{
    int n;
    cin >> n;

    vector<int> A (n) , B (n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i < n; i++)
    {
        kraw[A[i]].push_back (B[i]);
        kraw[B[i]].push_back (A[i]);
    }

    int cykl = 0;

    for (int i = 0; i < n; i++)
    {
        if (!odw[i])
        {
            dfs (i);
            cykl++;
        }
    }

    long long odp = 1;
    for (int i = 0; i < cykl; i++)
    {
        odp = (odp * 2) % MOD;
    }

    cout << odp;
}
