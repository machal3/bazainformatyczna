#include <bits/stdc++.h>
using namespace std;

struct wierzcholek
{
	int min_2_dwa;
	int min_2_piec;
	int min_5_dwa;
	int min_5_piec;
};


int tab[200000][200000];
wierzcholek odp[200000][200000];
int n , m;

int mniejsza (int a , int b)
{
	if (a > b)
	{
		return b;
	}

	return a;
}

int liczenie (int a , int b)
{
	int tym = mniejsza (a , b);
	return tym;
}

int ilesiemiesci (int a , int b)
{
	int tym = 0;

	while (true)
	{
		tym++;
		a /= b;

		if (a % b != 0)
		{
			return tym;
		}

	}
}

int main ()
{
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cin >> tab[j][i];
		}
	}

	for (int i = 2; i < m + 1; i++)
	{
		odp[i][0].min_2_dwa = INT_MAX;
		odp[i][0].min_5_dwa = INT_MAX;
		odp[i][0].min_2_piec = INT_MAX;
		odp[i][0].min_5_piec = INT_MAX;
	}
	for (int i = 2; i < n + 1; i++)
	{
		odp[0][1].min_2_dwa = INT_MAX;
		odp[0][1].min_5_dwa = INT_MAX;
		odp[0][1].min_2_piec = INT_MAX;
		odp[0][1].min_5_piec = INT_MAX;
	}

	for (int j = 1; j < n + 1; j++)
	{
		for (int i = 1; i < m + 1; i++)
		{
			if (odp[i - 1][j].min_2_dwa > odp[i][j - 1].min_2_dwa)
			{
				odp[i][j].min_2_dwa = odp[i][j - 1].min_2_dwa;
				odp[i][j].min_2_piec = odp[i][j - 1].min_2_piec;
			}

			else
			{
				odp[i][j].min_2_dwa = odp[i - 1][j].min_2_dwa;
				odp[i][j].min_2_piec = odp[i - 1][j].min_2_piec;
			}

			if (odp[i - 1][j].min_5_piec > odp[i][j - 1].min_5_piec)
			{
				odp[i][j].min_5_piec = odp[i][j - 1].min_5_piec;
				odp[i][j].min_5_dwa = odp[i][j - 1].min_5_dwa;
			}

			else
			{

				odp[i][j].min_5_dwa = odp[i - 1][j].min_5_dwa;
				odp[i][j].min_5_piec = odp[i - 1][j].min_5_piec;
			}
			if (tab[i][j] == 0)
			{
				cout << 0;
				exit (0);
			}
			else
			{
				if (tab[i][j] % 5 == 0)
				{
					odp[i][j].min_2_piec += ilesiemiesci (tab[i][j] , 5);
					odp[i][j].min_5_piec += ilesiemiesci (tab[i][j] , 5);
				}

				if (tab[i][j] % 2 == 0)
				{
					odp[i][j].min_2_dwa += ilesiemiesci (tab[i][j] , 2);
					odp[i][j].min_5_dwa += ilesiemiesci (tab[i][j] , 2);
				}
			}

		}
	}

	cout << mniejsza (liczenie (odp[m][n].min_2_dwa , odp[m][n].min_2_piec) , liczenie (odp[m][n].min_5_dwa , odp[m][n].min_5_piec));

}