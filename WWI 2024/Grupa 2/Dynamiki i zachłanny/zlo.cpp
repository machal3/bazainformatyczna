#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, B;
    cin >> n >> B;
    vector<int> m(n), v(n);
    for (int i = 0; i < n; ++i) cin >> m[i];
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<int> dp(B + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = B; j >= m[i]; --j) {
            dp[j] = max(dp[j], dp[j - m[i]] + v[i]);
        }
    }

    vector<int> results(n, 0);

    for (int i = 0; i < n; ++i) {
        vector<int> dp_without(B + 1, 0);

        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            for (int k = B; k >= m[j]; --k) {
                dp_without[k] = max(dp_without[k], dp_without[k - m[j]] + v[j]);
            }
        }

        results[i] = dp_without[B];
    }

    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
}
