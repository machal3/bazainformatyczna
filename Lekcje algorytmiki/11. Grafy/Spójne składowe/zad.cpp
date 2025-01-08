#include <bits/stdc++.h>
using namespace std;

int n , m , q;
int tym;
int a , b;

struct W
{
	bool odw;
	int numer;
	vector <int> krawedzie;
};

W wierzcholki[1000000];

void dfs (int v)
{
	wierzcholki[v].odw = true;
	wierzcholki[v].numer = tym;
	for (auto j : wierzcholki[v].krawedzie)
	{
		if (!wierzcholki[j].odw)
		{
			dfs (j);
		}
	}
}

int main ()
{
	cin >> n >> m >> q;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		wierzcholki[a].krawedzie.push_back (b);
		wierzcholki[b].krawedzie.push_back (a);

	}

	for (int i = 1; i < n + 1; i++)
	{
		if (!wierzcholki[i].odw)
		{
			dfs (i);
			tym++;
		}
	}

	while (q--)
	{
		cin >> a >> b;

		if (wierzcholki[a].numer == wierzcholki[b].numer)
		{
			cout << "T\n";
		}

		else
		{
			cout << "N\n";
		}
	}
}