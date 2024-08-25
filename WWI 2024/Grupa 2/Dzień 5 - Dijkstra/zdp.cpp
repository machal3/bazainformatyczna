#include <bits/stdc++.h>
using namespace std;

const long long inf = LONG_LONG_MAX;

struct W
{
	long long odleglosc;
	vector<pair<long long , int>> krawedzie;
};

W graf[1000000];
priority_queue < pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> kolejka;
int ilosc_wierzcholkow , ilosc_krawedzi;
int a , b , c;

int main ()
{
	cin >> ilosc_wierzcholkow >> ilosc_krawedzi;

	for (int i = 0; i < ilosc_krawedzi; i++)
	{
		cin >> a >> b >> c;
		graf[a].krawedzie.push_back ({ c, b });
		graf[b].krawedzie.push_back ({ c, a });
	}

	for (int i = 2; i < ilosc_wierzcholkow + 1; i++)
	{
		graf[i].odleglosc = inf;
	}

	graf[1].odleglosc = 0;
	kolejka.push ({ 0, 1 });
	pair<long long , int> obecny;

	while (!kolejka.empty ())
	{
		obecny = kolejka.top ();
		kolejka.pop ();
		if (graf[obecny.second].odleglosc < obecny.first)
		{
			continue;
		}

		for (auto nowy : graf[obecny.second].krawedzie)
		{
			if (graf[nowy.second].odleglosc > graf[obecny.second].odleglosc + nowy.first)
			{
				graf[nowy.second].odleglosc = graf[obecny.second].odleglosc + nowy.first;
				kolejka.push ({ graf[obecny.second].odleglosc + nowy.first, nowy.second });
			}
		}

	}

	for (int i = 1; i < ilosc_wierzcholkow + 1; i++)
	{
		if (graf[i].odleglosc == inf)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << graf[i].odleglosc << "\n";
		}
	}


}
