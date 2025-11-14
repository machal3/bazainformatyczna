#include <iostream>
#include <queue>
using namespace std;

priority_queue<int , vector<int> , greater<int>> krawedzie[1000050];

int n , m;
int a , b;

int main ()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        krawedzie[a].push (b);
        krawedzie[b].push (a);
    }

    for (int i = 1; i < n + 1; i++)
    {
        cout << i << ": ";
        while (!krawedzie[i].empty ())
        {
            cout << krawedzie[i].top () << " ";
            krawedzie[i].pop ();
        }
        cout << "\n";

    }
}