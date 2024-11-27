#include <bits/stdc++.h>
using namespace std;

int n;

void binarny (int a)
{
    if (a == 0)
    {
        return;
    }
    binarny (a / 2);
    cout << a % 2;
}

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 0)
            cout << 0;

        else
            binarny (a);

        cout << "\n";


    }
}