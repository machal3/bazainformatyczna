#include <iostream>
using namespace std;

bool juzwdol = false;

int n;
int a;
int b;

int main ()
{
    cin >> n;
    cin >> a;
    n--;
    while (n--)
    {
        cin >> b;
        if (juzwdol)
        {
            if (b >= a)
            {
                cout << "NIE";
                return 0;
            }
        }
        else
        {
            if (b == a)
            {
                cout << "NIE";
                return 0;
            }
            if (b < a)
            {
                juzwdol = true;
            }
        }
        a = b;
    }

    cout << "TAK";
}