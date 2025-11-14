#include <iostream>
#include <queue>
using namespace std;

priority_queue<int , vector<int> , greater<int>> kolejka;

int n;
int x , y;

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);

    cin >> n;

    while (n--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            kolejka.push (y);
        }
        else
        {
            cout << kolejka.top () << "\n";
            kolejka.pop ();
        }

    }
}