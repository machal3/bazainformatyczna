#include <iostream>
using namespace std;

main ()
{
    int x;
    cin >> x;
    int a = (x - (x % 100)) / 100;
    int b = ((x - a * 100) - ((x - 100 * a) % 10)) / 10;
    int c = x - ((a * 100) + (b * 10));

    cout << (100 * c) + (10 * b) + (a);
}