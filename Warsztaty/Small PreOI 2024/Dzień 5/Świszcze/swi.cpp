#include <bits/stdc++.h>
using namespace std;

int n;

long long wieksza (long long a , long long b)
{
    return a > b ? a : b;
}

struct Swiszcz
{
    long long wiek;
    long long k;
    double minim;
};

bool por (Swiszcz& a , Swiszcz& b)
{
    return a.wiek > b.wiek;
}

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    cin >> n;

    vector<Swiszcz> swicarze (n);

    for (int i = 0; i < n; i++)
    {
        long long w , k;
        std::cin >> w >> k;
        swicarze[i].wiek = w;
        swicarze[i].k = k;
        swicarze[i].minim = w / (double)k;
    }

    sort (swicarze.begin () , swicarze.end () , por);

    int odp = 1;
    double najmniejszywiek = 0.0;

    for (const auto& swiszcz : swicarze)
    {
        if (swiszcz.wiek < najmniejszywiek)
        {
            odp++;
            najmniejszywiek = 0.0;
        }
        najmniejszywiek = wieksza (najmniejszywiek , swiszcz.minim);
    }

    cout << odp << "\n";
}