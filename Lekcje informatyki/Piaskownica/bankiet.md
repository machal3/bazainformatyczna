# Bankiet
## Limit pamięci: 32 MB

W restauracji Utalentowany Miś zaplanowano bankiet dla finalistów OIG. Goście zasiądą przy okrągłych stołach w ściśle określony sposób. Kierownik sali otrzymał listę gości wraz z informacją, kto ma siedzieć z lewej strony każdego z nich. Ile stołów musi przygotować na bankiet?
Zadanie

Opracuj program, który:

- wczyta ze standardowego wejścia informacje o rozmieszczeniu gości,
- obliczy ile stołów trzeba przygotować,
- wypisze wynik na standardowe wyjście.

## Wejście

W pierwszym wierszu zapisano liczbę gości $N (1 \leq N \leq )$. Goście są ponumerowani kolejnymi liczbami naturalnymi od $1$ do $N$. W drugim wierszu zapisano numer gościa siedzącego po lewej stronie pierwszego gościa. w trzecim wierszu zapisano numer gościa siedzącego po lewej stronie drugiego gościa itd. W $i$-tym wierszu zapisano numer gościa siedzącego po lewej stronie $(i-1)$-tego gościa. W $N+1$-szym wierszu zapisano numer gościa siedzącego po lewej stronie $N$-tego gościa.

## Wyjście
W pierwszym wierszu wypisz liczbę stolików potrzebnych do usadzenia wszystkich gości.

## Przykład

Dla danych wejściowych:
```
12
4
10
7
3
2
6
1
5
11
8
12
9
```

poprawną odpowiedzią jest:
```
4
```

