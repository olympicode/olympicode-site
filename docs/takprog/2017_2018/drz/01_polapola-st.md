Наталија и Мила се по цео дан досађују па су решиле да играју следећу игру. Мила отвара Ноутпед, прави празан фајл а затим редом куца у Ноутпеду мала слова енглеског алфабета. Међутим, с времена на време, Наталија узима искуцани текст, дели га на два једнака дела а затим мења редослед тим половинама. Наталија је јако пажљива па ово ради само када је дужина текста позитиван паран број. Нажалост, њима се покварио хард диск па је овај фајл изгубљен. Срећом, оне се сећају свих акција које су извеле и у ком редоследу. Помозите им да реконструишу текст који је садржао Ноутпед пре него што им се покварио хард диск.

## Опис улаза
У првој линији стандардног улаза налази се један природан број $N$ - број акција које су извеле Мила и Наталија. У наредних $N$ редова налази се опис једне акције. Са `1 x` означавамо акцију у којој је Мила додала слово `x` на крај фајла у Ноутпеду. Са `2` означавамо акцију у којој је Наталија заменила прву и другу половину фајла.

## Опис излаза
У једини ред стандардног излаза исписати реконструисани изглед фајла након свих акција.

## Пример 1
### Улаз
```
4
1 a
1 b
2
1 c
```

### Излаз
```
bac
```

## Пример 2
### Улаз
```
9
1 a
1 b
2
1 a
1 m
2
1 a
1 d
2
```

### Излаз
```
aadamb
```

## Објашњење примера
У првом примеру Мила додаје слова _a_ и _b_ након чега Наталија дели овај текст на два дела (од по једног слова) и замењује их. На крају, Мила записује _c_ па је коначни изглед текста _bac_.

У другом примеру изглед текста након сваког потеза је следећи:

```
a
ab
ba
baa
baam
amba
ambaa
ambaad
aadamb
```

## Ограничења и подзадаци

* $1 \leq N \leq 500000$.

Постоји пет подзадатака:

* Подзадатак $1$ [$4$ поена]: Мила увек пише исто слово.
* Подзадатак $2$ [$13$ поена]: $N \leq 5000$.
* Подзадатак $3$ [$19$ поена]: Мила неће записати више од 5000 слова.
* Подзадатак $4$ [$22$ поена]: Мила пише само слова _a_ или _b_, $N \leq 50000$.
* Подзадатак $5$ [$42$ поена]: Нема додатних ограничења.