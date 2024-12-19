#include <bits/stdc++.h>

using namespace std;

int n , p;

void XOrek (vector<int>& tab , vector<pair<int , int>>& operacje , int a , int b)
{
    tab[a] = tab[a] ^ tab[b];
    operacje.push_back ({ a + 1, b + 1 });
    tab[b] = tab[a] ^ tab[b];
    operacje.push_back ({ b + 1, a + 1 });
    tab[a] = tab[a] ^ tab[b];
    operacje.push_back ({ a + 1, b + 1 });
}

void bubble (vector<int>& tab , int p)
{
    int n = tab.size ();
    vector<pair<int , int>> operacje;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((p == 1 && tab[j] > tab[j + 1]) || (p == 2 && tab[j] > tab[j + 1]))
            {
                XOrek (tab , operacje , j , j + 1);
            }
        }
    }

    cout << operacje.size () << "\n";

    for (const auto& op : operacje)
    {
        cout << op.first << " " << op.second << "\n";
    }
}

int main ()
{
    cin >> n >> p;
    vector<int> wczyt (n);

    for (int i = 0; i < n; i++)
    {
        cin >> wczyt[i];
    }

    bubble (wczyt , p);
}