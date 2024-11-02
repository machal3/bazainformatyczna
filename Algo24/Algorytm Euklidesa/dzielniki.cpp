#include <iostream>
using namespace std;

int n;
int duzoliczbpierwszych[1000000] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233 };
int ilosc_dzielnikow;
int ilosc[1000000];
int p;
long long odp;

int main ()
{
    cin >> n;
    n--;

    while (n == 0)
    {
        if (n - ilosc_dzielnikow - 1 >= 0)
        {
            ilosc[p]++;
            p++;
            ilosc_dzielnikow++;
        }
        else
        {
            p = 0;
            ilosc[p]++;
            ilosc_dzielnikow++;
        }

    }

}