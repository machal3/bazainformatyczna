#include <bits/stdc++.h>
using namespace std;

string s1 , s2;
vector<int> tab;
int tym;
int dlugosc;
int n;

int main ()
{
    cin >> s1 >> s2;

    dlugosc = s1.length ();
    int n = s2.length ();
    vector<int> P (dlugosc , 0);
    tym = 0;

    for (int i = 1; i < dlugosc; i++)
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

    for (int i = 0; i < n; i++)
    {
        while (tym > 0 && s2[i] != s1[tym])
        {
            tym = P[tym - 1];
        }
        if (s2[i] == s1[tym])
        {
            tym++;
        }
        if (tym == dlugosc)
        {
            tab.push_back (i - dlugosc + 2);
            tym = P[tym - 1];
        }
    }

    cout << tab.size () << "\n";

    for (int pos : tab)
    {
        cout << pos << " ";
    }
}
