﻿
У средњевековном селу Ењоред, налази се n срењовековних плацева поређаних у ред, jедан до другог, нумерисаних средњевековним броjевима од 1 до $n$. За сваки плац jе позната снага утицаjа средњевековних подземних вода над њим; за $i$-ти плац та вредност jе $v_i$. Jедног дана, скупило се $k$ средњевековних вазалних господара и одлучили су да изграде $k$ великих кућа при чему би свака кућа заузимала тачно $t$ узастопних плацева и, наравно, никоjе две куће не могу имати заjеднички плац.

У договору са селом, вазални господари су се обавезали да, на име средњевековног пореза, укупно плате по 1 златник за сваки од $n$ плацева коjи нису део ниjедне куће. Испоставило се да су вредности $n$, $k$ и $t$ такве да када $k$ вазалних господара подjеднако поделе порез, свако од њих треба да плати не више од 10 златника.

Наравно, наjбитниjа ствар у овоj средњевековноj причи jе одбрана од средњевековних вештица. У то време, када би људи градили куће, они би постављали анти-вештичне урећаjе у наjлевљем плацу своjе куће и отпорност куће на вештице би директно зависила од одговараjуће подземне воде. Нпр. уколико се кућа налази на плацевима $i, i+ 1, . . . i+t−1$, отпорност те куће jе $v_i$. Вазалнигосподари су разумни људи коjи веруjу у вештице и договорили су се да саграде куће тако да jе сума отпорности кућа на вештице наjвећа могућа. Помозите им у томе!


## Опис улаза
У првом реду стандардног улаза налазе се три природна броjа $n$, $k$ и $t$ коjи представљаjу, редом, броj плацева, броj кућа коjе треба изградити и дужину сваке куће у плацевима. У наредном реду налазе се $n$ природних броjева $v_i$, где $i$-ти броj представља снагу утицаjа подземне воде на $i$-ти плац.

## Опис излаза
У првом и jедином реду стандардног излаза исписати наjвећу могућу вредност суме отпорности свих кућа. Гарантуjе се да ће решење (тj. бар jедан распоред кућа) увек постоjати.

## Пример 1
### Улаз
```
8 3 2
4 5 1 4 8 10 7 3
```

### Излаз
```
20
```
## Објашњења примера
Имамо 8 плацева и потребно jе изградити 3 куће од коjих свака заузима по 2 узастопна плаца. Уколико куће изградимо на следећи начин: 4 {5 1} 4 {8 10} {7 3} , тада jе укупна отпорност кућа jеднака $v_2$ + $v_5$ + $v_7$ = 20. Може се показати да не постоjи распоред кућа коjи даjе отпорност већу од 20.

## Ограничења

* $n ≤ 800 000$
* $1 ≤ t, k ≤ 3 000$
* $1 ≤ v_i ≤ 10^9$
* За броjеве $n$, $k$ и $t$ важе сва додатна огранчења из текста задатака.
 
## Подзадаци и бодовање. 
Тест примери су подељени у 4 подзадатка, у коjима важе следећа додатна
ограничења:
* Подзадатак 1 [12 поена]: $n ≤ 20, k, t ≤ 5$
* Подзадатак 2 [15 поена]: После изградње, остаће тачно jедан слободан плац
* Подзадатак 3 [30 поена]: $n ≤ 30 000$
* Подзадатак 4 [43 поена]: Нема додатних ограничења.

## Напомена
Обратити пажњу да jе за испис решења неопходан 64-битни тип података.
