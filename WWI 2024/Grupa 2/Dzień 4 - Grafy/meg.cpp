#include <bits/stdc++.h>
using namespace std;

int ilosc_wiosek , ilosc_zapytan;
int a , b;
int dlugosc_dolna;
int tym = 1;
char wczytchar;
int wczytint_1 , wczytint_2;

struct G
{
    bool odwiedzone;
    int odleglosc;
    vector < int > krawedzie;
    int wejscie;
    int wyjscie;
};

int drzewo[2000000];
G graf[300000];

void DFS (int w , int odl)
{
    graf[w].odwiedzone = 1;
    graf[w].odleglosc = odl;
    graf[w].wejscie = tym;
    tym++;

    for (auto j : graf[w].krawedzie)
    {
        if (graf[j].odwiedzone == 0)
        {
            DFS (j , odl + 1);
        }
    }

    graf[w].wyjscie = tym;
    tym++;
    return;
}

void w_gore (int a)
{
    int odp = 0;
    while (a > 0)
    {
        odp += drzewo[a];
        a /= 2;
    }
    cout << odp << "\n";
    return;
}

void update (int p , int k , int punkt)
{
    if (a > k || b < p)
    {
        return;
    }

    else if (p >= a && k <= b)
    {
        drzewo[punkt]--;
    }
    else
    {
        update (p , (p + k) / 2 , punkt * 2);
        update ((p + k) / 2 + 1 , k , punkt * 2 + 1);
    }
    return;

}

int main ()
{
    cin >> ilosc_wiosek;

    for (int i = 1; i < ilosc_wiosek; i++)
    {
        cin >> a >> b;
        graf[a].krawedzie.push_back (b);
        graf[b].krawedzie.push_back (a);
    }

    DFS (1 , 0);

    dlugosc_dolna = 2;

    while (true)
    {
        if (dlugosc_dolna >= ilosc_wiosek * 2)
        {
            break;
        }

        dlugosc_dolna *= 2;
    }

    for (int i = 1; i < ilosc_wiosek + 1; i++)
    {
        drzewo[graf[i].wejscie + dlugosc_dolna - 1] = graf[i].odleglosc;
        drzewo[graf[i].wyjscie + dlugosc_dolna - 1] = graf[i].odleglosc;
    }

    cin >> ilosc_zapytan;



    for (int i = 0; i < ilosc_zapytan + ilosc_wiosek - 1; i++)
    {
        cin >> wczytchar;

        if (wczytchar == 'W')
        {
            cin >> wczytint_1;
            w_gore (graf[wczytint_1].wejscie + dlugosc_dolna - 1);
        }

        else
        {
            cin >> wczytint_1 >> wczytint_2;
            if (graf[wczytint_1].wejscie > graf[wczytint_2].wejscie)
            {
                a = graf[wczytint_1].wejscie;
                b = graf[wczytint_1].wyjscie;
            }
            else
            {
                a = graf[wczytint_2].wejscie;
                b = graf[wczytint_2].wyjscie;

            }

            update (1 , dlugosc_dolna , 1);
        }
    }
}
