#include <bits/stdc++.h>
using namespace std;

const int duzo_v2 = 200000;
long long drzewko[4 * duzo_v2];
int wysokosc;

void znajdzpotege (int n)
{
	wysokosc = 1;
	while (wysokosc < n)
	{
		wysokosc *= 2;
	}
}

void dodajliczbe (int x , long long a)
{
	x += wysokosc - 1;
	drzewko[x] += a;
	while (x > 1)
	{
		x /= 2;
		drzewko[x] = max (drzewko[2 * x] , drzewko[2 * x + 1]);
	}
}

long long odczyt (int x , int l , int r , int a , int b)
{
	if (a > r || b < l)
	{
		return LLONG_MIN;
	}
	if (a <= l && r <= b)
	{
		return drzewko[x];
	}
	int mid = (l + r) / 2;
	return max (odczyt (2 * x , l , mid , a , b) , odczyt (2 * x + 1 , mid + 1 , r , a , b));
}

int main ()
{
	int n , m;
	cin >> n >> m;
	znajdzpotege (n);

	for (int i = 0; i < n; i++)
	{
		long long wartosc;
		cin >> wartosc;
		dodajliczbe (i + 1 , wartosc);
	}

	for (int i = 0; i < m; i++)
	{
		char wczyt;
		cin >> wczyt;
		if (wczyt == '+')
		{
			int x;
			long long a;
			cin >> x >> a;
			dodajliczbe (x , a);
		}
		else if (wczyt == '?')
		{
			int a , b;
			cin >> a >> b;
			cout << odczyt (1 , 1 , wysokosc , a , b) << "\n";
		}
	}
	return 0;
}
