# Koło
## Limit pamięci: 256 MB
Zadaniem Twojego programu będzie obliczenie pola i obwodu koła o zadanym promieniu. Interesuje nas wynik z dokładnością do trzech cyfr po kropce dziesiętnej.

## Wejście
Na wejściu znajduje się jedna liczba rzeczywista $r$ $(0 < r \leq 1000)$, będąca długością promienia koła.

Wyjście
W pierwszym wierszu należy wypisać pole koła o promieniu  z dokładnością do 3 miejsc po kropce dziesiętnej, a w drugim wierszu należy wypisać długość obwodu tego koła również z dokładnością do 3 miejsc po kropce.

Przykład
Dla danych wejściowych:

```
10.0
```

poprawną odpowiedzią jest:

```
314.159
62.832
```
Wskazówka: W pliku nagłówkowym `cmath` dostępne jest dobre przybliżenie liczby $\Pi$ `(stała M_PI)`. Możesz też użyć własnego przybliżenia liczby $\Pi$; pamiętaj jednak, że powinno być możliwie dokładne, tak aby wynik dla koła o maksymalnym możliwym w tym zadaniu promieniu był poprawny z dokładnością do 3 cyfr po kropce.