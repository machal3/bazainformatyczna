#include <iostream>

using namespace std;

int k, minim;
int tab[1000001];
long long sum;

int f = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> k >> minim;

	for (int i = 1; i <= k; i++) {
		cin >> tab[i];

		if (tab[i] >= minim) {
			sum += (i - f) * (k - i + 1);
			f = i;
		}
	}

	cout << sum;
}
