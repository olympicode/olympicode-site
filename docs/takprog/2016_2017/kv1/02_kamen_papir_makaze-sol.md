﻿## Први подзадатак:
Како је највише једна Нешина дивизија по броју различита од $0$, то није битно како је нападамо пошто ће на крају бити исти број војника поражено. Потребно је само имплементирати ово.

## Други подзадатак:
Задатак приступамо похлепно. Лукина једина дивизија прво напада Нешину против које он има предност. Затим, ако преостане војника, напада ону против које губи једнак број војника. На крају, ако опет остане војника, напада Нешину дивизију против које нема предност.

## Главно решење:
Слично као раније, одвија се $3$ корака, у сваком по $3$ борбе. Прво, све Лукине дивизије се прво боре против оних према којима имају предност. Затим, $3$ борбе се одвијају између дивизија једнаких снага. На крају се Лукине дивизије боре против Нешиних према којима немају предност.