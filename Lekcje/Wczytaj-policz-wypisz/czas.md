# Czas
## Limit pamięci: 256 MB
Napisz program, który przelicza czas podany w sekundach na zapis uwzględniający godziny, minuty oraz sekundy.

## Wejście
Jedyny wiersz wejścia zawiera jedną liczbę całkowitą $t$ $(1 \leq t \leq 1000000)$, oznaczającą czas wyrażony w sekundach.

## Wyjście
Twój program powinien wyrazić czas  w postaci , gdzie ,  i  oznaczają odpowiednio liczbę godzin, minut i sekund, i wypisać to wyrażenie na wyjście. Innymi słowy, $g$ godzin, $m$ minut i $s$ sekund powinno łącznie dawać $t$ sekund.

Liczby $g$, $m$ i $s$ powinny być całkowite i nieujemne, a liczby $m$ i $s$ nie powinny przekraczać 59. W żadnej z liczb nie należy wypisywać zer wiodących.

## Przykład
Dla danych wejściowych:

```
4000
```

poprawną odpowiedzią jest:

```
1g6m40s
```