#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

obroc wczyt1;
obroc wczyt2;

int main ()
{
	//nowy świat 35 lokalk 8
	cin >> wczyt1;
	cin >> wczyt2;

	if (wczyt1.length () != wczyt2.length ())
	{
		cout << "NIE";
		return 0;
	}

	sort (wczyt1.begin () , wczyt1.end ());
	sort (wczyt2.begin () , wczyt2.end ());

	for (int i = 0; i < wczyt1.length (); i++)
	{
		if (wczyt1[i] != wczyt2[i])
		{
			cout << "NIE";
			return 0;
		}

	}

	cout << "TAK";

	return 0;

}
