#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
	int n , m , k;
	cin >> n >> m >> k;

	vector<vector<int>> las (n , vector<int> (m));
	for (int i = 0; i < n; ++i)
	{
		string row;
		cin >> row;
		for (int j = 0; j < m; ++j)
		{
			las[i][j] = row[j] - '0';
		}
	}

	// Tworzymy tablicę sum prefiksowych
	vector<vector<int>> prefix (n + 1 , vector<int> (m + 1 , 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			prefix[i][j] = las[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
		}
	}

	int max_area = 0;

	// Przeszukujemy wszystkie pary wierszy
	for (int top = 1; top <= n; ++top)
	{
		for (int bottom = top; bottom <= n; ++bottom)
		{
			int left = 1;
			for (int right = 1; right <= m; ++right)
			{
				// Liczymy liczbę jedynek w prostokącie
				int ones = prefix[bottom][right] - prefix[top - 1][right] - prefix[bottom][left - 1] + prefix[top - 1][left - 1];

				while (ones > k)
				{
					left++;
					ones = prefix[bottom][right] - prefix[top - 1][right] - prefix[bottom][left - 1] + prefix[top - 1][left - 1];
				}

				// Liczymy pole prostokąta
				int area = (bottom - top + 1) * (right - left + 1);
				max_area = max (max_area , area);
			}
		}
	}

	cout << max_area << endl;

	return 0;
}
