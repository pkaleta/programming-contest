
###################################################################
# Wskazowki odnosnie uzywania programu:

-Program tworzy log'i rozgrywki w plikach w katalogu log. W pliku game.log
znajduje siê przebieg ca³ej rozgrywki. W plikach gracz1_log.in i
gracz2_log.in znajduja sie dane, ktore dany gracz otrzymal na wejscie, a w
gracz1_log.out i gracz2_log.out to co wygenerowal. Dzieki tym plikom mozna
latwiej sledzic bledy programu oraz odtwarzac rozgrywke z plikow ustawiajac
rodzaj graczy na "Plik z ruchami".

-Aby zmienic opoznienie pomiedzy turami trzeba je wpisac i wcisnac Enter.
Wtedy zmieni sie liczba w nawiasie. To ona jest faktyczna wartoscia
opoznienia. To samo dotyczy czasu na gre.

-Rodzaj gracza "Plik z ruchami" oznacza, ze zamiast uruchamiac program gracza
jego ruchy beda odczytywane z pliku. Aby po prostu odtworzyc plik z logami,
trzeba wybrac "Plik z ruchami" dla obu graczy.

-Wybieraj±c gracza "Mysz" klikamy na postaæ, któr± chcemy ruszyæ, pó¼niej 
pole docelowe, pó¼niej pole, na które wylewamy beton.

-Pomiar czasu w aplecie odbywa siê w inny sposób ni¿ bêdzie to robione
podczas turnieju.

-Aplet nie sprawdza ograniczeñ takich jak zu¿ycie pamiêci, nie otwieranie
plików, itp.


##################################################################
# Windows

-Uruchom run.bat

Zakladam, ze polecenie "java" jest w sciezce dostepu.
Jezeli nie, to trzeba dopisac recznie w pliku run.bat.

Mo¿e te¿ siê daæ klikn±æ na plik "gra.jar".

Powinno dzialac na JVM w wersji >=1.4

Uwaga!!!
(Te uwagi s± z zesz³ego roku i nie wiem na ile s± poprawne, ale je tu
pozostawiam.)

1. Nie wszystkie kompilatory C/C++ kompiluja poprawnie. Niektore
programy moga sie wieszac albo powodowac blad zawodnika.
Zalecam uzywanie MinGW, ktory mozna pobrac ze strony:
http://prdownloads.sf.net/mingw/MinGW-3.1.0-1.exe?download
 
2. Programy zawodnikow napisane w Pascalu nie dzialaja pod Windowsem
po skompilowaniu Free Pascalem w wersji 1.0.10. Polecam wersje 1.0.6, ktora
powinna dzialac dobrze. Jako target nalezy dac win32.
Mozna ja sciagnac ze strony:
http://sourceforge.net/project/showfiles.php?group_id=2174


##################################################################
# Linux

-Uruchom run.sh.

Zakladam, ze polecenie "java" jest w sciezce dostepu.
Jezeli nie, to trzeba dopisac recznie w pliku run.sh.

Powinno dzialac na JVM w wersji >=1.4


###################################################################
# Licencja

Program jest rozpowszechniany na zasadzie licencji GPL
(GNU GENERAL PUBLIC LICENSE).

Autor: 
Pawel Parys (parys@mimuw.edu.pl)

Wzorowano sie na programie sprzed z roku 2003, ktorego autorem jest:
Rafal Rusin (r.rusin@students.mimuw.edu.pl)

7.09.2006 Wersja 1.01
