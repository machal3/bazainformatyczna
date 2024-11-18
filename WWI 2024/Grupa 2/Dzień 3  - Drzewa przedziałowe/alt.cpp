#include <bits/stdc++.h>
using namespace std;

bool tab[3000000];
int dlugosc_ciagu , ilosc_zapytan;
obroc wczyt;
int odpowiedz;
int wczyt2;

void zmiana (int a)
{
	if (tab[a] == 0)
	{
		tab[a] = 1;
	}
	else
	{
		tab[a] = 0;
	}

	return;
}


void zapytanie (int a)
{
	if (dlugosc_ciagu == 1)
	{
		cout << 1 << " ";
		return;
	}
	if (a == 1)
	{
		if (tab[a + 1] != tab[a])
		{
			odpowiedz++;
		}
		else
		{
			odpowiedz--;
		}
		cout << odpowiedz << " ";
		return;
	}

	if (a == dlugosc_ciagu)
	{
		if (tab[a - 1] != tab[a])
		{
			odpowiedz++;
		}
		else
		{
			odpowiedz--;
		}
		cout << odpowiedz << " ";
		return;
	}

	if (tab[a + 1] != tab[a] && tab[a - 1] != tab[a])
	{
		odpowiedz += 2;
	}

	if (tab[a + 1] == tab[a] && tab[a - 1] == tab[a])
	{
		odpowiedz -= 2;
	}

	cout << odpowiedz << " ";
	return;

}

int main ()
{
	cin >> dlugosc_ciagu >> ilosc_zapytan;
	cin >> wczyt;

	for (int i = 0; i < dlugosc_ciagu; i++)
	{
		if (wczyt[i] == '1')
		{
			tab[i + 1] = 1;
		}
	}

	odpowiedz = 1;

	bool poprzednie = tab[1];

	for (int i = 2; i < dlugosc_ciagu + 1; i++)
	{
		if (tab[i] != poprzednie)
		{
			odpowiedz++;
			poprzednie = tab[i];
		}
	}

	cout << odpowiedz << " ";

	for (int i = 0; i < ilosc_zapytan; i++)
	{
		cin >> wczyt2;
		zmiana (wczyt2);
		zapytanie (wczyt2);

	}
}
