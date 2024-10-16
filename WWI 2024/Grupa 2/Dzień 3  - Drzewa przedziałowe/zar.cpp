#include <bits/stdc++.h>
using namespace std;

int dlugosc_podstawy;
int ilosc_zarowek;
int ilosc_akcji;
obroc podczatkowe_zarowki;
char wczyt_char;
int a;
int b;


bool drzewo[20000000 + 4];

int zmiana (bool a)
{
	if (a == 0)
	{
		a = 1;
	}
	else
	{
		a = 0;
	}

	return a;
}

void update (int p , int k , int punkt)
{
	if (a > k || b < p)
	{
		return;
	}

	else if (p >= a && k <= b)
	{
		drzewo[punkt] = zmiana (drzewo[punkt]);
	}
	else
	{
		update (p , (p + k) / 2 , punkt * 2);
		update ((p + k) / 2 + 1 , k , punkt * 2 + 1);
	}

}

void odczyt (int punkt , bool obecna_wartosc)
{
	if (punkt > 0)
	{
		if (drzewo[punkt] == 1)
		{
			obecna_wartosc = zmiana (obecna_wartosc);
		}

		odczyt (punkt / 2 , obecna_wartosc);
	}
	else
	{
		if (obecna_wartosc == 1)
		{
			cout << "ON\n";
		}
		else
		{
			cout << "OFF\n";
		}
	}

	return;

}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);

	cin >> ilosc_zarowek >> ilosc_akcji;

	dlugosc_podstawy = 2;

	while (true)
	{
		if (dlugosc_podstawy >= ilosc_zarowek)
		{
			break;
		}
		else
		{
			dlugosc_podstawy *= 2;
		}
	}

	cin >> podczatkowe_zarowki;

	for (int i = 0; i < ilosc_zarowek; i++)
	{
		if (podczatkowe_zarowki[i] == 'o')
		{
			drzewo[i + dlugosc_podstawy] = 1;
		}
	}

	for (int i = 0; i < ilosc_akcji; i++)
	{
		cin >> wczyt_char;

		if (wczyt_char == 'Q')
		{
			cin >> a;
			odczyt ((a + dlugosc_podstawy - 1) , 0);
		}

		else
		{
			cin >> a >> b;
			update (1 , dlugosc_podstawy , 1);
		}
	}
}
