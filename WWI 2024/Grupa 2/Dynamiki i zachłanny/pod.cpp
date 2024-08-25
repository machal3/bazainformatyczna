#include <bits/stdc++.h>
using namespace std;

long long tab[2][1000000];
long long liczby[2000000];
int ilosc_liczb;
int wczyt;

int main ()
{
	cin >> ilosc_liczb;
	for (int i = 1; i <= ilosc_liczb; i++)
	{
		cin >> wczyt;
		tab[0][i] = tab[1][i - 1] + wczyt;
		tab[1][i] = max (tab[0][i - 1] , tab[1][i - 1]);
	}

	cout << max (tab[0][ilosc_liczb] , tab[1][ilosc_liczb]);
}
