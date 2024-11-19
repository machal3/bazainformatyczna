#include <iostream>
using namespace std;

int n;
int odp;


int jedenosiem;
int dwajeden;
int dwapiec;

int obecny;

int main ()
{
	cin >> n;
	jedenosiem = n;
	dwajeden = n;
	dwapiec = n;

	while (jedenosiem != 0 || dwajeden != 0 || dwapiec != 0)
	{
		odp++;
		obecny = 60;

		while (dwapiec != 0)
		{
			if (obecny < 25)
			{
				break;
			}

			else
			{
				dwapiec--;
				obecny -= 25;
			}
		}

		while (dwajeden != 0)
		{
			if (obecny < 21)
			{
				break;
			}
			else
			{
				dwajeden--;
				obecny -= 21;
			}
		}

		while (jedenosiem != 0)
		{
			if (obecny < 18)
			{
				break;
			}
			else
			{
				jedenosiem--;
				obecny -= 18;
			}
		}
	}


	cout << odp;
}
