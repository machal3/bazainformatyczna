#include <bits/stdc++.h>

using namespace std;

string s;
int n;
int q;
int a , b;
int tym;


vector<int> prefiksowanie (string& sztring)
{
    int dlugosc = sztring.size ();
    vector<int> prefiks (dlugosc , 0);

    for (int i = 1 , k = 0; i < dlugosc; i++)
    {
        while (k > 0 && sztring[i] != sztring[k])
        {
            k = prefiks[k - 1];
        }

        if (sztring[i] == sztring[k])
        {
            k++;
        }

        prefiks[i] = k;
    }

    return prefiks;
}

int main ()
{
    ios::sync_with_stdio (0);
    cin.tie (0);

    cin >> n;
    cin >> s;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        string fragment = s.substr (a - 1 , b - a + 1);

        vector<int> prefiks = prefiksowanie (fragment);

        n = fragment.size ();
        tym = n - prefiks[n - 1];

        if (n % tym == 0)
        {
            cout << tym << "\n";
        }

        else
        {
            cout << n << "\n";
        }
    }

}
