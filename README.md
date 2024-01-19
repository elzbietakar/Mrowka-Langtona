# Mrówka-Langtona

### Walczące mrówki Langtona, instrukcja obsługi programu
#### W celu kompilacji programu należy:  
Otworzyć okno terminalu i prześć do katalogu w którym znajduje się program.  
Wykonać komendę `Make`  
Wykonać z odpowiednimi argumentami komendę `./a.out -a ii -b ss m n l it name`:
1. Wczytanie planszy z pliku.   
       Aby wczytać gotową planszę, należy użyć flagi `-b`, a następnie podać kolejno następujące argumenty: 
    * `ss`, nazwa pliku wejścia
    * `it`, liczba iteracji
    * `name`, opcjonalny argument, przedrostek plików wynikowych
  
2. Tworzenie nowej planszy  
   Aby stworzyć planszę, należy podać kolejno następujące argumenty:
   *  `-a ii`, opcjonalna flaga, plansza utworzy się losowo zapełniona białymi polami, gdzie `ii` to procentowe zapełnienie planszy.
   *  `m`, szerokość planszy
	 * `n`, wysokość planszy
	 * `l` liczba mrówek, które chcemy wylosować
	 * `it`, liczba iteracji
	 * `name`, opcjonalny argument,  przedrostek plików wynikowych
		
Jeśli argument `name` nie zostanie podany, plansza będzie wypisywana na wyjście standardowe (stdout). 
 
### Architektura pilku wejścia:
#### Poniżej pokazano strukturę białej planszy 5x5 z 1 mrówką znajdującą się na polu 2x2 zwróconą na północ i drużyną koloru czerownego:
```c++
5 5          //szerokość i wysokość planszy

0 0 0 0 0    //plasza, 0 = puste pole, 1 = pełne pole
0 0 0 0 0  
0 0 0 0 0  
0 0 0 0 0  
0 0 0 0 0    

1            //ilość mrówek
2 2 1 0 0    //parametry mrówki: x, y, życie, kierunek(0-△,1-▽,2-▷,3-◁), drużyna(0-czerwona, 1-zielona, 2-żółta)
