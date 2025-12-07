#include <iostream>
using namespace std;
#include <string>

int d;
string s;
int k1 , k2;

bool czymniejszy (int d , string s , int k1 , int k2)
{
    int i = k1;
    int j = k2;
    while (i <= d && j <= d)
    {
        if (s[i] == s[j])
        {
            i++;
            j++;
        }
        else if (s[i] < s[j])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (j <= d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main ()
{
    cin >> d;
    cin >> s;
    cin >> k1 >> k2;

    if (czymniejszy (d , s , k1 , k2))
    {
        cout << "TAK\n";
    }
    else
    {
        cout << "NIE\n";
    }
}