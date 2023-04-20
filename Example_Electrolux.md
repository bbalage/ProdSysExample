# Electrolux tanszéki projekt

Hűtőszekrények gyártásával foglalkozik a projekt.
Az Electrolux Magyarország igényeihez kellett igazítani a rendszert.
Az igényelemzés már korábban el lett végezve.

Adott egy gyártórendszer. Vannak alkatrészgyártó gépek és összeszerelő sorok.
Közöttük egy műveletközi tároló található.

A szerelősorok intenzitása nagyobb, mint az alkatrészgyártásé. Ennek oka, hogy
a szerelősor gyorsabban tud működni. Az alkatrészgyártás több időt vesz igénybe.

A rendszerben modellezni kell a szűkös tárolókapacitást. Erősen korlátozottak 
a műveletközi tárolók kapacitásai. A gép és a raktár közös térben van. Új gépek 
telepítése helyet vesz el. Hűtőszekrényt nem lehet más műhelyben tárolni, mert 
nehéz a mozgatása.

Sokféle alkatrész van. Például ajtóból van 10-féle, és megvan adva, hogy melyiket
melyik gépen tudom gyártani.

Akadnak szerszámok, amikből csak bizonyos mennyiség áll rendelkezésre. Tehát egy
művelet elvégzéséhez szükség van:
- Egy gépre
- Egy szerszámra\
Ez a páros együtt adja meg a műveleti időt.

A menedzsment elvárása:
- A szerelést időre el kell tudjuk végezni. Ez az elsődleges cél.
- Másodlagos cél, hogy a gépek állása minimális legyen; tehát kevés legyen a
ki-bekapcsolás, a gépek a betervezett műszakban folyamatosan tudjanak dolgozni; ez a dolgozók
bérezése miatt szükséges, ugyanis az állás közbeni munkaidőt is fizetni kell.
- További elvárás, hogy kevés átállás legyen, ugyanis az átállási idő hosszú.

Sok célfüggvény van, amelyet a fóliában láthatunk:
- $f_1$: minimális legyen a határidőt túllépő sorozatok száma.
- $f_2$: minimális legyen a csúszások időösszege.
- $f_3$: minimális legyen a legnagyobb határidő-túllépés (csúszás).
- $f_4$: minimális legyen a gépátállítások száma.
- $f_5$: minimális legyen a gépátállítások időösszege.
- $f_6$: minimális legyen a gépek átlagos kihasználatlansága.
- $f_7$: minimális legyen a sorozatok átlagos átfutási ideje.
- $f_8$: minimális legyen a műszakbeosztások költségeinek összege.
  - Ez utóbbi annyit jelent, hogy a délelőttös műszak költségesebb, mint az éjszakás, stb.
  - Mindhez tartozik egy szorzó, amit a műszak idejére alkalmazunk.

Műveletközi tároló kezelése során nem a darabszám mérvadó, elvégre egy adott terméktípusból
lehet több, egy másikból lehet kevesebb fog elférni benne. Alkatrészenként visszafejthető,
hogy egy termék hány százalékát foglalja el a tárkapacitásnak.

A művelet befejezési ideje, és a gép felszabadulási ideje elválik.

A program használatához szükséges felhasználónév és jelszó:
- username: freeq1
- password: freeq1

M_J_A_S_Tabu_Search_with__S_class_do_pi_for_first_step_....