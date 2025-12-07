#include <iostream>
using namespace std;
#include <vector>

int a , b;

int main ()
{
    std::ios_base::sync_with_stdio (false);
    std::cin.tie (NULL);

    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        vector<int> czynniki;
        int n = i;

        while (n % 2 == 0)
        {
            czynniki.push_back (2);
            n /= 2;
        }

        for (int j = 3; j * j <= n; j += 2)
        {
            while (n % j == 0)
            {
                czynniki.push_back (j);
                n /= j;
            }
        }
        if (n > 1)
        {
            czynniki.push_back (n);
        }

        if (!czynniki.empty ())
        {
            cout << czynniki.front ();
        }

        bool mmm = 0;
        for (int k : czynniki)
        {
            if (mmm)
            {
                cout << "*" << k;
            }
            mmm = 1;
        }

        cout << "\n";
    }

}