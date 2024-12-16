#include<bits/stdc++.h>
using namespace std;

vector<int> rodzic , indeksik;

int znajdz (int p)
{
    if (p == rodzic[p])
    {
        return p;
    }

    return rodzic[p] = znajdz (rodzic[p]);
}

void poloncz (int a , int b)
{
    a = znajdz (a);
    b = znajdz (b);

    if (a != b)
    {
        if (indeksik[a] < indeksik[b])
        {
            swap (a , b);
        }

        rodzic[b] = a;

        if (indeksik[a] == indeksik[b])
        {
            indeksik[a]++;
        }
    }
}

int main ()
{
    vector <pair<int , int>> domy;

    int n , t;
    cin >> n >> t;

    rodzic.resize (n);
    indeksik.resize (n);
    domy.resize (n);

    for (int i = 0; i < n; i++)
    {
        rodzic[i] = i;
        indeksik[i] = 0;
    }

    unordered_map<int , vector<int>> mapax;
    unordered_map<int , vector<int>> mapay;


    for (int i = 0; i < n; i++)
    {
        int y , x;
        cin >> x >> y;
        mapax[y].push_back (i);
        mapay[x].push_back (i);
    }

    for (auto& p : mapax)
    {
        vector<int> indeksy = p.second;

        for (int i = 1; i < indeksy.size (); i++)
        {
            poloncz (indeksy[i - 1] , indeksy[i]);
        }
    }
    for (auto& p : mapay)
    {
        vector<int> indeksy = p.second;

        for (int i = 1; i < indeksy.size (); i++)
        {
            poloncz (indeksy[i - 1] , indeksy[i]);
        }
    }

    for (int i = 0; i < t; i++)
    {

        int a , b;
        cin >> a >> b;

        if (znajdz (a - 1) == znajdz (b - 1))
        {
            cout << "TAK\n";
        }
        else
        {
            cout << "NIE\n";
        }
    }
}
