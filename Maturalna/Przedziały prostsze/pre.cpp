#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

long long odp = LLONG_MAX;
long long tym;

struct P
{
    long long x;
    int i;
    int t;
};

bool por2 (P a , P b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    return a.i < b.i;
}

bool por (P a , P b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    if (a.t != b.t)
    {
        return a.t > b.t;
    }
    return a.i < b.i;
}

vector <P> zdarzenia;
int n;

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long a , b;
        cin >> a;
        cin >> b;
        zdarzenia.push_back ({ a , i + 1, 1 });
        zdarzenia.push_back ({ b , i + 1, -1 });
    }

    sort (zdarzenia.begin () , zdarzenia.end () , por);

    int aktywne = 0;

    for (size_t i = 0; i < zdarzenia.size (); ++i)
    {
        aktywne += zdarzenia[i].t;

        if (aktywne >= 2)
        {
            odp = 0;
            break;
        }
    }

    if (odp != 0)
    {
        vector<P> tab = zdarzenia;

        sort (tab.begin () , tab.end () , por2);

        for (size_t i = 1; i < tab.size (); i++)
        {
            tym = tab[i].x - tab[i - 1].x;

            if (tab[i].i != tab[i - 1].i)
            {
                odp = min (tym , odp);
            }
        }
    }

    cout << odp;
}