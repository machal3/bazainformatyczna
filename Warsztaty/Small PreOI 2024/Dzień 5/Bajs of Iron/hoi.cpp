#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 5;

vector<int> tree[MAXN]; // Lista sąsiedztwa dla drzewa
int dopamine[MAXN];     // Dopamina dla każdego węzła
long long dp[MAXN][2];  // DP dla maksymalnej dopaminy z równoważnym przydziałem kampanii
int n , k;               // Liczba węzłów i kampanii

void dfs (int node)
{
    vector<pair<long long , long long>> children_results; // Wyniki dzieci (dp[x][0], dp[x][1])

    for (int child : tree[node])
    {
        dfs (child);
        children_results.push_back ({ dp[child][0], dp[child][1] });
    }

    sort (children_results.rbegin () , children_results.rend () ,
         [](pair<long long , long long>& a , pair<long long , long long>& b)
 {
     return a.first - a.second > b.first - b.second;
         });

    // Obliczanie dp[node][0] i dp[node][1]
    dp[node][0] = 0;
    dp[node][1] = dopamine[node];

    int remaining_k = k - 1;
    for (auto [max_eq , max_plus_one] : children_results)
    {
        if (remaining_k > 0)
        {
            dp[node][1] += max_plus_one;
            dp[node][0] += max_eq;
            remaining_k--;
        }
        else
        {
            dp[node][0] += max_eq;
        }
    }
}

int main ()
{
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        int parent , dop;
        cin >> parent >> dop;

        dopamine[i] = dop;

        if (parent != 0)
        {
            tree[parent].push_back (i);
        }
    }

    dfs (1);

    cout << dp[1][1] << endl;

    return 0;
}
