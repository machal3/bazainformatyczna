#include <bits/stdc++.h>
using namespace std;

int pojemnosc;
int ilosc_przedmiotow;

struct komorka
{
    int wartosc;
    int_fast32_t poprzednie;
};

struct przedmiot
{
    int masa;
    int wartosc;
};

przedmiot przedmioty[101];

komorka tab[101][10001];

int kozackafuncka (int a , int b)
{
    if (a < b)
    {
        return 0;
    }
    else
    {
        return (a - b);
    }
}

int main ()
{
    cin >> ilosc_przedmiotow >> pojemnosc;

    for (int i = 1; i < ilosc_przedmiotow + 1; i++)
    {
        cin >> przedmioty[i].masa;
    }

    for (int i = 1; i < ilosc_przedmiotow + 1; i++)
    {
        cin >> przedmioty[i].wartosc;
    }

    //koniec wczytu

    for (int j = 1; j < pojemnosc + 1; j++)
    {
        for (int i = 1; i < ilosc_przedmiotow + 1; i++)
        {

            if (przedmioty[i].masa > j)
            {
                tab[i][j].wartosc = tab[i - 1][j].wartosc;
            }

            else if (tab[i - 1][j].wartosc > (tab[i - 1][kozackafuncka (j , przedmioty[i].masa)].wartosc + przedmioty[i].wartosc))
            {
                tab[i][j].wartosc = tab[i - 1][j].wartosc;
            }
            else
            {
                tab[i][j].wartosc = tab[i - 1][kozackafuncka (j , przedmioty[i].masa)].wartosc + przedmioty[i].wartosc;
                tab[i][j].poprzednie = przedmioty[i].masa;
            }
        }
    }
    for (int j = 1; j < pojemnosc + 1; j++)
    {
        for (int i = 1; i < ilosc_przedmiotow + 1; i++)
        {
            cout << tab[i][j].poprzednie << " ";
        }
        cout << endl;
    }

    for (int j = 1; j < pojemnosc + 1; j++)
    {
        cout << tab[ilosc_przedmiotow][pojemnosc].wartosc;
    }

}