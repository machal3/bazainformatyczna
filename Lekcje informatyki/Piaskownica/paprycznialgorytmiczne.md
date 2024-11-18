# Papryczki logarytmiczne
Hitem sezonu w bajtockim warzywniaku są papryczki logarytmiczne. Jak sama nazwa wskazuje, wagi papryczek, wyrażone w gramach, są wyłącznie potęgami dwójki między $2^a$ a $2^k$.

![papryczki](https://www.agrofakt.pl/wp-content/uploads/2024/01/produkcja-papryki.jpg)


Typowy przebieg transakcji w warzywniaku wygląda tak, że klient prosi o $x$ gramów papryczek i sprzedawca wydaje mu dokładnie taką ich masę, posługując się wyłącznie całymi papryczkami. Może się niestety tak zdarzyć, że zamówienie klienta będzie niemożliwe do spełnienia. Pomóż sprzedawcy sprawdzić, na ile jest on zabezpieczony przed taką feralną sytuacją, czyli wyznaczyć najmniejszą taką liczbę naturalną $x$ z zamówienia nie do zrealizowania.

## Zadanie
Napisz program, który:

- wczyta ze standardowego wejścia opis aktualnego stanu warzywniaka,
- wyznaczy wartość $x$ z najgorszych koszmarów sprzedawcy,
- wypisze wynik na standardowe wyjście.

## Wejście

Pierwszy wiersz wejścia zawiera jedną liczbę całkowitą $k$ (1 \leq k \leq 10), oznaczającą, że masy papryczek znajdujących się na stanie warzywniaka to $2^a, 2^1, ..., 2^k$. Drugi wiersz zawiera $k+1$ liczb całkowitych dodatnich $p_a, p_1, ..., p_k$ nie większych niż $1000$, pooddzielanych pojedynczymi odstępami i oznaczających dokładny stan sklepu:  $p_a$ papryczek o wadze $1$, $p_1$ - o wadze 2, ...,  $p_k$ - o wadze $2^k$.

## Wyjście

Pierwszy i jedyny wiersz wejścia powinien zawierać jedną liczbę całkowitą dodatnią $x$ - najmniejszą wartość zamówienia, której sprzedawca nie będzie w stanie zrealizować.

## Przykład
Dla danych wejściowych:
```
2
2 1 1
```

poprawną odpowiedzią jest:

```
9
```

Wyjaśnienie do przykładu: Wszystkie wartości x od 1 do 8 można osiągnąć przy aktualnym stanie sklepu; oto przykładowe takie przedstawienia: $1 = 1$, $2 = 1 + 1$, $3 = 1 +2$ itd. Wartości $x=9$ oczywiście nie da się wyrazić.