#include <iostream>

using namespace std;

long long rec (int* a , char* o , int n)
{
    if (n <= 1)
    {
        return a[0];
    }

    long long ret = 0;
    for (int i = 0; i < n - 1; i++)
    {
        char* no = new char[n - 2];
        int* na = new int[n - 1];
        for (int j = 0 , k = 0; j < n - 2; j++)
        {
            if (k == i)
            {
                long long obl;
                if (o[k] == '+')
                {
                    obl = static_cast<long long>(a[k]) + (long long)(a[k + 1]);
                }
                else if (o[k] == '-')
                {
                    obl = static_cast<long long>(a[k]) - (long long)(a[k + 1]);
                }
                else if (o[k] == '*')
                {
                    obl = static_cast<long long>(a[k]) * (long long)(a[k + 1]);
                }
                else
                {
                    cout << "BLAD - NIEZNANY OPERATOR: " << o[k] << '\n';
                    cout << "n o a " << n << ' ' << o[k] << ' ' << a[k] << '\n';
                }
                na[j] = obl % 1000000007;
                j -= 1;
            }
            else
            {
                na[j] = a[k];
                no[j] = o[k];
                cout << "J K NO O " << j << ' ' << k << ' ' << no[j] << ' ' << o[k] << '\n';
            }
            k++;
        }
        ret += rec (na , no , n - 1);
        ret = ret % 1000000007;
    }
    return ret;
}

int main ()
{
    int n;
    cin >> n;

    int* a = new int[n];
    char* o = new char[n - 1];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> o[i];
    }
    long long ret = rec (a , o , n);
    cout << ret << '\n';

}