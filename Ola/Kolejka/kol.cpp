#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct pacjent
{
	int wiek;
	string imie;
	int indeks;
};

// struct por
// {
// 	bool operator()(const pair<int , string>& a ,
// 					const pair<int , string>& b) const
// 	{
// 		return a.first > b.first;
// 	}
// };

struct por
{
	bool operator()(const pacjent& a , const pacjent& b) const
	{
		if (a.wiek != b.wiek)
		{
			return a.wiek > b.wiek;
		}

		return a.indeks < b.indeks;
	}
};

priority_queue <pacjent , vector<pacjent> , por> kolejka;

int n;
int a;
string b;
pacjent wczyt;

int main ()
{
	cin >> n;

	while (n--)
	{
		cin >> a;

		if (a == -1)
		{
			if (kolejka.empty ())
			{
				cout << "-\n";
			}

			else
			{
				cout << kolejka.top ().imie << "\n";
				kolejka.pop ();

			}
		}

		else
		{
			cin >> wczyt.imie;
			wczyt.wiek = a;
			wczyt.indeks = n;
			kolejka.push (wczyt);
		}
	}

}
