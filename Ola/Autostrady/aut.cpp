#include <iostream>
#include <vector>
using namespace std;

int R[500010];
bool odwiedzone[500010];
vector <int> krawedzie[500010];

int a , b;
int n , m , p;

void zapuszczamy (int w , int r)
{
    odwiedzone[w] = 1;
    R[w] = r;
    for (auto j : krawedzie[w])
    {
        if (!odwiedzone[j])
        {
            zapuszczamy (j , r);
        }
    }
}

int main ()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        krawedzie[a].push_back (b);
        krawedzie[b].push_back (a);
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (!odwiedzone[i])
        {
            zapuszczamy (i , i);
        }
    }

    cin >> p;

    while (p--)
    {
        cin >> a >> b;
        if (R[a] == R[b])
        {
            cout << "TAK\n";
        }
        else
        {
            cout << "NIE\n";
        }
    }

}