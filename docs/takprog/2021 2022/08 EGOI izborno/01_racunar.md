# 1 - Računar

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Igor Pavlović | Igor Pavlović | Vladimir Milovanović | Vladimir Milovanović |

Najpre je neophodno uočiti da svaki zadatak iz postavke ima svoj redni broj (indeks) u redosledu zadataka, početak i kraj izvršavanja, te trenutak upisa rezultata u memoriju koji je potrebno odrediti. Stoga je korisno iskoristiti neku od struktura koja grupiše ove četiri karateristike svakog zadatka. Takođe, prema postavci, zadaci nisu sortirani ni prema početnom, a ni prema krajnjem trenutku svog izvršavanja.

## Kvadratno rešenje

Dovoljno je u dve ugnežđene petlje redosledom proći po svim zadacima i za svaki zadatak ispitati da li postoji neki drugi zadatak koji je počeo pre njega, a koji se završava nakon njega. Drugim rečima, u petljama za svaka dva zadatka $i$ i $j$ proveravati da li je $A_j < A_i$ i $B_j > B_i$ i simultano ažurirati traženo vreme upisa u memoriju na maksimalno $B_j$ od zadataka koji zadovoljavaju prethodni uslov. Najzad, po redosledu proći i ispisati vremena. Kako se u svakoj od dve petlje prolazi kroz sve zadatke, ovo rešenje ima kvadratnu vremensku složenost, odnosno $\mathcal{O}(N^2)$, gde $N$ predstavlja broj zadataka.

## Glavno rešenje u loglinearnoj složenosti

Da bi se problem rešio na efikasan način, mogu se zadaci umesto po indeksu sortirati po vremenu početka izvršavanja. Pošto u tako sortiranim zadacima nakon $i$-tog zadatka nema zadataka koji su počeli posle njega, to je dovoljno u samo jednom prolasku kroz zadatke, vodeći računa o dotadašnjem maksimumu, ažurirati vreme upisa u memoriju kao trenutnu vrednost maksimuma. Najzad, potrebno je pre ispisa zadatke ponovo sortirati po redosledu učitavanja, odnosno po indeksima, kako bi se u jednom prolasku ispisala tražena vremena. Kako je operaciju sortiranja efikasnim algoritmima moguće izvršiti u loglinearnoj vremenskoj složenosti $\mathcal{O}(N\log N)$, a kako je ovo vremenski najzahtevnija operacija u predloženom rešenju, to je i ukupna složenost ovog rešenja loglinearna po broju zadataka.
