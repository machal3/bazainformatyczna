#include "jas.h"

#include <iostream>
#include <set>

using namespace std;

int main ()
{
    int n = init ();
    bool* u = new bool[n];
    bool* k = new bool[n];
    int* p = new int[n];
    for (int i = 0; i < n; i++)
    {
        u[i] = false;
        k[i] = true;
    }

    int f;
    int o;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        int e = n - 1;

        f = wyprobuj (u);
        while (s != e)
        {
            //f = wyprobuj(u);
            int m = (s + e) / 2;
            for (int j = s; j <= m; j++)
            {
                if (k[j])
                {
                    u[j] = !u[j];
                }
            }
            o = wyprobuj (u);
            if ((f > i && o == i) || (f == i && o > i) || (f == -1 && o == i) || (f == i && o == -1))
            {
                e = m;
            }
            else
            {
                s = m + 1;
            }
            f = o;
        }

        //cout << "S E F O " << s << ' ' << e << ' ' << f << ' ' << o << '\n';
        if (o > i || o == -1)
        {

        }
        else
        {
            //u[i] = !u[i];
            u[s] = !u[s];
        }
        //p[i] = s;
        p[s] = i;
        //k[i] = false;
        k[s] = false;

        /*cout << "ODP U: ";
        for (int i = 0; i < n; i++)
        {
            cout << (int)u[i] << ' ';
        }
        cout << "\nODP P: ";
        for (int i = 0; i < n; i++)
        {
            cout << p[i] << ' ';
        }
        cout << '\n';*/
    }

    /*cout << "ODP U: ";
    for (int i = 0; i < n; i++)
    {
        cout << (int)u[i] << ' ';
    }
    cout << "\nODP P: ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << ' ';
    }
    cout << '\n';*/

    odpowiedz (u , p);
}