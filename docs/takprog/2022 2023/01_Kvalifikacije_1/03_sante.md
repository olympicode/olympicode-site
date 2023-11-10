# 3 - Sante

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Momčilo Tošić | Momčilo Tošić | Momčilo Tošić | Marko Milenković |

Korisno je uočiti da sante formiraju graf od $N$ čvorova i $M$ grana, gde svaka grana ima težinu 0 ili 1. Moguće je bez promene stanja mašine kretati se samo preko grana one težine koje je trenutno stanje (0 - mašina ne radi, 1 - mašina radi). Početno stanje je 0.

## Rešenje kada $M = N-1$ i iz svake sante ide jedna ili dve grane

Ovako zadate sante formiraju niz gde je svaka povezana sa prethodnom i sledećom (osim prve i poslednje).
Možemo doći od jedne do druge sante na jedinstven način (pokušamo da idemo levo od Mike dok ne stignemo do kraja, ili do Laze, i isto tako na desno), i simulirati promene
stanja.

## Rešenje kad je put između svake dve sante teško prohodan

Ovde je jedini mogući odgovor 1 ili -1, zavisno od toga da li je moguće doći od Mikine do Lazine sante. Ovo možemo proveriti nekim algortimom poput $DFS$-a (rekurzivni obilazak svake sante sa pamćenjem posećenih).

## Rešenje kad je $M = N-1$ i uvek se može doći od jedne do druge sante

Graf koji sante opisuju u ovoj grupi primera je stablo. Kao u prvom podzadatku, jedinstven je način da se dođe od jedne sante do druge (osobina stabla), samo je ovaj put
potrebno koristiti neki algoritam za nalaženje puta (ovde je put skup grana, a ne termin iz teksta) između dva čvora (kao $BFS$), i simulirati promene stanja mašine na njemu.

## Rešenje za pun broj poena

Primetimo da ukoliko je stanje mašine $s$, a nalazimo se u čvoru $u$, moguće je slobodno (bez povećanja konačnog odgovora) se kretati po svim čvorovima
do kojih se granama težine $s$ može doći iz $u$. Dakle, konstrukcija našeg rešenja može izgledati tako što prvo obiđemo sve čvorove do kojih se može doći iz početnog koristeći grane
težine 0, zatim promeniti težinu i naći sve dostižne preko grana težine jedan od prethodno dostignutih itd. (naravno ne obilazeći već posećene čvorove).<br>
Elegantnu implementaciju ove ideje nam pruža takozvani $0-1$ $BFS$. U redu sa dva kraja (double ended queue) pamtimo čvor kao i stanje u kom se nalazimo kad ga posećujemo (na početku dodamo Mikinu santu i 0),
i na početak reda dodajemo one čvorove koji su povezani granama težine koja odgovara stanju čvora, 
dok se na kraj dodaju čvorovi povezani granama suprotne težine (i u oba slučaja ažuriramo cenu dolaska do nekog čvora). Ovako smo se osigurali da prvo prolazimo kroz
sve dostupne iz prvog čvora bez promene stanja, a da dalje ne menjamo stanje dok nismo obišli sve koji se dostižu jednom promenom stanja, itd.<br>
Na kraju jednostavno proverimo da li je obiđen Lazin čvor, i koja je cena njegovog obilaska.<br> Vremenska i memorijska složenost su $O(N+M)$.<br>

## Rešenje 2 (za pun broj poena)

Kako je moguće slobodno se kretati od nekog čvora po određenoj grupi čvorova, možemo grupisati čvorove u 0-komponente i 1-komponente (zavisno od toga kakvim se granama krećemo) $DFS$-om,
a zatim formirati novi graf u kom povezujemo dve komponente ukoliko ne postoji čvor preko kog je moguće preći iz jedne u drugu (u ovom čvoru menjamo stanje mašine). Kasnije nalazimo najkraći put između odgovarajućih
komponenti u ovom grafu $BFS$-om (s tim što je početna udaljenost 1 ukoliko krećemo od 1-komponente). Svaka komponenta je ili 1 ili 0 komponenta i ima najmanje jedan čvor, te 
njih ima reda veličine $N$, dok grana između njih ima najviše $N$ (jer jedan čvor predstavlja granu između komponenti) - dakle red veličine složenosti je ponovo linearan.

*Napomena: sporija implementacija ideje za 100 poena (npr Dajkstrin algoritam u kvadratnoj složenosti umesto 0-1 BFS) će raditi za vrednosti N i M do 5000*
