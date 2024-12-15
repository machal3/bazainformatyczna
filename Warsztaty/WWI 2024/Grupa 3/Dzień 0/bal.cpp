#include <iostream>
#include <set>
#include "string"
#include "ballib.h"

using namespace std;

int minimalna_liczba_rzutow ()
{
    int n = liczba_malpek ();
    int r = 0;

    unsigned char* t = new unsigned char[1000000001];

    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < 1000000001; i++)
        {
            t[i] = 0;
        }
        //uint_fast8_t t[1000000000] = { 0 };
        int x = kolejny_balon (i);
        while (x > 0)
        {
            if (t[x] < 1)
            {
                r += 1;
            }
            else
            {
                t[x] -= 1;
            }
            t[x - 1] += 1;

            x = kolejny_balon (i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        auto s = multiset<int> ();

        int x = kolejny_balon (i);
        while (x != -1)
        {
            auto p = s.find (x);
            if (p != s.end ())
            {
                cout << "\nTAK: " << s.size ();
                s.erase (p);
                s.insert (x - 1);
            }
            else
            {
                cout << "\nNIE: " << s.size ();
                s.insert (x - 1);
            }

            cout << "\nSIZE: " << s.size ();

            x = kolejny_balon (i);
            //cin >> x;
        }
        r += s.size ();
    }
    return r;
}


