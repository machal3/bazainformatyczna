#include <bits/stdc++.h>
using namespace std;

int ilosc_wierzcholkow;
int X , Y;
int ilosc_krawedzi;
int a , b;
int dlugosc;
const int inf = 3e6;
int najmniejsze = 1e7;

struct W
{
	vector<int> krawedzie;
	bool nakolejce;
	int dlugosc;
};

W graf[inf];

void BFS (int n)
{
	queue<int> kolejka;
	kolejka.push (n);
	graf[n].dlugosc = 0;
	graf[n].nakolejce = 1;

	while (!kolejka.empty ())
	{
		n = kolejka.front ();

		kolejka.pop ();

		for (auto f : graf[n].krawedzie)
		{
			if (!graf[f].nakolejce)
			{
				kolejka.push (f);
				graf[f].dlugosc = graf[n].dlugosc + 1;
				graf[f].nakolejce = 1;
			}
		}

	}

	return;

}
int main ()
{
	cin >> ilosc_wierzcholkow >> ilosc_krawedzi >> X >> Y;

	for (int i = 0; i < ilosc_krawedzi; i++)
	{
		cin >> a >> b;
		graf[a].krawedzie.push_back (b);
		graf[b + ilosc_wierzcholkow].krawedzie.push_back (a + ilosc_wierzcholkow);
		graf[a + 2 * ilosc_wierzcholkow].krawedzie.push_back (b + 2 * ilosc_wierzcholkow);
	}

	for (int i = 1; i < ilosc_wierzcholkow + 1; i++)
	{
		graf[i].krawedzie.push_back (i + ilosc_wierzcholkow);
		graf[i + ilosc_wierzcholkow].krawedzie.push_back (i + 2 * ilosc_wierzcholkow);
	}

	BFS (X);

	if (ilosc_wierzcholkow == 1)
	{
		cout << 0;
		return 0;
	}

	if (graf[Y + 2 * ilosc_wierzcholkow].dlugosc == 0)
	{
		cout << -1;
		return 0;
	}

	else
	{
		cout << graf[Y + 2 * ilosc_wierzcholkow].dlugosc - 2;
		return 0;
	}
}
