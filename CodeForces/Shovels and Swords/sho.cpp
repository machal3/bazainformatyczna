#include <iostream>
using namespace std;

int p;

int main ()
{
    cin >> p;

    for (int i = 0; i < p; i++)
    {
        int a , b;
        cin >> a >> b;

        cout << min ((a + b) / 3 , min (a , b)) << "\n";

    }
}