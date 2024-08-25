#include <iostream>
#include <algorithm>

using namespace std;

int k, l = 0, p, s, powtorzenia;

long long tab[1000000];
long long x;
int minim, maxim;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> tab[i];
	}

	sort(tab, tab + k);

	cin >> powtorzenia;

	for (int i = 0; i < powtorzenia; i++) {
		cin >> x;

		l = 0;
		p = k;

		while (l < p) {
			s = (l + p) / 2;

			if (tab[s] < x) {
				l = s + 1;
			}

			else {
				p = s;
			}
		}
		
		minim = l;

		l = 0;
		p = k;

		while (l < p) {
			s = (l + p) / 2;

			if (tab[s] > x) {
				p = s;
			}

			else {
				l = s + 1;
			}
		}

		maxim = p - 1;

		if (tab[minim] == x) {
			cout << maxim - minim + 1 << endl;
		}

		else {
			cout << "0"<<endl;
		}
		

	}
}
