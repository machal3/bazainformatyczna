#include "ballib.h"
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

int n;
vector<vector<int>> balony;
vector<int> podanyBalon;

int liczba_malpek ()
{
    return balony.size ();
}

int kolejny_balon (int i)
{
    if (podanyBalon[i] < balony[i].size ())
        return balony[i][podanyBalon[i]++];
    return -1;
}

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    cin >> n;

    balony.push_back ({});
    podanyBalon.push_back (0);
    for (int i = 1; i <= n; i++)
    {
        int x , y;
        cin >> x;
        balony.push_back ({});
        podanyBalon.push_back (0);
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            balony[i].push_back (y);
        }
    }

    cout << minimalna_liczba_rzutow () << '\n';
}