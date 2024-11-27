#include <iostream>
using namespace std;

int T;
int a , b , k;

int max (int a , int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int main ()
{
	cin.tie (0);
	ios::sync_with_stdio (0);

	cin >> T;

	while (T--)
	{
		int odp = 0;
		cin >> a >> b >> k;
		// for (int i = a; i < b; i++)
		// {
		// 	if (b / i >= k)
		// 	{
		// 		odp++;
		// 	}
		// }

		odp = max (b / k - a + 1 , 0);
		cout << odp << "\n";
	}

}