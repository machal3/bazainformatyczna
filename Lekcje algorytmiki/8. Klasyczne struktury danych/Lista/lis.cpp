#include <iostream>

using namespace std;

struct Element
{
	int cyfra;
	int wskaznik;
	bool usuniety;
};

Element lista[200001];
int poczatek = -1;

int main ()
{
	int iloscOperacji;
	cin >> iloscOperacji;

	for (int i = 1; i <= iloscOperacji; i++)
	{
		string operacja;
		cin >> operacja;

		if (operacja == ">")
		{
			int x;
			cin >> x;
			lista[i].cyfra = x;
			lista[i].wskaznik = poczatek;
			lista[i].usuniety = 0;
			poczatek = i;
		}
		else if (operacja == "+")
		{
			int x , y;
			cin >> x >> y;
			lista[i].cyfra = x;
			lista[i].wskaznik = lista[y].wskaznik;
			lista[i].usuniety = 0;
			lista[y].wskaznik = i;
		}
		else if (operacja == "<")
		{
			int i = poczatek;
			while (true)
			{
				if (lista[i].usuniety == 0)
				{
					lista[i].usuniety = 1;
					break;
				}

				i = lista[i].wskaznik;
			}


		}
		else if (operacja == "-")
		{
			int y;
			cin >> y;
			lista[y].usuniety = 1;
		}
	}

	int chodzi = poczatek;
	while (chodzi != -1)
	{
		if (!lista[chodzi].usuniety)
			cout << lista[chodzi].cyfra << " ";
		chodzi = lista[chodzi].wskaznik;
	}

	return 0;
}
