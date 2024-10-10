#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    // Wczytanie danych
    int n , m;
    cin >> n >> m;

    vector<int> masy (n + 1);
    vector<int> wartosci (n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> masy[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> wartosci[i];
    }

    vector<vector<int>> tab (n + 1 , vector<int> (m + 1 , 0));

    vector<vector<bool>> wybrany (n + 1 , vector<bool> (m + 1 , false));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            tab[i][j] = tab[i - 1][j];

            if (j >= masy[i])
            {
                if (tab[i][j] < tab[i - 1][j - masy[i]] + wartosci[i])
                {
                    tab[i][j] = tab[i - 1][j - masy[i]] + wartosci[i];
                    wybrany[i][j] = true;
                }
            }

        }
    }


    int maksym = tab[n][m];
    cout << maksym << endl;

    vector<int> wziete;
    int w = m;

    for (int i = n; i >= 1; i--)
    {
        if (wybrany[i][w])
        {
            wziete.push_back (i);
            w -= masy[i];
        }
    }

    cout << wziete.size () << endl;

    for (int i = wziete.size () - 1; i >= 0; i--)
    {
        cout << wziete[i] << " ";
    }
    cout << endl;
}
