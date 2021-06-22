## Wazne informacje
Testy zostały zapisane do pliku log.txt w glownym katalogu,
gdzie zostały usuniete wszystkie puste pola (std out sie zapycha)

Podczas animacji lotu nie nalezy ruszac perspektywa, poniewaz program
sie zawiesza (prawdopodobnie przyczyna w sposobie uzywania GNUPlota).

W MENU dodana jest opcja 't', gdzie jest juz zaplanowana trasa z przeszkodami.
Dron ominie przeszkody, wyladuje na plaskowyzu i znowu wystartuje z danego miejsca.

Przydatne:

Po uruchomieniu programu i zadaniu  parametrow lotu:
kat 45;
odleglosc 50
dla Drona 0, Dron ominie gore z grania i wyladuje na plaskowyzu.  
Nastepnie zadanie temu samemu Dronowi parametrow
kat 0;
odleglosc 50;
Pokazane bedzie jak wykrywana jest kolizja z plaskowyzem.

####  Datacamp Skill Track
Ukonczylem sciezke Python Fundamentals
W katalogu glownym znajduje sie pdf z certyfikatem.
Jakis czas temu zaczalem kolejna, ale raczej nie zdaze
do wystawienia ocen (Dopiero 1 kurs z 6 ).

## Dokumentacja
Dokumentacja wygenerowana przy pomocy Doxygen'a znajduje sie w katalogu /Documentation.
W katalogu znajduje sie skrot do strony HTML o nazwie index.html
W celu otworzenia dokumentacji nalezy uruchomic skrot lub przeszukac katalog /html.

W razie problemow pliki graficzne diagramow znajduja sie w folderze images.
Pliki z diagramami w programie Dia znajduja sie w /Documentation/dia/.

## Faza 3
Implementacja detekcji kolizji oraz podstawy autonomicznego lotu.
Drony moga ladowac na Plaskowyzach.

Zmiana sposobu rysowania w programie GNUPlot za pomoca Sceny.

Wygenerowano nowa dokumentacje

Wszystkie wczesniejsze operacje nadal dzialaja

Nazwa pliku wynikowego ./main

Aby wykonac testy:  ./unit_tests -s

#######
Testy zostały zapisane do pliku log.txt w glownym katalogu,
gdzie zostały usuniete wszystkie puste pola.
######

## Faza 2
Rozbudowano klasy i dziedziczenie o metody wirtualne i nowe klasy

Program korzysta ze wskaznikow wspoldzielonych

Do sceny moga byc dodawane i usuwane Obiekty Sseny

Wygenerowano nowa dokumentacje

Wszystkie wczesniejsze operacje nadal dzialaja

Nazwa pliku wynikowego ./main

## Faza 1

Program poprawnie rysuje scene i drony.

Wykonanie obiektowe z dziedziczeniem.

Animacja lotu jednego z dronow.
Mozliwy lot po oktagonie (modyfikacja).
Program zlicza uzywane i usuwane wektory.
Pliki tekstowe wzorcowe i robocze znajduja sie w katalogu datasets w odpowiedznich lokalizacjach.

Kazdy dron jest opisany 12 wektorami (polozenie w ukladach lokalnych i globalnych bryl i drona, wektor skalowania w klasie bazowej).

## Uruchamianie programu i testy
W celu uruchomienia programu nalezy wejsc w katalog build i uruchomimc program ./main
W tym samym katalogu polecenie make kompiluje program.

Testy mozna przeprowadzic za pomoca polecen:
-make test	 (Testy ogolne)
./unit_tests -s (Testy jednostkowe)


## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: cmake, gnuplot, doxygen + dot (in graphviz library)

Example:

``` bash
> mkdir build && cd build
> cmake .. #### options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make     #### compilation
> ./main   #### main() from app
> make test      #### Compile the tests
> ./unit_tests -s   #### Start the tests, -s flag - full description of each case
> make fulltest #### alternative for above, compile & run tests with full decription
> make coverage  #### Generate a coverage report
> make doc       #### Generate html documentation
```

Things to remember:
* changes to CMakeLists.txt in the main folder with new files added, i.e.:
```cpp
# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------
set(SOURCES          # All .cpp files in src/
    src/lacze_do_gnuplota
    src/Matrix2x2.cpp
    src/Rectangle .cpp
    src/Vector2D.cpp # etc.
)
set(TESTFILES        # All .cpp files in tests/
    Vector2D.cpp
    Matrix2x2.cpp
    Rectangle.cpp # etc.
)
set(LIBRARY_NAME zadX)  # Default name for the library built from src/*.cpp (change if you wish)
```
* changes to tests/CMakeLists.txt (in tests subfolder) with new files added, i.e.:
```cpp
# List all files containing tests. (Change as needed)
set(TESTFILES        # All .cpp files in tests/
    main.cpp
    test_Wektor2D.cpp
    test_Macierz2x2.cpp
    test_Prostokat.cpp # etc.
)
```
The `main.cpp` in the folder `tests` is needed. Only there we define `#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN`.

The main loop of the program is in the `app` folder.

