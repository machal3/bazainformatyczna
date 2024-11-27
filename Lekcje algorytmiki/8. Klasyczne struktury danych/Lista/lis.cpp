#include <iostream>
#include <string>

using namespace std;

struct Element
{
    int cyfra;
    int wskaznik;
    bool usuniente;
};

Element lista[200001];
int poczontek = -1;
int iloscoperacji;
int x , y;

int main ()
{
    cin >> iloscoperacji;
    char s;

    for (int i = 1; i < iloscoperacji + 1; i++)
    {
        cin >> s;
        if (s == '>')
        {
            cin >> lista[i].cyfra;
            lista[i].wskaznik = poczontek;
            poczontek = i;
        }
        else if (s == '<')
        {
            if (poczontek != -1)
            {
                lista[poczontek].usuniente = true;
                poczontek = lista[poczontek].wskaznik;
            }
        }
        else if (s == '-')
        {
            cin >> x;
            if (x >= 0 && x < 1000)
            {
                lista[x].usuniente = true;
            }
        }
        else if (s == '+')
        {
            cin >> x >> y;
            lista[i].cyfra = x;
            lista[i].wskaznik = lista[y].wskaznik;
            lista[y].wskaznik = i;
        }
    }

    for (int i = poczontek; i != -1; i = lista[i].wskaznik)
    {
        if (lista[i].usuniente == false)
        {
            cout << lista[i].cyfra << " ";
        }
    }
}