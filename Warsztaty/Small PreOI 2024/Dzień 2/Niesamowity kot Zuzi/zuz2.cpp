#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n , k;
vector<int> pokoje[200005];
int p;
int m;

int dfs (int v , int rodzic)
{
    int h = 0;
    for (int u : pokoje[v])
    {
        if (u != rodzic)
        {
            int dziecko = dfs (u , v) + 1;
            h = max (h , dziecko);
        }
    }
    if (h > m)
    {
        p++;
        return -1;
    }
    else
    {
        return h;
    }
}

int fun (int M)
{
    m = M;
    p = 0;
    dfs (0 , -1);
    return p;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (0);

    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int a , b;
        cin >> a >> b;
        pokoje[a - 1].push_back (b - 1);
        pokoje[b - 1].push_back (a - 1);
    }

    int l = 0 , r = n , odpowiedz = n;
    while (l <= r)
    {
        int s = (l + r) / 2;
        if (fun (s) > k)
        {
            l = s + 1;
        }
        else
        {
            odpowiedz = s;
            r = s - 1;
        }
    }

    cout << odpowiedz << endl;
    return 0;
}