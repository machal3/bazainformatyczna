#include <iostream>
#include <cmath>
using namespace std;

int n;
int m = 1;

int main ()
{
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 2; i <= sqrt (n); i++)
    {
        if (n % i == 0)
        {
            m += i;

            if (i != n / i)
                m += n / i;
        }
    }

    if (m == n)
    {
        cout << "TAK";
    }
    else
    {
        cout << m;
    }
}