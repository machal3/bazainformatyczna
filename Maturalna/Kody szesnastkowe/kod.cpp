#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void rozklad_na_czynniki_pierwsze (int n)
{
    int temp_n = n;
    std::vector<int> czynniki;

    while (temp_n % 2 == 0)
    {
        czynniki.push_back (2);
        temp_n /= 2;
    }

    for (int i = 3; i * i <= temp_n; i += 2)
    {
        while (temp_n % i == 0)
        {
            czynniki.push_back (i);
            temp_n /= i;
        }
    }

    // 3. Jeśli pozostała wartość jest większa niż 1, jest to ostatni czynnik pierwszy
    if (temp_n > 1)
    {
        czynniki.push_back (temp_n);
    }

    // 4. Wypisanie wyniku zgodnie z formatem
    // Liczba 1 jest szczególnym przypadkiem, ale zgodnie z zakresem (a, b) nie powinna się pojawić 
    // dla a >= 2. W przykładzie pojawiła się dla 9 (9-3+1 = 7, więc 10? - Błąd w przykładzie lub jego interpretacji).
    // Założenie: Rozkład na czynniki 1 nie jest wymagany lub traktowany jako "1".
    if (n == 1)
    {
        std::cout << 1 << std::endl;
        return;
    }

    // Rozkład liczby złożonej (posiada co najmniej dwa czynniki lub jest większa niż 1 i ma tylko jeden czynnik
    // jeśli została rozłożona prawidłowo)
    if (!czynniki.empty ())
    {
        for (size_t i = 0; i < czynniki.size (); ++i)
        {
            std::cout << czynniki[i];
            if (i < czynniki.size () - 1)
            {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
    // To miejsce teoretycznie nie powinno być osiągnięte dla n >= 2, 
    // ponieważ każda taka liczba ma co najmniej jeden czynnik pierwszy.
    // Ale dodajemy go jako fallback na wypadek n=1 lub innej nieoczekiwanej sytuacji.
    else
    {
        std::cout << n << std::endl; // Jeśli z jakiegoś powodu lista jest pusta, wypiszemy liczbę
    }
}

/**
 * @brief Główna funkcja programu.
 * * Wczytuje dwie liczby a i b, a następnie iteruje po przedziale [a, b]
 * i dla każdej liczby wywołuje funkcję rozkładającą na czynniki pierwsze.
 */
int main ()
{
    // Optymalizacja wejścia/wyjścia (dobra praktyka, chociaż dla tego zadania opcjonalna)
    std::ios_base::sync_with_stdio (false);
    std::cin.tie (NULL);

    int a , b;

    // Wejście: dwie liczby całkowite a i b (2 <= a <= b <= 10^4)
    std::cin >> a >> b;

    for (int n = a; n <= b; ++n)
    {
        rozklad_na_czynniki_pierwsze (n);
    }

    return 0;
}