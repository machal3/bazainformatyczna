#include <iostream>
#include <set>

using namespace std;

int n , p , q;
int a , b , c;
int tab[7700000];


bool zapuszczenie (int w , int unikaj)
{
	if (w == unikaj)
	{
		return 1;
	}

	if (w == 1)
	{
		return 0;
	}

	return zapuszczenie (tab[w] , unikaj);
}


int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> q;
	for (int i = 2; i < n + 1; i++)
	{
		cin >> tab[i];
	}

	for (int i = 0; i < q; i++)
	{
		cin >> a >> b >> c;
		bool a1 = zapuszczenie (a , c);
		bool b1 = zapuszczenie (b , c);

		if (!a1 and !b1)
		{
			cout << "Droga wolna\n";
		}
		else if (!b1 and a1)
		{
			cout << "Tylko B\n";
		}
		else if (!a1 and b1)
		{
			cout << "Tylko A\n";
		}
		else if (a1 && b1)
		{
			cout << "Dyrektor patrzy\n";
		}
	}
}