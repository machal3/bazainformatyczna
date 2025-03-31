#include <bits/stdc++.h>
using namespace std;

string s1 , s2;
vector<int> tab;
int tym;
int dlugosc1;
int dlugosc2;

int main ()
{
    cin >> s1 >> s2;

    dlugosc1 = s1.length ();
    dlugosc2 = s2.length ();

    vector<int> P (dlugosc1 , 0);
    tym = 0;

    for (int i = 1; i < dlugosc1; i++)
    {
        while (tym > 0 && s1[i] != s1[tym])
        {
            tym = P[tym - 1];
        }
        if (s1[i] == s1[tym])
        {
            tym++;
            P[i] = tym;
        }
    }

    tym = 0;

    for (int i = 0; i < dlugosc2; i++)
    {
        while (tym > 0 && s2[i] != s1[tym])
        {
            tym = P[tym - 1];
        }
        if (s2[i] == s1[tym])
        {
            tym++;
        }
        if (tym == dlugosc1)
        {
            tab.push_back (i - dlugosc1 + 2);
            tym = P[tym - 1];
        }
    }

    cout << tab.size () << "\n";

    for (int pos : tab)
    {
        cout << pos << " ";
    }
}
