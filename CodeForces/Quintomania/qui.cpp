#include <iostream>
using namespace std;

int a , b;
int n;
int p;

int mod (int a , int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

int main ()
{
    cin >> p;

    for (int j = 0; j < p; j++)
    {

        cin >> n;
        bool dasie = 0;

        cin >> b;

        for (int i = 1; i < n; i++)
        {
            cin >> a;

            if (mod (a , b) != 5 && mod (a , b) != 7)
            {
                dasie = 1;
            }
            b = a;
        }

        if (dasie == 0)
            cout << "YES\n";

        else
            cout << "NO\n";

    }
}