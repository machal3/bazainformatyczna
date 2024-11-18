# Domek z kart
# Limit pamięci: 32 MB

Marcel dostał w tym roku na urodziny talię bardzo specyficznych kart. Nie służą one do gry, lecz do budowania domków z kart. Zaraz po rozpakowaniu prezentu niecierpliwy Marcel zbudował ogromną wieżę. Zrobił to w następujący sposób: w pierwszej kolejności opierał karty parami o siebie, następnie na powstałych szczytach stawiał kolejne karty, znów opierając je parami o siebie, i tak dalej. Okazało się, że na każdym piętrze, poza ostatnim, liczba szczytów była parzysta, więc zawsze dało się poprawnie zbudować wyższe piętro.

Każda z kart w talii ma swoją wartość. Teraz Marcel żałuje, że nie przemyślał lepiej swojej konstrukcji i zużył zbyt dużo wartościowych kart. Znając wartość każdej karty, chciałby zdjąć nie więcej niż  kart z wieży tak, aby suma ich wartości była jak największa. Oczywiście domek z kart nie może się przy tym zawalić!

Aby po wyjęciu kart domek nadal był stabilny, Marcel nie może nigdy zdjąć pojedynczej karty, nie wyjmując zarazem jej pary (tzn. tej karty, z którą nawzajem się podpierają). Ponadto nigdy nie może zdjąć karty, nie zdjąwszy wcześniej wszystkich kart, które są wyżej od niej i pośrednio lub bezpośrednio są o nią oparte.

## Wejście

W pierwszym wierszu standardowego wejścia znajdują się dwie liczby całkowite $n$ i $k$ oznaczające odpowiednio liczbę pięter karcianej wieży i maksymalną liczbę kart, które Marcel może zdjąć. Ponieważ karty można zdejmować tylko w parach, to $k$ będzie zawsze parzyste.

Kolejne  wierszy wejścia zawiera opisy poszczególnych pięter wieży od najwyższego do najniższego. W $(i+1)$-szym wierszu znajduje się $2^i$ liczb całkowitych $a_{i, 1} ,a_{i, 2} , ..., a_{i,j}$, oznaczających wartości kart na $i$-tym piętrze od góry, w kolejności od lewej do prawej.

W testach wartych łącznie 50% punktów zachodzą dodatkowe ograniczenia: $n \leq 8$, $k \leq 30$, .

Wyjście
Twój program powinien wypisać na standardowe wyjście dokładnie jedną liczbę całkowitą - maksymalną sumę wartości kart, jaką Marcel może odzyskać, wyjmując maksymalnie  kart z wieży, tak aby ta się nie zawaliła.

## Przykład

Dla danych wejściowych:

```
3 6
1 -3
-10 1 2 1
1 1 3 2 -1 5 2 -3
```

poprawną odpowiedzią jest:

```
5
```