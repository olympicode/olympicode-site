Мала Дуца много воли да једе бомбонице. Она је од своје маме добила бесконачно бомбоница и сада жели да их распореди у кутије.
Узела је $N$ празних кутија, написала на њима бројеве од $1$ до $N$, и поставила их редом **у круг** око себе. Кутији са редним бројем $N$ суседне кутије су са редним бројевима $N-1$ и $1$. 

Сада ће стављати бомбонице у кутије на следећи начин: Изабраће два броја, $P$ и $K$, и онда ће у кутију број $P$ додати тачно $K^2$ бомбинца (зато што воли бројеве који су потпуни квадрати), затим ће у следећу кутију редом у кругу додати $(K-1)^2$ бомбоница, затим у следећу $(K-2)^2$, итд. редом док не прође $K$ кутија и у последњу стави једну ($1^2$) бомбоницу. 
Овакав поступак, почев од поновног избора нових бројева $P$ и $K$, ће потенцијално понављати више пута, све док јој не досади.

Дуца жели да одржава одређени баланс бомбоница у неким кутијама, тако да ће се повремено запитати колико је укупно бомбоница убацила у неких $T$ узастопних кутија, почев од кутије број $X$. Како то може бити јако велики број за рачунање, моли вас за помоћ да јој сваки пут одговорите на овакво питање, и за узврат ће вам дати неколико бомбоница. Уколико сви одговори буду тачни, помоћи ће вам и да освојите неки поен на такмичењу.

## Описи функција
Потребно је да имплементирате следеће функције:

* $Pocetak(N)$

која се позива тачно једном на почетку извршавања програма, и саопштава да Дуца има $N$ кутија постављених у круг.

* $DodajBombonice(P,K)$

која означава да Дуца додаје бомбонице у $K$ кутија, почев од кутије број $P$, на начин који је описан у задатку.

* $Prebroji(X,T)$

која треба да врати колико се тренутно укупно бомбоница налази у $Т$ узастпних кутија, почев од кутије број $X$.
**Пошто овај број може бити велики, вратити остатак при дељењу броја бомбоница са $10^9 + 7 = 1000000007$.**

## Пример 1

| Позиви функција  		| Објашњење				                                                       		  	| 
| --------------------- | --------------------------------------------------------------------------------------|
| Pocetak(7)       		| Имамо 7 кутија које су на почетку празне. Број бомбоница у њима можемо 				|
|						| представити као низ индексиран од 1:  [0,0,0,0,0,0,0]									|
| DodajBombonice(2,3)	| Додајемо $9=3^2$ бомбоница у другу кутију, $4=2^2$ бомбоница у трећу 					|
|						| кутију и $1=1^2$ бомбоницу у четврту кутију. Сада је стање: [0,9,4,1,0,0,0] 			|
| DodajBombonice(4,2)	| Додајемо $4$ бомбонице у четврту и $1$ бомбоницу у пету кутију. 						|
|						| Тренутно стање: [0,9,4,5,1,0,0]  														|
| DodajBombonice(5,4)	| Додајемо $16$ бомбоница у пету, затим $9$ у шесту, $4$ у седму, и $1$ у прву кутију. 	|
|						| Тренутно стање: [1,9,4,5,17,9,4]														|
| Prebroji(1,5)			| Бројимо колико има бомбоница у 5 узастопних кутија почев од прве. 					|
|						| [**1,9,4,5,17**,9,4] Овај позив функције треба да врати резултат 36.					|
| Prebroji(5,1)			| Бројимо колико има бомбоница у 1 узастопној кутији почев од пете.  		 			|
|						| [1,9,4,5,**17**,9,4] Овај позив функције треба да врати резултат 17.					|
| DodajBombonice(7,2)	| Додајемо $4$ бомбонице у седму и $1$ бомбоницу у прву кутију. 						|
|						| Добијамо стање: [2,9,4,5,17,9,8] 											 			|
| Prebroji(6,4)			| Бројимо колико има бомбоница у $3$ узастопне кутије почев од шесте.					|
|						| [**2,9**,4,5,17,**9,8**]Овај позив функције треба да врати резултат 28.				|


## Ограничења

+ Нека је $Q$ укупан број позива функција $DodajBombonice$ i $Prebroji$.
+ $1 \leq N, Q \leq 250000$
+ $1 \leq P,K,X,T \leq N$

## Подзадаци

+ Подзадатак 1 [11 поена]: $N, Q \leq 1000$.
+ Подзадатак 2 [18 поена]: $K \leq 3$.
+ Подзадатак 3 [19 поена]: $T \leq 3$.
+ Подзадатак 4 [20 поена]: Прво ће се извршавати само позиви функције $DodajBombonice$, потом након њих само позиви функције $Prebroji$
+ Подзадатак 5 [32 поена]: Нема додатних ограничења.

## Детаљи имплементације
Потребно је да пошаљете тачно један фајл `bombonice.cpp` или `bombonice.pas`, који имплементира поменуте функције. Осим тражених функција, ваш фајл може садржати и додатне глобалне променљиве, помоћне функције и додатне библиотеке.

У зависности од програмског језика који користите, ваше функције/процедуре морају бити следећег облика:

| Језик   | Декларација функције                              | 
| ------- | ------------------------------------------------- |
| C++     | `void Pocetak(int N);`   						  |
|		  | `void DodajBombonice(int P, int K);`			  | 
|		  | `int Prebroji(int X, int T);`					  |						
| Pascal  | `procedure Pocetak(N: longint);`				  |
|		  |	`procedure DodajBombonice(P,K : longint);`		  |
|		  | `function Prebroji(N,T : longint) : longint;`	  |

## Тестирање и експериментисање
Уз задатак, обезбеђени су вам "template" фајлови `code.cpp` и `code.pas` које можете користити и мењати по потреби. Такође су вам обезбеђени програми `grader.cpp`, `grader.pas` који служе да лакше тестирате кодове. Ови програми учитавају са стандардног улаза следеће податке:

+ У првом реду учитава бројеве $N$ i $Q$
+ Позива функцију $Pocetak(N)$
+ У наредних $Q$ редова чита по 3 броја
+ + Први број је тип упита (1 - додавање бомбоница, 2 - пребројавање)
+ + У првом случају, преостала два броја су $P$ и $K$, и позива се функција $DodajBombonice(P,K)$
+ + У другом случају, преостала два броја су $X$ и $T$, и позива се функција $Prebroji(X,T)$, и исписује се њен резултат, сваки у посебном реду.

Кодове ових програма можете мењати по потреби.