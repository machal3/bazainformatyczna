#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool comp (pair<string , void*> a , pair<string , void*> b)
{
    if (a.first.size () < b.first.size ())
    {
        return true;
    }
    return false;
}

int main ()
{
    int n;
    cin >> n;
    auto s = new pair<string , void*>[n];

    for (int i = 0; i < n; i++)
    {
        getline (cin , s[i].first);
    }

    sort (s , s + n , comp);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool pref = s[j].first.compare (0 , s[i].first.size () , s[i].first);
            bool suff = s[j].first.compare (s[j].first.size () - s[i].first.size () , s[i].first.size () , s[i].first)
        }
    }
}