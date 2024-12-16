#include <bits/stdc++.h>
#include "loc_lib.h"


using namespace std;
int n;
int l , p;

int main ()
{
    n = daj_n ();
    l = 1;
    p = 1 << n;

    while (l != p)
    {
        char odp = pytanie (l , p);
        if (odp == '>')
        {
            p--;
        }
        else if (odp == '<')
        {
            l++;
        }
        else
        {
            l++;
            p--;
        }
    }
    odpowiedz (l);
}