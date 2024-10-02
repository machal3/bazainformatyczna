#include <bits/stdc++.h>
using namespace std;

struct wierzcholek
{
	int min_2_dwa;
	int min_2_piec;
	int min_5_dwa;
	int min_5_piec;
};

bool czyistniejegdzieszero;

int tab[2000000];
wierzcholek odp[2000000];
int n , m;

int mniejsza (int a , int b)
{
	return min (a , b);
}

int liczenie (int a , int b)
{
	return mniejsza (a , b);
}


int ilesiemiesci (int a , int b)
{
	int tym = 0;
	while (a % b == 0 && a != 0)
	{
		tym++;
		a /= b;
	}
	return tym;
}

int main ()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> tab[(i - 1) * m + (j - 1)];
		}
	}

	odp[0].min_2_dwa = ilesiemiesci (tab[0] , 2);
	odp[0].min_5_dwa = ilesiemiesci (tab[0] , 2);
	odp[0].min_2_piec = ilesiemiesci (tab[0] , 5);
	odp[0].min_5_piec = ilesiemiesci (tab[0] , 5);

	if (tab[0] == 0)
	{
		cout << 1;
		return 0;
	}

	for (int i = 1; i < m; i++)
	{
		if (tab[i] == 0)
		{
			czyistniejegdzieszero = 1;
			odp[i].min_2_dwa = 1;
			odp[i].min_5_dwa = 1;
			odp[i].min_2_piec = 1;
			odp[i].min_5_piec = 1;
		}
		else
		{
			odp[i].min_2_dwa = odp[i - 1].min_2_dwa + ilesiemiesci (tab[i] , 2);
			odp[i].min_5_dwa = odp[i - 1].min_5_dwa + ilesiemiesci (tab[i] , 2);
			odp[i].min_2_piec = odp[i - 1].min_2_piec + ilesiemiesci (tab[i] , 5);
			odp[i].min_5_piec = odp[i - 1].min_5_piec + ilesiemiesci (tab[i] , 5);
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (tab[i * m] == 0)
		{
			czyistniejegdzieszero = 1;
			odp[i * m].min_2_dwa = 1;
			odp[i * m].min_5_dwa = 1;
			odp[i * m].min_2_piec = 1;
			odp[i * m].min_5_piec = 1;
		}
		else
		{
			odp[i * m].min_2_dwa = odp[(i - 1) * m].min_2_dwa + ilesiemiesci (tab[i * m] , 2);
			odp[i * m].min_5_dwa = odp[(i - 1) * m].min_5_dwa + ilesiemiesci (tab[i * m] , 2);
			odp[i * m].min_2_piec = odp[(i - 1) * m].min_2_piec + ilesiemiesci (tab[i * m] , 5);
			odp[i * m].min_5_piec = odp[(i - 1) * m].min_5_piec + ilesiemiesci (tab[i * m] , 5);
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			int indeks = i * m + j;
			int lewy = i * m + (j - 1);
			int gora = (i - 1) * m + j;

			if (odp[lewy].min_2_dwa > odp[gora].min_2_dwa)
			{
				odp[indeks].min_2_dwa = odp[gora].min_2_dwa;
				odp[indeks].min_2_piec = odp[gora].min_2_piec;
			}

			else
			{
				odp[indeks].min_2_dwa = odp[lewy].min_2_dwa;
				odp[indeks].min_2_piec = odp[lewy].min_2_piec;
			}

			if (odp[lewy].min_5_piec > odp[gora].min_5_piec)
			{
				odp[indeks].min_5_piec = odp[gora].min_5_piec;
				odp[indeks].min_5_dwa = odp[gora].min_5_dwa;
			}

			else
			{

				odp[indeks].min_5_dwa = odp[lewy].min_5_dwa;
				odp[indeks].min_5_piec = odp[lewy].min_5_piec;
			}

			if (tab[indeks] == 0)
			{
				czyistniejegdzieszero = 1;
				odp[indeks].min_2_dwa = 1;
				odp[indeks].min_5_dwa = 1;
				odp[indeks].min_2_piec = 1;
				odp[indeks].min_5_piec = 1;
			}

			if (tab[indeks] % 5 == 0)
			{
				odp[indeks].min_2_piec += ilesiemiesci (tab[indeks] , 5);
				odp[indeks].min_5_piec += ilesiemiesci (tab[indeks] , 5);
			}

			if (tab[indeks] % 2 == 0)
			{
				odp[indeks].min_2_dwa += ilesiemiesci (tab[indeks] , 2);
				odp[indeks].min_5_dwa += ilesiemiesci (tab[indeks] , 2);
			}



		}
	}

	int wynik = mniejsza (liczenie (odp[(n - 1) * m + (m - 1)].min_2_dwa , odp[(n - 1) * m + (m - 1)].min_2_piec) , liczenie (odp[(n - 1) * m + (m - 1)].min_5_dwa , odp[(n - 1) * m + (m - 1)].min_5_piec)
	);

	if (czyistniejegdzieszero == 1)
	{
		cout << mniejsza (1 , wynik);
		return 0;
	}

	cout << wynik;
}
