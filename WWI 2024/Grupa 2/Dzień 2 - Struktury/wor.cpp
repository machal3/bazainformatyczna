#include <iostream>
#include <algorithm>

using namespace std;

int ilosc_prowadzonych , l = 0 , ilosc_kolek , s , powtorzenia;

long long tab[1000000];
long long x;
int minim , maxim;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);

	cin >> ilosc_prowadzonych;

	for (int i = 0; i < ilosc_prowadzonych; i++)
	{
		cin >> tab[i];
	}

	sort (tab , tab + ilosc_prowadzonych);

	cin >> powtorzenia;

	for (int i = 0; i < powtorzenia; i++)
	{
		cin >> x;

		l = 0;
		ilosc_kolek = ilosc_prowadzonych;

		while (l < ilosc_kolek)
		{
			s = (l + ilosc_kolek) / 2;

			if (tab[s] < x)
			{
				l = s + 1;
			}

			else
			{
				ilosc_kolek = s;
			}
		}

		minim = l;

		l = 0;
		ilosc_kolek = ilosc_prowadzonych;

		while (l < ilosc_kolek)
		{
			s = (l + ilosc_kolek) / 2;

			if (tab[s] > x)
			{
				ilosc_kolek = s;
			}

			else
			{
				l = s + 1;
			}
		}

		maxim = ilosc_kolek - 1;

		if (tab[minim] == x)
		{
			cout << maxim - minim + 1 << endl;
		}

		else
		{
			cout << "0" << endl;
		}


	}
}
