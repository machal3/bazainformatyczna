#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const double EPS = 1e-9;

void funkcja (vector<vector<double>>& macierz , vector<double>& wynik , int n , int m)
{
	for (int i = 0; i < m; i++)
	{
		int tym = i;
		for (int wiersz = i + 1; wiersz < n; wiersz++)
		{
			if (fabs (macierz[wiersz][i]) > fabs (macierz[tym][i]))
			{
				tym = wiersz;
			}
		}

		// Zamień, aby umieścić pivot w bieżącym wierszu
		swap (macierz[i] , macierz[tym]);

		// Znormalizuj wiersz z pivotem
		if (fabs (macierz[i][i]) > EPS)
		{
			for (int kolumna = i + 1; kolumna <= m; kolumna++)
			{
				macierz[i][kolumna] /= macierz[i][i];
			}
			macierz[i][i] = 1;

			// Eliminuj wpisy kolumn poniżej i powyżej pivota
			for (int wiersz = 0; wiersz < n; wiersz++)
			{
				if (wiersz != i)
				{
					double czynnik = macierz[wiersz][i];
					for (int kolumna = i; kolumna <= m; kolumna++)
					{
						macierz[wiersz][kolumna] -= czynnik * macierz[i][kolumna];
					}
				}
			}
		}
	}

	// Wyodrębnij wyniki
	for (int i = 0; i < m; i++)
	{
		wynik[i] = macierz[i][m];
	}
}

int main ()
{
	int n , m;
	cin >> n >> m;

	vector<vector<double>> macierz (n , vector<double> (m + 1));
	vector<double> wynik (m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			cin >> macierz[i][j];
		}
	}

	funkcja (macierz , wynik , n , m);

	for (int i = 0; i < m; i++)
	{
		cout << setprecision (4) << wynik[i] << " ";
	}

	return 0;
}
