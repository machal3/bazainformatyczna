#include <iostream>
#include <vector>

using namespace std;

const int duużo = 200005;

vector<int> graf[duużo];
int n , k;
long long wynik = 0;


void dfs (int x , int y , int p)
{
    if (y == k)
    {
        wynik++;
        return;
    }

    for (int sasiad : graf[x])
    {
        if (sasiad != p)
        {
            dfs (sasiad , y + 1 , x);
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    cin >> n >> k;

    for (int i = 1; i < n; i++)
    {
        int a , b;
        cin >> a >> b;
        graf[a].push_back (b);
        graf[b].push_back (a);
    }

    for (int i = 1; i <= n; i++)
    {
        dfs (i , 0 , -1);
    }

    cout << wynik / 2 << '\n';
}