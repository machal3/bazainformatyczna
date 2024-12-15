#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long odp;

struct K
{
    int koszt;
    int odzysk;
    int roznica;
};

struct por
{
    bool operator () (K& a , K& b) const
    {
        return a.roznica > b.roznica;
    }
};


priority_queue < K , vector<K> , por> kolejka1;

priority_queue <int> kolejka2;

int A[1000005];
int B[1000005];
int C[1000005];
int a , b;
int wczyt;

int main ()
{
    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < a; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < a; i++)
    {
        kolejka1.push ({ A[i] , B[i] , (A[i] - B[i]) });
    }

    for (int i = 0; i < b; i++)
    {
        cin >> wczyt;
        kolejka2.push (wczyt);
    }

    while (!kolejka1.empty ())
    {
        if (kolejka1.top ().koszt > kolejka2.top ())
        {
            kolejka1.pop ();
        }

        else
        {
            odp += 2 * ((kolejka2.top () - kolejka1.top ().koszt) / kolejka1.top ().roznica + 1);
            kolejka2.push (kolejka1.top ().koszt - (kolejka1.top ().roznica - (kolejka2.top () - kolejka1.top ().koszt) % kolejka1.top ().roznica));
            kolejka2.pop ();
        }

    }

    cout << odp;
}