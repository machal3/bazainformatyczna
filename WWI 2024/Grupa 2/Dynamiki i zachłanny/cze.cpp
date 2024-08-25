#include <bits/stdc++.h>

using namespace std;

long long m , n;

bool por (pair <long long , long long> a , pair <long long , long long> b)
{
	return a.first > b.first;
}

long long pion = 1 , poziom = 1;

long long suma;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	cin >> m >> n;
	pair <int , bool> tab[m + n];

	for (int i = 0; i < m - 1; i++)
	{
		cin >> tab[i].first;
	}

	for (int i = m - 1; i < m + n - 2; i++)
	{
		cin >> tab[i].first;
		tab[i].second = 1;
	}

	sort (tab , tab + n + m , por);

	for (int i = 0; i < m + n; i++)
	{
		if (tab[i].second == 0)
		{
			suma += tab[i].first * poziom;

			pion++;
		}

		else
		{
			suma += tab[i].first * pion;

			poziom++;
		}
	}

	cout << suma;
}
