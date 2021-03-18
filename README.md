# Ski-Jumper-Perspective
Gra o tematyce skoków narciarskich. Mamy do wyboru karierę własnego skoczka (można użyć istniejących karier, z dodatkową zawartością np. dodatkową fabułą), lub poprowadzić którąś z reprezentacji. Gra jest na bardzo wczesnym etapie rozwoju.

## Funkcje w aktualnej wersji ##
* Symulowanie jednoseryjnego konkursu ze skoczkami wpisanymi do pliku.

## Atrybuty zawodnika ##
* Moc wybicia (od 1 do 120 [zalecane do 100])
* Technika wybicia (od 1 do 120 [zalecane do 100])
* Technika lotu (od 1 do 120 [zalecane do 100])
* Styl lotu (0 - klasyczny, 1 - Styl V, 2 - Nowoczesne V, 3 - Nowoczesne V równoległe, 4 - Styl H [równoległy])
* Umiejętność lądowania (nie mylić ze stylem lądowania) (od 1 do 60)
* Styl lądowania (od 1 do 60)
* Forma (od 1 do 120 [zalecane do 100])
* Doświadczenie (niedostępne)
* Odporność na kontuzje (Od 1 do 5) (niedostępne) (Jest tylko do trybu kariery)

Dlaczego przy atrybutach jest zalecane do 100, mimo że jest do 120?
Po prostu powyżej 100 skoczek będzie już bardzo dobry, i światowa czołówka będzie pewnie miała nieco poniżej 100.

## Atrybuty skoczni ##
* Nazwa skoczni
* Kraj skoczni
* Punkt K (na jego podstawie jest określany typ skoczni)
* Punkt HS (znaczenie ma tylko w zasadzie 95% HS przy obniżaniu belki, lecz ta opcja nie jest jeszcze dostępna)
* Punkty za belke (ile punktów zostanie dodanych/odjętych skoczkowi na podwyższony/obniżony rozbieg)
* Metry za belke (jaki metrowo wpływ ma belka. jeśli wpisze się "-1", metry zostaną określone w taki sposób: "punkty za belke / punkt za metr odległości") (Dla Wisły Malinki to 7.24 / 1.8)
* Punkty za wiatr przedni (tak samo jak z belką)
* Metry za wiatr przedni (tak samo jak z belką)
* Punkty za wiatr tylni (tak samo jak z belką)
* Metry za wiatr tylni (tak samo jak z belką)
* Maksymalna odległość (ile można makymalnie skoczyć na danej skoczni)
* Losowość maksymalnej odległości (o ile inna może być maksymalna odległość)
* Startowa odległość (im wyższa, tym dalsze skoki. Można podpatrzeć z innych skoczni)
* Trudność przy lądowaniu przy punkcie HS (im większa, tym większa szansa na upadek etc, im większa skocznia tym w miarę większa powinna być wartość)
* Metry za styl klasyczny
* Metry za styl V
* Metry za styl nowoczesne V
* Metry za styl nowoczesne równoległe V
* Metry za styl H
(metry za styl lotu pokazują ile zyskuje się lecąc w określony sposób. Skoki stylami bardziej nowoczesnymi mogą być trochę mniej równe)
* Optymalna moc wybicia (Jaka jest optymalna moc wybicia)
* Ważność mocy wybicia (Jak ważna jest moc wybicia. Można podpatrzeć z innych skoczni)
* Metry za technikę wybicia (Ile punktów zyskuje się za dobre wybicie. Najlepiej podpatrzeć z innych skoczni)
* Metry za technike lotu (Tak jak z techniką wybicia)
* Dzielnik not sędziowskich: Do noty za styl jest dodawana odległość za punktem K podzielona przez dzielnik.

## Atrybuty ustawień treningu ##
Ważność skoku (od 1 do 5)
Zakres wiatru minimalny
Zakres wiatru maksymalny (przed początkiem konkursu następuje losowanie podstawowego wiatru z tego zakresu. Potem dochodzi jeszcze loteryjność i wadliwość przelczników)
Zakres zmiany wiatru minimalny
Zakres zmiany wiatru maksymalny (jest losowanie z tego zakresu, a później wylosowaną wartość dodaje się do podstawowego wiatru)
Punkty za belke (0 - nie, 1 - tak)
Punkty za wiatr (0 - nie, 1 - tak)
Noty sędziowskie (0 - nie, 1 - tak)


## Plki z zasobami##

**(Wartości w plikach trzeba oddzielać przecinkami!!!)** <br>
* **hills.csv** - Wpisuje sie tam skocznie w kolejności w jakiej podane są atrybuty skoczni. <br>
* **jumpers.csv** - Wpisuje sie tam skoczków do trybu kariery, i do trybu treningu.
Kolejność: Imię,Nazwisko,Narodowość,Wiek,Wzrost,Moc wybicia, Technika wybicia, Technika lotu, Styl lotu, Umiejętność lądowania, Styl lądowania, Doświadczenie, Forma, Odporność na kontuzje
* **trainingconfig.csv** - Wpisuje się w takiej kolejności jak w atrybutach ustawień treningu.

(reszta plików póki co nie ma znaczenia)
