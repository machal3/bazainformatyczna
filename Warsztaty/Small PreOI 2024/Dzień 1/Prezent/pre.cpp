#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 998244353;

// Funkcja obliczająca liczbę potęg dwójki w przedziale [low, high]
int countPowersOfTwo (long long low , long long high)
{
    int count = 0;
    long long firstPower = 1LL << (int)ceil (log2 (low)); // Pierwsza potęga dwójki >= low
    for (long long power = firstPower; power <= high; power *= 2)
    {
        count++;
    }
    return count;
}

// Funkcja obliczająca resztę z dzielenia przez MOD
long long modExp (long long base , long long exp , long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main ()
{
    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    int n;
    cin >> n;

    vector<pair<long long , long long>> queries (n);
    for (int i = 0; i < n; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }

    for (const auto& query : queries)
    {
        long long p = query.first;
        long long k = query.second;

        // Obliczamy maksymalny rozmiar zbioru
        int maxSize = countPowersOfTwo (p , k);

        // Obliczamy liczbę możliwości
        long long possibilities = maxSize > 0 ? modExp (2 , maxSize - 1 , MOD) : 0;

        cout << maxSize << " " << possibilities << "\n";
    }

    return 0;
}
