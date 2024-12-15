#include <bits/stdc++.h>
using namespace std;
const int inf = 6000;
int dlugosc_pierwszego , dlugosc_drugiego;
int gora_1[inf];
int gora_2[inf];
int tab[inf][inf];

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);

	obroc pierwsze_slowo , drugie_slowo;
	cin >> pierwsze_slowo >> drugie_slowo;
	dlugosc_pierwszego = pierwsze_slowo.size ();
	dlugosc_drugiego = drugie_slowo.size ();
	for (int i = 0; i < dlugosc_pierwszego; i++)
	{
		gora_1[i] = pierwsze_slowo[i];
	}
	for (int i = 0; i < dlugosc_drugiego; i++)
	{
		gora_2[i] = drugie_slowo[i];
	}

	int maksymalny = 0;

	pair<int , int> i_maksymalny;

	for (int i = 1; i <= dlugosc_pierwszego; i++)
	{
		for (int j = 1; j <= dlugosc_drugiego; j++)
		{
			if (gora_1[i - 1] == gora_2[j - 1])
			{
				tab[i][j] = tab[i - 1][j - 1] + 1;


			}
			else
				tab[i][j] = max (tab[i - 1][j] , tab[i][j - 1]);
			if (tab[i][j] > maksymalny)
			{
				maksymalny = tab[i][j];
				i_maksymalny = { i,j };
			}

		}
	}
	cout << maksymalny << "\n";

	obroc op;

	while (tab[i_maksymalny.first][i_maksymalny.second] != 0)
	{
		int i = i_maksymalny.first;
		int j = i_maksymalny.second;

		int tym = tab[i][j];

		if (tab[i - 1][j] == tym)
		{
			i_maksymalny.first--;
		}
		else if (tab[i][j - 1] == tym)
		{
			i_maksymalny.second--;
		}
		else
		{
			op.push_back (pierwsze_slowo[i - 1]);
			i_maksymalny.first--;
			i_maksymalny.second--;
		}
	}
	for (int i = maksymalny - 1; i >= 0; i--)
	{
		cout << op[i];
	}
}
