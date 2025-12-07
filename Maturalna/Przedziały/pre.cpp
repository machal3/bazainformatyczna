#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P
{
    long long p;
    long long k;
};

bool por (const P& a , const P& b)
{
    if (a.p != b.p)
    {
        return a.p < b.p;
    }
    return a.k < b.k;
}

int n;
int odp;


int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    cin >> n;

    vector<P> przedzialy (n);

    for (int i = 0; i < n; i++)
    {
        cin >> przedzialy[i].p >> przedzialy[i].k;
    }

    sort (przedzialy.begin () , przedzialy.end () , por);

    if (n > 0)
    {
        odp = 1;
        long long tym = przedzialy[0].k;

        for (int i = 1; i < n; ++i)
        {
            if (przedzialy[i].p <= tym + 1)
            {
                tym = max (tym , przedzialy[i].k);
            }

            else
            {
                odp++;
                tym = przedzialy[i].k;
            }
        }
    }

    return 0;
}