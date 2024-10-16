#include <bits/stdc++.h>
using namespace std;

int n , m , k;
obroc wczyt;

int main ()
{
	cin >> n >> m >> k;
	vector<vector<int>> las (n , vector<int> (m));

	for (int i = 0; i < n; ++i)
	{
		cin >> wczyt;
		for (int j = 0; j < m; ++j)
		{
			las[i][j] = wczyt[j] - '0';
		}
	}

	vector<vector<int>> tab (n + 1 , vector<int> (m + 1 , 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			tab[i][j] = las[i - 1][j - 1] + tab[i - 1][j] + tab[i][j - 1] - tab[i - 1][j - 1];
		}
	}

	int odpowiedz = 0;

	for (int gorny = 1; gorny <= n; gorny++)
	{
		for (int dolny = gorny; dolny <= n; ++dolny)
		{
			int lewy = 1;
			for (int prawy = 1; prawy <= m; ++prawy)
			{
				int superzmienna = tab[dolny][prawy] - tab[gorny - 1][prawy] - tab[dolny][lewy - 1] + tab[gorny - 1][lewy - 1];

				while (superzmienna > k)
				{
					lewy++;
					superzmienna = tab[dolny][prawy] - tab[gorny - 1][prawy] - tab[dolny][lewy - 1] + tab[gorny - 1][lewy - 1];
				}

				int obszar = (dolny - gorny + 1) * (prawy - lewy + 1);
				odpowiedz = max (odpowiedz , obszar);
			}
		}
	}

	cout << odpowiedz;
}
