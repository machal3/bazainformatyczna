#include <bits/stdc++.h>
using namespace std;


int dp[1001][1001];
int diamenty[1001][1001];

int x , y;
int T;

int wieksza (int a , int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;

	}
}


int main ()
{
	cin >> T;

	while (T--)
	{
		cin >> x >> y;

		for (int i = 1; i < y + 1; i++)
		{
			for (int j = 1; j < x + 1; j++)
			{
				cin >> diamenty[i][j];
			}
		}

		//depeczek

		for (int i = 1; i < y + 1; i++)
		{
			for (int j = 1; j < x + 1; j++)
			{
				dp[i][j] = wieksza (dp[i - 1][j] , dp[i][j - 1]) + diamenty[i][j];
			}
		}

		cout << dp[y][x] << "\n";
	}


}
