Zadatak se svodi na: za dato stablo sa N čvorova, izabrati minimalan broj parova čvorova (neka je taj broj P) tako da se svaki čvor stabla nalazi na bar jednom od P puteva čiji su krajevi izbaranih P parova čvorova. Drugim recima, unija tih P puteva treba da ‘prekrije’ ceo graf.

Prvo treba uočiti da je uvek optimalno da se povežu dva lista u grafu. Jedini način da se neki list ‘prekrije’ je da taj list bude jedan od čvorova iz skupa odabranih P parova. Prema tome, donja granica rešenja je P = floor((L+1)/2) gde L broj listova u stablu, a floor je funkcija koja vraća donji ceo deo.

Uzmimo proizvoljan čvor X koj nije list. Kad bismo izabrali P parova čvorova tako da svaki par čine neka dva lista i da put između ta dva lista prolazi kroz X, ceo graf bi bio prekriven. Zaista, ovim smo prekrili put od svakog lista do X, a to je celo stablo. Uslov da putevi između listova svakog para prolaze kroz X je ekvivalentan sa uslovim da listovi svakog para pripadaju različitim podstablima sinova čvora X.

Umesto da proizvoljno biramo čvor X, možemo izabrati čvor za koji važi da podstablo svakog njegovog sina sadrzi najvise L / 2 listova (nije teško pokazati da takav čvor uvek postoji a možemo ga pronaći uz pomoć jednog DFS obilaska grafa i računanjem broja listova u svakom podstablu). Koristeći ovu osobinu čvora X, mozemo da povežemo floor((L+1)/2) parova listova tako da svaki od pomenutih puteva prolazi kroz čvor X, npr. za svako i <= L/2, možemo upariti i-ti i (i + L/2)-ti čvor (redni brojevi na osnovu DFS obilaska).

Slozenost: O(n)
