#include <iostream>
#include <algorithm>

using namespace std;

long long wzgledna (long long a , long long b)
{
    if (b == 0)
    {
        return a;
    }
    return wzgledna (b , a % b);
}

long long algo_eklides (long long a , long long b , long long& u , long long& v)
{
    if (b == 0)
    {
        u = 1;
        v = 0;
        return a;
    }

    long long u1 , v1;
    long long d = algo_eklides (b , a % b , u1 , v1);
    u = v1;
    v = u1 - (a / b) * v1;
    return d;
}


int funckja (int a , int b , int m)
{
    long long u , v;
    long long d = algo_eklides (a , m , u , v);

    if (b % d != 0)
    {
        return -1;
    }

    a /= d;
    b /= d;
    m /= d;

    long long odp = (u * b) % m;
    if (odp < 0)
    {
        odp += m;
    }

    return odp;
}

int main ()
{
    long long a , b , m;
    cin >> a >> b >> m;

    long long odp = funckja (a , b , m);

    if (odp == -1)
    {
        cout << "NIE";
    }
    else
    {
        cout << odp;
    }
}