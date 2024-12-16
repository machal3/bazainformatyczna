#include <bits/stdc++.h>
using namespace std;

int ilosc_stacji;
int ilosc_polonczen;

vector<vector<pair<int , int>>> graf;
vector<pair<int , int>> dystans1;
vector<bool> odwiedzony1;
vector<pair<int , int>> dystans2;
vector<bool> odwiedzony2;

bool por2 (pair<int , int> a , pair<int , int> b)
{
    return a.second < b.second;
}

dystans2.assign (ilosc_stacji , { INT_MAX, INT_MAX });
dystans1.assign (ilosc_stacji , { INT_MAX, INT_MAX });



void dijkstra1 (int start)
{
    odwiedzony1.assign (ilosc_stacji , false);
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> kolejka;

    dystans1[start].first = 0;
    dystans2[start].first = 0;

    kolejka.push ({ 0, start });

    while (!kolejka.empty ())
    {
        int v = kolejka.top ().second;
        kolejka.pop ();

        if (odwiedzony1[v]) continue;
        odwiedzony1[v] = true;

        for (auto edge : graf[v])
        {
            int to = edge.first;
            int weight = edge.second;

            if (dystans1[v].first + weight < dystans1[to].first)
            {
                dystans1[to].first = dystans1[v].first + weight;
                dystans2[to].first = dystans2[v].first + weight;

                kolejka.push ({ dystans1[to].first, to });
            }
        }
    }
}

void dijkstra2 (int start)
{
    odwiedzony2.assign (ilosc_stacji , false);
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> kolejka;

    dystans2[start].second = 0;
    dystans1[start].second = 0;

    kolejka.push ({ 0, start });

    while (!kolejka.empty ())
    {
        int v = kolejka.top ().second;
        kolejka.pop ();

        if (odwiedzony1[v]) continue;
        odwiedzony1[v] = true;

        for (auto edge : graf[v])
        {
            int to = edge.first;
            int waga = edge.second;

            if (dystans2[v].second + waga < dystans2[to].second)
            {
                dystans2[to].second = dystans2[v].second + waga;
                dystans1[to].second = dystans1[v].second + waga;
                kolejka.push ({ dystans2[to].second, to });
            }
        }
    }
}

int s , t , c , k;

int main ()
{
    int odp = 0;

    cin >> ilosc_stacji >> ilosc_polonczen;
    cin >> s >> t >> c >> k;

    graf.resize (ilosc_stacji);

    for (int i = 0; i < ilosc_polonczen; i++)
    {
        int a , b , w;
        cin >> a >> b >> w;
        graf[a].push_back ({ b, w });
        graf[b].push_back ({ a, w });
    }

    dijkstra1 (s);
    dijkstra2 (t);

    sort (dystans1.begin () , dystans1.end ());
    sort (dystans2.begin () , dystans2.end () , por2);

    for (int i = 1; i < ilosc_stacji; i++)
    {
        if (dystans1[i].first + dystans1[i].second <= k - c);
        {
            odp++;
        }
    }


}