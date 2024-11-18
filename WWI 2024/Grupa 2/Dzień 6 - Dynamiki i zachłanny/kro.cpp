#include <iostream>
#include <queue>
using namespace std;
int ilosc_miast;

struct G
{
	int wejscie;
	int odwiedzone;
	int wyjscie;
	vector <int> krawedzie;
};

int tab[1000000];
G graf[1000000];
int a , b;
int maks;
int i_maks;
int chodzona = 1;
bool nie_mozna;

struct por
{
	bool operator() (pair<int , int> a , pair<int , int> b)
	{
		if (a.first == b.first)
		{
			return a.second > b.second;
		}
		return a.first < b.first;
	}
};

priority_queue<pair<int , int> , vector<pair<int , int>> , por> kolejka;

void DFS (int p)
{
	graf[p].odwiedzone = 1;
	graf[p].wejscie = chodzona;
	chodzona++;
	for (auto j : graf[p].krawedzie)
	{
		if (graf[j].odwiedzone == 0)
		{
			DFS (j);
		}
	}

	graf[p].wyjscie = chodzona;

	chodzona++;

}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> ilosc_miast;

	for (int i = 0; i < ilosc_miast - 1; i++)
	{
		cin >> a >> b;
		tab[a]++;
		tab[b]++;
		graf[a].krawedzie.push_back (b);
		graf[b].krawedzie.push_back (a);
	}
	for (int i = 1; i < ilosc_miast + 1; i++)
	{
		kolejka.push ({ tab[i], i });
	}

	while (true)
	{
		maks = kolejka.top ().first;
		i_maks = kolejka.top ().second;

		DFS (i_maks);

		nie_mozna = 0;

		for (auto j : graf[i_maks].krawedzie)
		{
			if (graf[j].wyjscie - graf[j].wejscie + 1 > ilosc_miast)
			{
				nie_mozna = 1;
				break;
			}
		}

		if (nie_mozna == 0)
		{
			cout << i_maks << "\n" << maks;
			break;
			return 1;

		}

		for (int i = 1; i < ilosc_miast + 1; i++)
		{
			graf[i].odwiedzone = 0;
		}

		tab[i_maks] = 0;
		kolejka.pop ();

	}

}
