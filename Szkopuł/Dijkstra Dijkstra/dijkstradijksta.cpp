#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

long long liczba_wierzcholkow , liczba_krawedzi;


struct Krawedz
{
    long long do_wierzcholka , odwrotna;
    long long pojemnosc , koszt;
};

const long long NIESKONCZONOSC = numeric_limits<long long>::max ();

vector<vector<Krawedz>> graf;
vector<long long> dystans , poprzedni_wierzcholek , poprzednia_krawedz;
vector<bool> w_kolejce;

void dodajKrawedz (long long od , long long do_wierzcholka , long long pojemnosc , long long koszt)
{
    graf[od].push_back ({ do_wierzcholka, (long long)graf[do_wierzcholka].size (), pojemnosc, koszt });
    graf[do_wierzcholka].push_back ({ od, (long long)graf[od].size (), 0, -koszt });
}

pair<long long , long long> jakaksfunkcja (long long p , long long dokad , long long maks)
{
    long long odp = 0 , koszt = 0;
    while (odp < maks)
    {
        for (auto& d : dystans)
        {
            d = NIESKONCZONOSC;
        }

        dystans[p] = 0;
        w_kolejce.assign (graf.size () , false);

        for (int i = 0; i < liczba_wierzcholkow; i++)
        {
            w_kolejce[i] = 0;
        }

        queue<long long> kolejka;
        kolejka.push (p);
        w_kolejce[p] = true;

        while (!kolejka.empty ())
        {
            long long u = kolejka.front ();
            kolejka.pop ();
            w_kolejce[u] = 0;

            for (auto& nowy : graf[u])
            {
                if (nowy.pojemnosc > 0 && dystans[u] + nowy.koszt < dystans[nowy.do_wierzcholka])
                {
                    dystans[nowy.do_wierzcholka] = dystans[u] + nowy.koszt;
                    poprzedni_wierzcholek[nowy.do_wierzcholka] = u;
                    poprzednia_krawedz[nowy.do_wierzcholka] = &nowy - &graf[u][0];
                    if (!w_kolejce[nowy.do_wierzcholka])
                    {
                        kolejka.push (nowy.do_wierzcholka);
                        w_kolejce[nowy.do_wierzcholka] = true;
                    }
                }
            }
        }

        if (dystans[dokad] == NIESKONCZONOSC) break;

        long long d = maks - odp;
        for (long long u = dokad; u != p; u = poprzedni_wierzcholek[u])
        {
            d = min (d , graf[poprzedni_wierzcholek[u]][poprzednia_krawedz[u]].pojemnosc);
        }

        odp += d;
        koszt += d * dystans[dokad];
        for (long long u = dokad; u != p; u = poprzedni_wierzcholek[u])
        {
            Krawedz& e = graf[poprzedni_wierzcholek[u]][poprzednia_krawedz[u]];
            e.pojemnosc -= d;
            graf[u][e.odwrotna].pojemnosc += d;
        }
    }
    return { odp, koszt };
}

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    cin >> liczba_wierzcholkow >> liczba_krawedzi;


    graf.resize (liczba_wierzcholkow + 1);
    dystans.resize (liczba_wierzcholkow + 1);
    poprzedni_wierzcholek.resize (liczba_wierzcholkow + 1);
    poprzednia_krawedz.resize (liczba_wierzcholkow + 1);
    w_kolejce.resize (liczba_wierzcholkow + 1);

    for (long long i = 0; i < liczba_krawedzi; ++i)
    {
        long long wierzcholek_poczatkowy , wierzcholek_koncowy , waga;
        cin >> wierzcholek_poczatkowy >> wierzcholek_koncowy >> waga;
        dodajKrawedz (wierzcholek_poczatkowy , wierzcholek_koncowy , 1 , waga);
    }

    long long zrodlo = 1;
    long long ujscie = liczba_wierzcholkow;
    long long maksymalny_przeplyw = 2;

    pair<long long , long long> wynik = jakaksfunkcja (zrodlo , ujscie , maksymalny_przeplyw);

    if (wynik.first < maksymalny_przeplyw)
    {
        cout << "-1";
        return 0;
    }

    cout << wynik.second << endl;
    return 0;
}