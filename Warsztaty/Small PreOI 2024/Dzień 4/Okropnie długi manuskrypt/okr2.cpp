#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Funkcja sprawdzająca czy dany fragment ma okres długości p
bool checkPeriod (const string& s , int start , int end , int p)
{
    for (int i = start + p; i <= end; i++)
    {
        if (s[i] != s[i - p]) return false;
    }
    return true;
}

// Funkcja znajdująca najkrótszy okres
int findShortestPeriod (const string& s , int start , int end)
{
    int len = end - start + 1;

    // Sprawdzamy wszystkie możliwe długości okresu (muszą być dzielnikami długości fragmentu)
    for (int i = 1; i * i <= len; i++)
    {
        if (len % i == 0)
        {
            // Sprawdzamy najpierw mniejszy dzielnik
            if (checkPeriod (s , start , end , i))
            {
                return i;
            }

            // Sprawdzamy większy dzielnik (jeśli jest różny od mniejszego)
            int other = len / i;
            if (other != i && checkPeriod (s , start , end , other))
            {
                return other;
            }
        }
    }

    return len;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    int n;
    cin >> n;

    string text;
    cin >> text;

    int q;
    cin >> q;

    while (q--)
    {
        int a , b;
        cin >> a >> b;
        cout << findShortestPeriod (text , a - 1 , b - 1) << '\n';
    }

    return 0;
}