#include <iostream>
#include <vector>

using namespace std;

int n , p , q;
int a , b , c;
vector<int> krawendzie[500010];
int wejscie[500010];
int wyjscie[500010];

int tym;


void zapuszczenie (int w)
{
    wejscie[w] = tym;
    for (int i = 0; i < krawendzie[w].size (); i++)
    {
        tym++;
        zapuszczenie (krawendzie[w][i]);
    }
    wyjscie[w] = tym;
    tym++;
}


int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    cin >> n >> q;
    for (int i = 2; i < n + 1; i++)
    {
        cin >> tym;
        krawendzie[tym].push_back (i);
    };

    zapuszczenie (1);

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> c;
        bool a1 = 1 , b2 = 1;

        if (wejscie[a] >= wejscie[c] and wyjscie[a] <= wyjscie[c])
        {
            a1 = 0;
        }
        if (wejscie[b] >= wejscie[c] and wyjscie[b] <= wyjscie[c])
        {
            b2 = 0;
        }

        if (a1 && b2)
        {
            cout << "Droga wolna\n";
        }

        else if (a1)
        {
            cout << "Tylko A\n";
        }

        else if (b2)
        {
            cout << "Tylko B\n";
        }

        else
        {
            cout << "Dyrektor patrzy\n";
        }
    }
}