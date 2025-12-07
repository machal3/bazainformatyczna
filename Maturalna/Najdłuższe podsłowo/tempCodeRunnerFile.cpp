#include <iostream>
#inlcude <string>
using namespace std;

string wczyt;
int o;
int naj;

int main ()
{
    cin >> wczyt;

    for (char g : wczyt)
    {
        if (g == 'a')
        {
            o++;
            if (o > naj)
            {
                naj = o;
            }
        }
        else
        {
            o = 0;
        }
    }

    for (naj--)
    {
        cout << 'a';
    }
}