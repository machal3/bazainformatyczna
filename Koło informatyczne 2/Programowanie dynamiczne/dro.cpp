#include <iostream>

using namespace std;

int n;
int tablica[10000][10000];
bool tab[100000][100000];

int main () {
	cin >> n;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> tab[i][j];
		}
	}

	tablica[1][1] = 1;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (tab[i][j] == 0) {
				tablica[i][j] += tablica[i][j - 1] + tablica[i - 1][j] % 1000000;
			}
		}
	}

	cout << tablica[n][n];
}




