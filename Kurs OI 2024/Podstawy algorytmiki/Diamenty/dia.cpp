#include <bits/stdc++.h>
using namespace std;


int dp[1001][1001];
int diamenty[10001][10001];

int x , y;
int T;

int wieksza (int a, int b){
	if(a > b){
		return a;
	}
	return b;
}


int main ()
{
	cin >> T;
	for(int d = 0; d < T; d++)
	{
		cin >> x >> y;

		for(int i = 1; i < x + 1; i++)
		{
			for(int j = 1; j < y + 1; j++)
			{
				cin >> diamenty[i][j];
			}
		}

		//depeczek
		
		for(int i = 1; i < x + 1; i++)
		{
			for(int j = 1; j < y + 1; j++)
			{
				dp[i][j] = wieksza(dp[i-1][j], dp[i][j-1]) + diamenty[i][j];
			}
		}

		cout << dp[x][y] << "\n";
	}


}
