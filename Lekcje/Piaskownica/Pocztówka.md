# Pocztówka
## Limit pamięci: 32 MB
W czasie ferii zimowych w górach Wojtek kupił ogromną pocztówkę z panoramą gór. Po powrocie do domu oprawił ją w ramkę i powiesił na ścianie, aby móc ją codziennie podziwiać. Jednak po kilku tygodniach znudził się widokiem z pocztówki.

Pamiątka z gór już miała powędrować na strych, kiedy Wojtek wpadł na genialny pomysł, aby odciąć kilka gór z lewej strony i kilka z prawej i otrzymać nową, ciekawszą panoramę. Jednak gdyby odciął za dużo, nowy widok mógłby być mało efektowny. Aby temu zapobiec, Wojtek chciałby zostawić na pocztówce co najmniej jedną górę o wysokości nie mniejszej niż $m$.

Teraz Wojtek musi wybrać najładniejszą z możliwych kompozycji. Jednak nie wie jeszcze, jak trudne jest to zadanie - aby go o tym przekonać, policz, na ile sposobów może otrzymać nową, ciekawszą panoramę. W szczególności powinieneś uwzględnić, że Wojtek może się rozmyślić i pozostawić pocztówkę w stanie niezmienionym, o ile tylko zawiera ona górę wysokości co najmniej $m$.

## Wejście
W pierwszym wierszu standardowego wejścia znajdują się dwie liczby całkowite $n$ i $m$ $(1 \leq n \leq 1000000, 1 \leq m \leq 1000000000)$, oddzielone pojedynczym odstępem i oznaczające odpowiednio liczbę gór na pocztówce i minimalną wysokość góry, która czyni panoramę efektowną. Drugi wiersz zawiera $n$ liczb całkowitych $h_i$ $(1 \leq h_i,1000000000, h_i \neq h_j$ dla $i \neq j)$, pooddzielanych pojedynczymi odstępami. Są to wysokości gór w kolejności od lewej do prawej.

W testach wartych co najmniej $20\%$ punktów zachodzi $n \leq 100$, a w testach wartych co najmniej $50\%$ punktów - $n \leq 25000$.

## Wyjście
Na standardowe wyjście Twój program powinien wypisać dokładnie jedną liczbę całkowitą - liczbę wszystkich kompozycji, które spełniają podane warunki.

## Przykład
Dla danych wejściowych:
```
5 100
80 102 90 98 100
```
poprawną odpowiedzią jest:
```
11
```

## Komentarz do przykładu
Następujące jedenaście kompozycji spełnia warunki zadania:
```
80 102 90 98 100
102 90 98 100
90 98 100
98 100
100
80 102 90 98
80 102 90
80 102
102 90 98
102 90
102
```

