#include <iostream>

using namespace std;
int rok;

int main ()
{
    cin >> rok;

    if (rok % 4 == 0 && (rok % 100 != 0 || rok % 400 == 0))
    {
        cout << "TAK\n";
    }
    else
    {
        cout << "NIE\n";
    }
}