#include <iostream>
#include <string>

using namespace std;

void push (int* d , int l , int p , int x , int v)
{
    int m = 10;
    int i = x + p;
    if (i % 2 == 1)
    {
        d[i] = v * m;
    }
    else
    {
        d[i] = v;
    }
    d[i] = d[i] % 11;

    while (i > 0)
    {
        i = (i - 1) >> 1;
        m = (m * m) % 11;
        long long s1 = d[(i << 1) + 1] % 11;
        long long s2 = d[(i << 1) + 2] % 11;
        long long a = s1 + s2;
        if (i % 2 == 1)
        {
            a = a * m;
        }
        d[i] = a % 11;
        m = (m * m) % 11;
    }
}

int read (int* d , int l , int p , int a , int b)
{
    a += p;
    b += p;
    int w = 0;
    int wa = 0;
    int wb = 0;
    int m = 10;

    if (a % 2 == 1)
    {
        wa = d[a + 1] + d[a];
    }
    else
    {
        wa = d[a];
    }
    if (b % 2 == 0)
    {
        wb = d[b - 1] + d[b];
    }
    else
    {
        wb = d[b];
    }
    wa = wa % 11;
    wb = wb % 11;

    while (b > a + 1)
    {
        m = (m * m) % 11;
        a = (a - 1) >> 1;
        b = (b - 1) >> 1;

        if (a == b - 1)
        {
            w = wa * m + wb;
            w = w % 11;
            break;
        }

        if (a % 2 == 1)
        {
            wa = (d[a + 1] + wa * m);
        }
        else
        {
            wa = wa;
        }
        if (b % 2 == 0)
        {
            wb = d[b - 1] + wb;
        }
        else
        {
            wb = wb * m;
        }
        wa = wa % 11;
        wb = wb % 11;
    }
    return w % 11;
}

int main ()
{
    int n , q;
    cin >> n >> q;
    string s;

    getline (cin , s);
    getline (cin , s);

    int p = n - 1;
    int l = 0;
    while (p > 0)
    {
        p = p >> 1;
        l += 1;
    }
    p = 1 << l;
    l = p << 1;
    p -= 1;

    int* d = new int[l];
    for (int i = 0; i < l; i++)
    {
        d[i] = 0;
    }
    for (int i = 0; i < s.size (); i++)
    {
        push (d , l , p , i , s[i] - '0');
    }

    for (int i = 0; i < q; i++)
    {
        char o;
        cin >> o;
        if (o == '=')
        {
            int a , b;
            cin >> a >> b;
            push (d , l , p , a , b);
            s[a] = (char)(b + '0');
        }
        else if (o == '?')
        {
            int a , b;
            cin >> a >> b;

            while (d[p + a] == 0)
            {
                a += 1;
            }
            if (a == b)
            {
                /*int t = d[b + p];
                while (t > 9)
                {
                    t /= 10;
                }*/
                //cout << t << ' ' << a << ' ' << b << "\n";
                cout << s[a] << '\n';
                continue;
            }
            cout << read (d , l , p , a , b) << '\n';
        }
        else
        {
            cout << "NIEZNANA OPERACJA\n";
        }
    }
}