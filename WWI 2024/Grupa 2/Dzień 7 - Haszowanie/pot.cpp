#include <iostream>

using namespace std;

long long n;
long long a , b;
long long pom;

long long SpotR (long long a , long long k)
{
	if (k == 0)
	{
		return 1;
	}

	if ((k % 2) == 1)
	{
		return (a * SpotR (a , k - 1)) % int (1e9 + 7);
	}

	else
	{
		pom = SpotR (a , k / 2);
		return (pom * pom) % int (1e9 + 7);
	}
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << SpotR (a , b) % int (1e9 + 7) << "\n";
	}
}
