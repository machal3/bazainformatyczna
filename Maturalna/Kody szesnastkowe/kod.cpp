#include <iostream>
using namespace std;

string wczyt;
int odp;

int main ()
{
    cin >> wczyt;

    if (wczyt[1] > '0' - 1 && wczyt[1] < '9' + 1)
    {
        odp += (wczyt[1] - '0');
    }
    else
    {
        odp += (wczyt[1] - 'A' + 10);
    }

    odp += (wczyt[0] - '0') * 16;

    cout << odp << "\n";

    cout << char (odp);
}