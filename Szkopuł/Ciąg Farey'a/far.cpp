#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int NWD (int a , int b)
{
	if (b != 0)
		return NWD (b , a % b);

	return a;
}

bool por (pair<int , int> a , pair<int , int> b)
{
	return a.first * b.second < b.first * a.second;
}

int ilosc_sukni;
vector <pair<int , int>> tab;

int main ()
{
	cin >> ilosc_sukni;

	for (int i = 1; i <= ilosc_sukni; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (NWD (i , j) == 1)
			{
				tab.push_back ({ j, i });
			}
		}
	}

	sort (tab.begin () , tab.end () , por);

	for (int i = 0; i < tab.size (); i++)
	{
		cout << tab[i].first << "/" << tab[i].second << " ";
	}
}

