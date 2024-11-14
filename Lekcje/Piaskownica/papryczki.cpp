#include <iostream>
#include<cmath>
using namespace std;

long long pot(long long a, long long n)
{
	long long w = 1;
	while(n>0)
	{
		if(n%2 == 1) w *= a;
		a*= a;
		n/=2;
	}
	return w;
}

int ilosc[1000];

main(){

    int k;
    cin >> k;
    k=k+1;

    for (int i=0; i != k; i++)
    {
        cin>>ilosc[i];
    }
    int x;
    x = 0;
    int y;
    y = 0;

    while(x != k)
    {
        y = (y + ilosc[x]*(pot(2,x)));
        x++;
    }

cout << y+1;
}
