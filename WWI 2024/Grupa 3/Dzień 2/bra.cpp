#include <iostream>

#include <chrono>
#include <ctime>

using namespace std;

void tp (long long* d , int p , int l , int n , int k , long long x , long long v)
{
    x += p;
    d[x] += v;
    int i = x >> 1;
    while (i > 0)
    {
        d[i] = d[i << 1] + d[(i << 1) + 1];
        i = i >> 1;
    }
}

long long tr (long long* d , int p , int l , int n , int k , long long x , int y)
{
    x += p; y += p;

    long long s = 0;
    for (int i = x; i <= y; i++)
    {
        s += d[i];
    }
    return s;
}

long long ts (long long* a , long long* d , int p , int l , int n , int k , long long m , long long x , long long v)
{
    //cout << "ts(" << x << ' ' << v;
    long long c = 0;
    long long sub = tr (d , p , l , n , k , x - m + 1 , x);
    v -= sub;
    int i = x;
    while (v > 0 && x >= m - 1 && x > i - m)
    {
        long long tmp = max ((long long)0 , min (a[x - m + 1] , v));
        //cout << "WHILE: p x v sub i tmp " << p << ' ' << x << ' ' << v << ' ' << sub << ' ' << i << ' ' << tmp << '\n';
        tp (d , p , l , n , k , x , tmp);
        a[x - m + 1] -= tmp;
        v -= tmp;
        c += tmp;

        /*for (int i = 0; i < n + 2 * m - 2; i++)
        {
            cout << d[i + p] << ' ';
        }
        cout << '\n';*/

        /*if (x < n + m - 1)
        {

        }*/
        x--;
    }
    //cout << ") return " << c << '\n';
    return c;
}
uint32_t last = 123633;
int random (int seed)
{
    long long x = seed * 1453878 * seed;
    x = x % 83274;
    x = x + seed * last;
    x = x ^ 98623467283957891;
    x = x * 468285362394;
    x += 3;
    last = (x + seed) % 104729;
    x = abs ((int)x);
    return x;
}

long long brut (long long n , long long m , long long k , long long* a , bool wypis)
{
    long long* b = new long long[n + m - 1];
    for (long long i = 1; i < n + m - 1; i++)
    {
        b[i] = 0;
    }
    b[0] = min (a[0] , k);
    //b[n - 1] = min(a[n - 1], k);
    for (long long i = 0; i < n + m - 1; i++)
    {
        long long s = 0;
        for (long long j = max ((long long)0 , i - m + 1); j <= i; j++)
        {
            s += b[j];
        }
        if (s < k)
        {
            for (long long j = i; j >= max ((long long)0 , i - m + 1) && s < k; j--)
            {
                long long add = max ((long long)0 , min (a[j] - b[j] , k - s));
                s += add;
                b[j] += add;
            }
        }
    }
    long long all = 0;
    for (long long i = 0; i < n; i++)
    {
        all += b[i];
    }

    if (wypis)
    {
        /*cout << "\nBRUT: " << all << '\n';
        for (long long i = 0; i < n; i++)
        {
            cout << b[i] << ' ';
        }
        cout << '\n';*/
    }

    return all;
}


int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);

    int n , m , k;
    //cin >> n >> m >> k;

    int N = 10000;
    int M = 1000;
    int K = 1000;
    int A = 1000;
    for (int test = 0; test < 1000; test++)
    {
        srand (time (NULL));
        n = random (rand ()) % N;
        k = random (rand ()) % K;
        m = random (rand ()) % M;

        if (n == 0 || m == 0 || k == 0)
        {
            cout << test << " ZERA\n";
            continue;
        }

        cout << "GEN TEST " << n << ' ' << m << ' ' << k << '\n';

        auto a = new long long[n + m - 1];
        for (int i = 0; i < n; i++)
        {
            //cin >> a[i];
            srand (time (NULL) + n);
            a[i] = random (rand ()) % A;
            //cout << a[i] << ' ';
        }
        //cout << "\n";
        for (int i = n; i < n + m - 1; i++)
        {
            a[i] = 0;
        }

        int brut_ans = brut (n , m , k , a , true);


        int p = n + 2 * m - 2;
        int l = 0;
        while (p > 0)
        {
            p = p >> 1;
            l++;
        }
        p = (1 << l);
        l = p << 1;
        auto d = new long long[l];
        for (int i = 0; i < l; i++)
        {
            d[i] = 0;
        }
        long long c = 0;
        for (long long i = 0; i < n + 2 * m - 2; i++)
        {
            c += ts (a , d , p , l , n , k , m , i , k);
        }

        if (c == brut_ans)
        {
            cout << "TAK " << test << '\n';
        }
        else
        {
            cout << "NIE " << test << '\n';
            cout << c << '\n';
            for (int i = 0; i < n + 2 * m - 2; i++)
            {
                cout << d[i + p] << ' ';
            }
            cout << '\n';
            /*for (int i = m - 1; i < n + m - 1; i++)
            {
                cout << d[i + p] << ' ';
            }*/
        }
        //long long c = solve(n, m, k, a, true);
    }
}