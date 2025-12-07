#include <iostream>
#include <string>
using namespace std;

string wczyt;
int o;
int naj;

int main ()
{
    cin >> wczyt;

    for (char g : wczyt)
    {
        if (g == 'a')
        {
            o++;
            if (o > naj)
            {
                naj = o;
            }
        }
        else
        {
            o = 0;
        }
    }
    if (naj == 0)
    {
        cout << "BRAK";
        return 0;
    }

    while (naj--)
    {
        cout << 'a';
    }
}