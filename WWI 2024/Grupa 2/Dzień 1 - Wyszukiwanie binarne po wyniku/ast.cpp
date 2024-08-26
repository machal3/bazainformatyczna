#include <bits/stdc++.h>
using namespace std;

int ilosc_punktow , ilosc_szlakow;
bool dziala;

struct W
{
	vector<int> krawedzie;
	int wysokosc;
	bool odwiedzone;
};

W wierzcholki[500000];

int a , b;

void dfs (int max_wysokosc , int punkt)
{
	wierzcholki[punkt].odwiedzone = 1;

	if (punkt == ilosc_punktow - 1)
	{
		dziala = 1;
		return;
	}

	for (int i = 0; i < wierzcholki[punkt].krawedzie.size (); i++)
	{
		if (wierzcholki[wierzcholki[punkt].krawedzie[i]].wysokosc <= max_wysokosc && wierzcholki[wierzcholki[punkt].krawedzie[i]].odwiedzone == 0)
		{
			dfs (max_wysokosc , wierzcholki[punkt].krawedzie[i]);
		}
	}

	return;
}

void bin_search (int p , int k)
{
	if (p == k)
	{
		cout << p;
		return;
	}

	int s = (p + k) / 2;

	dziala = 0;

	if (wierzcholki[0].wysokosc > s)
	{
		bin_search (s + 1 , k);
		return;
	}

	for (int i = 0; i < ilosc_punktow; i++)
	{
		wierzcholki[i].odwiedzone = 0;
	}

	dfs (s , 0);

	if (dziala == 1)
	{
		bin_search (p , s);
		return;
	}
	else
	{
		bin_search (s + 1 , k);
		return;
	}

}

int main ()
{
	cin >> ilosc_punktow >> ilosc_szlakow;
	for (int i = 0; i < ilosc_punktow; i++)
	{

		cin >> wierzcholki[i].wysokosc;
	}

	for (int i = 0; i < ilosc_szlakow; i++)
	{
		cin >> a >> b;
		wierzcholki[a - 1].krawedzie.push_back (b - 1);
		wierzcholki[b - 1].krawedzie.push_back (a - 1);
	}
	bin_search (1 , 10000000);
}