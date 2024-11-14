# Mury
## (Limit pamięci: 32MB)
Wywiad Cesarstwa Bajtocji doniósł, że jej odwieczny wróg - Bitocja - chce przejąć kontrolę na strategicznie ważnym wąwozem łączącym oba państwa i wznieść tam fortyfikacje. Bajtocja musi szybko zaatakować i zniweczyć działania wroga, aby nie stracić kontroli na regionem.

Wąwóz prowadzi z zachodu na wschód (Bajtocja atakuje z zachodu), Bitocja planuje przegrodzić go $N$ równoległymi murami (prostopadłymi do wąwozu). Gdy ukończą budowę, forteca będzie nie do pokonania, ale teraz mury nie są jeszcze doskonałe i istnieje szansa ich sforsowania. Prace na murami zostały rozpoczęte od obu stron wąwozu. Mury na nieparzystych pozycjach (zaczynamy od 1) są budowane od południa, a te na parzystych pozycjach od północy. (Pierwszy mur jest od południa a potem na przemian).

Atak ma poprowadzić Bajtokles, który jako heros posiada moc strzelania piorunami, dzięki czemu może robić wyrwy w murach. W bitewnym szale nie myśli on jednak o unikaniu przeszkód, które mógłby wyminąć bokiem - biegnie prosto przed siebię (równolegle do ścian wąwozu).

Stratedzy znają położenie murów - dla każdego wiedzą jak długi odcinek został zbudowany (mury zaczynają się przy ścianach wąwozu). Szukają najlepszego miejsca do przeprowadzenia ataku - czyli takiego, żeby Bajtokles musiał przebić się przez jak najmniejszą liczbę murów. Znajdź:

- najmniejszą liczbę murów, które musi przebić Bajtokles aby sforsować fortyfikacje
- ile jest miejsc o takiej (najmniejszej) liczbie murów do przebicia (bo im więcej, tym trudniej wrogowi przewidzieć, gdzię nastąpi atak).

Pozycje liczymy od południa (najbardziej na południe jest pozycja 1). Wąwóz ma szerokość $H$ (najbardziej na północ jest pozycja $H$).
Ku chwale Bajtocji!

## Wejście

Pierwsza linia wejścia zawiera dwie liczby całkowite
$N$ $(2 <= N <= 200 000)$ - liczbę wszystkich murów w wąwozie (jest zawsze parzysta)
$H$ $(2 <= H <= 500 000)$ - szerokość wąwozu
W kolejnych $N$ liniach znajdują się liczby całkowite $a_i$ $(1 \leq a_i \leq H-1)$ oznaczające długości kolejnych murów.

W 50% testów $N \leq 2000$.

## Wyjście

Wyjście powinno zawierać dwie liczby oddzielone pojedynczą linią.

- minimalna liczba murów, które musi przebić Bajtokles
- liczba pozycji na jakich może to osiągnąć

## Przykład

Rysunek pokazuje możliwe scenariusze ataku:
Ataki na pozycji 2, 4, 6 (zaznaczone czerwonymi strzałkami) przebiją po 2 warstwy murów (co jest minimalną liczbą przeszkód).


## Wejście
```
6 7
1
5
3
3
5
1
```

## Wyjście
```
2 3
```