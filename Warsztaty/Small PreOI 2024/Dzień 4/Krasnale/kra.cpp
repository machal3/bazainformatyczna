#include "kralib.h"
#include <bits/stdc++.h>
using namespace std;

int n;

int znajdz_maximum (int l , int p , int max)
{
	if (l == p)
	{
		return l;
	}

	int s = (l + p) / 2;
	int lroz = RoznicaCzapek (l , s);
	int proz = RoznicaCzapek (s + 1 , p);

	if (lroz >= proz)
	{
		return znajdz_maximum (l , s , l);
	}

	else
	{
		return znajdz_maximum (s + 1 , p , p);
	}
}

void rekonstrukcja (int l , int p , vector<int>& tab)
{
	if (l > p) return;

	int roznica = RoznicaCzapek (l , p);

	int tym = -1;
	for (int i = l; i <= p; ++i)
	{

		if (RoznicaCzapek (l , i) == roznica)
		{
			tym = i;
			break;
		}
	}

	if (tym == -1)
	{
		tym = znajdz_maximum (l , p , roznica);
	}

	tab[tym] = roznica;

	rekonstrukcja (l , tym - 1 , tab);
	rekonstrukcja (tym + 1 , p , tab);
}

int main ()
{
	n = init ();
	vector<int> W (n , -1);

	rekonstrukcja (0 , n - 1 , W);

	Odpowiedz (W);
}