# Inwersje kontraatakują

Napisz program, który dla danego ciągu obliczy liczbę jego inwersji. Inwersją nazywamy taką parę (niekoniecznie kolejnych) indeksów $(i,j)$, że $i<j$, ale $a_i$ > $a_j$. Na przykład ciąg $(1,3,4,2)$ ma 2 inwersje: $(3,2)$ oraz $(4,2)$.

## Zadanie
Napisz program, który:
- wczyta ze standardowego wejścia ciąg liczb całkowitych,
- obliczy liczbę jej inwersji,
- wypisze wynik na standardowe wyjście.

## Wejście

W pierwszym wierszu wejścia znajduje się jedna liczba całkowita $n$, $(1 \leq n \leq 60000)$, oznaczająca liczbę elementów ciągu. Kolejnych n wierszy zawiera po jednej liczbie całkowitej $a_i$ $(-10^9 \leq ai \leq 10^9)$.

## Wyjście

W pierwszym i jedynym wierszu wyjścia należy wypisać jedną liczbę całkowitą, oznaczającą liczbę inwersji w podanym ciągu.

## Przykład

Dla danych wejściowych:

```
4
1
3
4
2
```

Poprawnym wynikiem jest:

```
2
```