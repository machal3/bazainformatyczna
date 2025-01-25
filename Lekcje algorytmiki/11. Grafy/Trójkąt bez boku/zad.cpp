#include <bits/stdc++.h>

using namespace std;

int n , m;

struct W
{
    bool odw;
    set <int> krawedzie;
};

int odp;

void dfs (int v , W wierzcholki [])
{
    wierzcholki[v].odw = true;

    for (auto j : wierzcholki[v].krawedzie)
    {
        if (!wierzcholki[j].odw)
        {
            dfs (j , wierzcholki);
        }
    }

}

int main ()
{

}