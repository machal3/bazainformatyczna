#include <iostream>
using namespace std;


long long m1 , m2 , a1 , a2;


void algorytm_eklidesa (long long a , long long b , long long& nwd , long long& x , long long& y)
{
    if (b == 0)
    {
        nwd = a;
        x = 1;
        y = 0;
    }

    else
    {
        long long x1 , y1;
        algorytm_eklidesa (b , a % b , nwd , x1 , y1);
        x = y1;
        y = x1 - (a / b) * y1;
    }
}

long long tw_chinskie (long long m1 , long long m2 , long long a1 , long long a2)
{
    long long gcd , x , y;
    algorytm_eklidesa (m1 , m2 , gcd , x , y);
    long long odp = a1 + (a2 - a1) * x % m2 * m1;
    return (odp % (m1 * m2) + (m1 * m2)) % (m1 * m2);
}

int main ()
{
    cin >> m1 >> m2 >> a1 >> a2;

    long long odp = tw_chinskie (m1 , m2 , a1 , a2);
    cout << odp;

    return 0;
}
