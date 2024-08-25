#include <bits/stdc++.h>
using namespace std;

int ilosc_wierzcholkow;
int ilosc_zapytan;
int chodzi;

struct W
{
	bool odwiedzone;
	int entry;
	int exit;
	vector<int> krawedzie;
};

W graf[2000000];
int a , b;

void DFS (int w)
{
	graf[w].entry = chodzi;
	chodzi++;

	graf[w].odwiedzone = 1;

	for (auto y : graf[w].krawedzie)
	{
		if (graf[y].odwiedzone == 0)
		{
			DFS (y);
		}
	}
	graf[w].exit = chodzi;
	chodzi++;
	return;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);

	cin >> ilosc_wierzcholkow >> ilosc_zapytan;

	for (int i = 1; i < ilosc_wierzcholkow; i++)
	{
		cin >> a >> b;
		graf[a].krawedzie.push_back (b);
		graf[b].krawedzie.push_back (a);
	}

	DFS (1);

	for (int i = 0; i < ilosc_zapytan; i++)
	{
		cin >> a >> b;

		if (graf[b].entry >= graf[a].entry && graf[b].exit <= graf[a].exit)
		{
			cout << "TAK\n";
		}

		else
		{
			cout << "NIE\n";
		}
	}


}
