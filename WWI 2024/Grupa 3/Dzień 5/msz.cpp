#include <iostream>

#include <vector>
#include <stack>

using namespace std;

// nie drzewo
//struct dewo
//{
//	// nie synowie
//	vector<dewo*> syni;
//	bool kugel;
//	int numel;
//};

// nie wierzcho³ek
struct wiezholeg
{
    // kule w dul
    vector<int> dul;
    // kule w gure
    vector<int> gura;
};

int main ()
{
    int n , q;
    cin >> n >> q;

    auto g = new wiezholeg[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 0)
        {
            continue;
        }
        a -= 1;
        g[i].gura.push_back (a);
        g[a].dul.push_back (i);
    }

    for (int i = 0; i < q; i++)
    {
        int a , b;
        cin >> a >> b;
        if (a == 1)
        {
            stack<int> dfs;
            dfs.push (0);
            while (b > 0)
            {
                for (int j = 0; j < g[dfs.top ()].dul.size (); j++)
                {
                    if ()
                }
            }
        }
        else if (a == 2)
        {

        }
        else
        {
            cout << "NIEZNANE A\n";
        }
    }

}