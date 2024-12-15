#include <bits/stdc++.h>
using namespace std;

int k , n;
int a , b;
int odp;

struct G
{
    vector<int> krawedzie;
    bool odwiedzone;
};

G graf[200001];

void DFS (int p , int odl)
{
    graf[p].odwiedzone = 1;
    if (odl == k)
    {
        odp++;
        return;
    }
    else
    {
        for (auto j : graf[p].krawedzie)
        {
            if (graf[j].odwiedzone == 0)
            {
                DFS (j , odl + 1);
            }
        }
    }

    return;

}

int main ()
{
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        graf[a].krawedzie.push_back (b);
        graf[b].krawedzie.push_back (a);
    }

    for (int i = 1; i < n + 1; i++)
    {
        DFS (i , 0);

        for (int j = 1; j < n + 1; j++)
        {
            graf[j].odwiedzone = 0;
        }
    }

    cout << odp / 2;
}