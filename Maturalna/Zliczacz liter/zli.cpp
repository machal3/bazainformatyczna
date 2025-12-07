#include <iostream>
#include <limits>
using namespace std;

string wczyt;

int tab[70];

int main ()
{
    int n;
    cin >> n;
    cin.ignore (numeric_limits<streamsize>::max () , '\n');

    while (n--)
    {
        getline (cin , wczyt);

        if (wczyt.empty ())
        {
            continue;
        }
        for (char g : wczyt)
        {
            if (g >= 'a' && g <= 'z')
            {
                tab[g - 'a']++;
            }
            else if (g >= 'A' && g <= 'Z')
            {
                tab[g - 'A' + 26]++;
            }
        }
    };

    for (int i = 0; i < 26; i++)
    {
        if (tab[i] > 0)
        {
            cout << char (i + 'a') << " " << tab[i] << "\n";
        }
    }

    for (int i = 26; i < 26 * 2; i++)
    {
        if (tab[i] > 0)
        {
            cout << char (i - 26 + 'A') << " " << tab[i] << "\n";
        }
    }
}