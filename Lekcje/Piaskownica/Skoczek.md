# (K,N)-skoczek [B]
## Limit pamięci: 32 MB
Jedną z najdziwniejszych odmian szachów na świecie są szachy bajtockie. Rozegranie partii stanowi poważną trudność, gdyż gra toczy się na nieskończonej szachownicy. Podstawową umiejętnością, której uczą się młodzi pasjonaci szachów bajtockich, jest rozpatrywanie możliwych sytuacji na planszy po wielu milionach posunięć. W tym celu muszą wiedzieć, czy dana figura może przejść pomiędzy dwoma wskazanymi polami.

Najmocniejszą spośród figur w szachach bajtockich jest $(K, N)$-skoczek. Jego ruchy przypominają nieco ruchy skoczka w klasycznych szachach (niepoprawnie zwanego czasem konikiem). W każdym ruchu może on wykonać jedno z dwóch posunięć: przesunąć się o $K$ pól w pionie, a następnie o $N$ pól w poziomie albo najpierw przesunąć się o $N$ pól w pionie, a następnie o $K$ pól w poziomie. Skoczka z szachów klasycznych można więc uznać za $(2,1)$-skoczka lub $(1,2)$-skoczka.

Dla podanych dwóch pól na planszy należy stwierdzić, czy -skoczek może przejść pomiędzy nimi (liczba skoków potrzebnych do wykonania tego przejścia jest nieistotna).

Wejście
W pierwszym wierszu standardowego wejścia znajduje się liczba całkowita $T$ $(1 \leq T \leq 20000)$ oznaczająca liczbę zestawów testowych. W każdym z kolejnych $T$ wierszy znajduje się opis jednego zestawu w postaci sześciu liczb całkowitych $K$, $N$, $x_1$, $x_2$, $y_1$, $y_2$ $(0 \leq K, N \leq 10^9, K + N > 0, -10^9 \leq x_1, y_1, x_2, y_2 \leq 10^9)$ pooddzielanych pojedynczymi odstępami. $K$ i $N$ opisują dopuszczalne ruchy skoczka. Początkowo skoczek znajduje się na polu o współrzędnych $(x_1, y_1)$. Należy stwierdzić, czy może on dojść do pola o współrzędnych $(x_2, y_2)$ .

## Wyjście
Dla każdego zestawu testowego na standardowe wyjście wypisz dokładnie jeden wiersz ze słowem `TAK` lub `NIE`, w zależności od tego, czy $(K, N)$-skoczek znajdujący się na polu $(x_1 , y_1)$ może dostać się do pola $(x_2, y_2)$.

## Przykład

Dla danych wejściowych:

```
3
2 1 0 0 3 3
1 1 1 1 1 2
1 0 2 3 4 6
```

poprawną odpowiedzią jest:

```
TAK
NIE
TAK
```
