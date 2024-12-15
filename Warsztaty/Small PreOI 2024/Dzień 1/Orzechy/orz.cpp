#include <iostream>
#include <vector>
using namespace std;

long long wieksza (long long a , long long b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

long long D[100005];
long long A[100005];
long long B[100005];

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> D[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> B[i];
    }

    long long ilosca , iloscb;

    cin >> ilosca >> iloscb;

    for (int i = 0; i < n; i++)
    {
        ilosca += D[i];
        iloscb += D[i];

        long long strataA = wieksza (0 , ilosca - A[i]);
        long long strataB = wieksza (0 , iloscb - B[i]);

        if (strataA > strataB)
        {
            iloscb = min (iloscb , B[i]);
        }
        else
        {
            ilosca = min (ilosca , A[i]);
        }
    }

    cout << ilosca + iloscb;
}