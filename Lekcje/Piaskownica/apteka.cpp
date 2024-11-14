#include <iostream>
#include <algorithm>

using namespace std;

using namespace std;
long long k;
long long n = 0;
long long suma = 0;

pair <long long, long long> tab[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	n = k + 1;

	for (int i = 0; i < k; i++) {
		cin >> tab[i].first;
		tab[i].second = k - i;
	}

	sort(tab, tab + k);

	for (int i = 0; i < k; i++) {
		if (tab[i].second <= n) {
			suma += (tab[i].first * (n - tab[i].second));

			n = tab[i].second;


			if (tab[i].second == 1) {
				break;
			}

		}
		
	}

	cout << suma;
}
