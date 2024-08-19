# Apteka
## Limit pamięci: 32 MB

Jaś stoi ostatni w kolejce do apteki. Ponieważ Jasiowi bardzo się śpieszy, to postanowił, że spróbuje się pozamieniać miejscami z niektórymi osobami, nawet jeśli musiałby za to zapłacić.

Każda osoba jest chętna do zamiany, ale $i$ - tej osobie za przesunięcie o każde jedno miejsce dalej w kolejce trzeba zapłacić $c_{1}$. Dokładniej, jeśli Jaś jest $k$ miejsc $(k > 0)$ dalej od kasy niż pewna osoba i jeśli chce się z nią zamienić miejscami, to musi jej zapłacić kwotę $k \cdot c_1$ .

Jaś chciałby być pierwszy w kolejce i zastanawia się, jak dokonywać zamian, aby wydać jak najmniej.

## Wejście

Pierwszy wiersz standardowego wejścia zawiera jedną liczbę całkowitą (), oznaczającą liczbę osób, które stoją przed Jasiem w kolejce do apteki.

Następny wiersz wejścia zawiera liczb całkowitych (), gdzie oznacza kwotę, jaką Jaś musi zapłacić -tej osobie za przesunięcie o każde miejsce dalej w kolejce. Kolejność osób liczona jest od osoby, za którą bezpośrednio stoi Jaś, a więc od końca kolejki do jej początku.

Możesz założyć, że w przynajmniej przypadków testowych zachodzi warunek: .
## Wyjście

Pierwszy i jedyny wiersz standardowego wyjścia powinien zawierać jedną liczbę całkowitą, równą minimalnej kwocie, jaką Jaś musi zapłacić, aby być pierwszym w kolejce.

## Przykład

Dla danych wejściowych:

```
4
5 2 4 3
```

poprawną odpowiedzią jest:

```
10
```

**Wyjaśnienie do przykładu:** Jaś zamieni się najpierw z osobą w kolejce za kwotę , a następnie z pierwszą osobą w kolejce za kwotę .

Autor zadania: Jacek Tomasiewicz.