#include <iostream>
using namespace std;
#include <queue>
constexpr int MN = 3e5;
priority_queue <int> kolejka;

int n;
long long magazyn;

int dostawy[MN];
int zamowienia[MN];

int main ()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> dostawy[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> zamowienia[i];
    }

    for (int i = 0; i < n; i++)
    {
        magazyn += dostawy[i];

        if (zamowienia[i] > magazyn)
        {
            if (kolejka.empty () != true && zamowienia[i] < kolejka.top ())
            {
                magazyn += kolejka.top ();
                kolejka.pop ();

                kolejka.push (zamowienia[i]);
                magazyn -= zamowienia[i];
            }
        }

        else
        {
            kolejka.push (zamowienia[i]);
            magazyn -= zamowienia[i];
        }
    }

    cout << kolejka.size ();
}