#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double x;

int main () {
    cin >> x;
    cout << setprecision (3) << fixed << (x * x) * M_PI << '\n';;
    cout << setprecision (3) << fixed << 2 * x * M_PI << '\n';
}