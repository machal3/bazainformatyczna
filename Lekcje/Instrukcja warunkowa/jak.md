# Jakie to działanie?
## Limit pamięci: 256 MB

W tym zadaniu Twój program powinien rozwiązać łamigłówkę postaci:
$$a ? b == c$$

W tej łamigłówce , i będą danymi liczbami całkowitymi nieujemnymi, a Twoim zadaniem jest powiedzieć, jakie działanie należy wstawić zamiast znaku zapytania, aby zachodziła równość. Masz do dyspozycji omówione już działania języka C++:

- `+` (dodawanie),
- `-` (odejmowanie),
- `*` (mnożenie),
- `/` (dzielenie z resztą),
- `%` (reszta z dzielenia).

## Wejście

Pierwszy i jedyny wiersz wejścia zawiera trzy liczby całkowite $a,b ,c (0 \leq a, b, c \leq 1000)$, oddzielone pojedynczymi odstępami.
## Wyjście

Twój program powinien wypisać wiersz z rozwiązaniem łamigłówki, zastępując znak zapytania odpowiednim działaniem. Znak działania i znaki równości powinny być otoczone pojedynczymi odstępami.

Gwarantujemy, że dla każdej łamigłówki będzie co najmniej jedno rozwiązanie. Jeśli łamigłówka ma więcej niż jedno rozwiązanie, Twój program powinien wypisać **wszystkie** z nich, w osobnych wierszach, według kolejności działań wypisanej powyżej.
## Przykład

Dla danych wejściowych:
```
2 3 6
```
poprawną odpowiedzią jest:
```
2 * 3 == 6
```
a dla danych wejściowych:
```
5 0 5
```
poprawnym wynikiem jest:
```
5 + 0 == 5
5 - 0 == 5
```
**Uwaga:** Pamiętaj, że nie wolno dzielić przez zero!
