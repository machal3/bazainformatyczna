#include <iostream>
using namespace std;

pair <long long , long long> ulamek1;
pair <long long , long long> ulamek2;
long long k , nwd;

long long NWD (long long a , long long b)
{
    long long c;

    while (b != 0)
    {
        c = b;
        b = a % b;
        a = c;
    }

    return a;
}

int main ()
{
    cin >> k;
    pair <long long , long long> odp[k];

    for (int i = 0; i < k; i++)
    {
        cin >> ulamek1.first >> ulamek1.second >> ulamek2.first >> ulamek2.second;

        ulamek1.first *= ulamek2.second;
        ulamek2.first *= ulamek1.second;

        ulamek2.second *= ulamek1.second;
        ulamek1.second *= ulamek2.second;

        odp[i].first = ulamek1.first + ulamek2.first;
        odp[i].second = ulamek2.second;

        nwd = NWD (odp[i].first , odp[i].second);

        odp[i].first /= nwd;
        odp[i].second /= nwd;

    }

    for (int i = 0; i < k; i++)
    {
        cout << odp[i].first << " " << odp[i].second << endl;
    }
}