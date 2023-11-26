/*
    ZADATAK:       zadaci (Kvalifikacije, 4)
    AUTOR ZADATKA: Andrej Ivaskovic
    AUTOR KODA:    Andrej Ivaskovic

    Za ovo resenje je predvidjeno 100 poena. Zasniva se na kombinatornoj logici
    i binarnoj pretrazi. Konkretno, svi podnizovi ciji je maksimum neko k imaju
    odredjen nenulti broj pojavljivanja k i sastoje se od nekog broja
    (potencijalno nula) elemenata polaznog niza koji su manji od k. Broj nacina
    na koji ovo moze da se postigne je (2^p - 1) * 2^q, gde je p broj
    pojavljivanja vrednosti p u A, a q broj elemenata niza A koji su manji od
    k.
    
    Stepeni dvojke mogu da se preprocesiraju, a odredjivanje p i q se odredjuje
    pri svakom upitu na efikasan nacin. Ako se A najpre sortira u (ne strogo)
    rastucem poretku, tada je moguce odrediti prvo i poslednje pojavljivanje k
    u sortiranom nizu A binarnom pretragom (uz dve njene standardne varijante),
    na osnovu cega mogu da se odrede vrednosti p i q.

    Slozenost ovog pristupa je O((Q + N) log N).
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_DUZ 200005
#define MOD 1000000007

int N, Q;
int A[MAX_DUZ];
int k;
long long broj_res;
long long stepen[MAX_DUZ];
int p, q;
int prvo_poj, posl_poj;

// Preprocesiranje stepena dvojke
void generisi_stepene(void)
{
    stepen[0] = 1L;
    for (int i = 1; i <= N; i++) {
        stepen[i] = (stepen[i - 1] * 2) % MOD;
    }
}

// Odredjuje indeks prvog pojavljivanja elementa koji je >= v u A
int bin_pret_l(int v)
{
    int l = 0, d = N - 1, s;
    while (l < d) {
        s = (l + d) / 2;
        if (v == A[s]) {
            d = s;
        } else if (v > A[s]) {
            l = s + 1;
        } else if (v < A[s]) {
            d = s - 1;
        }
    }
    return l;
}

// Odredjuje indeks poslednjeg pojavljivanja elementa koji je <= v u A
int bin_pret_d(int v)
{
    int l = 0, d = N - 1, s;
    while (l < d) {
        s = (l + d + 1) / 2;
        if (v == A[s]) {
            l = s;
        } else if (v > A[s]) {
            l = s + 1;
        } else if (v < A[s]) {
            d = s - 1;
        }
    }
    return l;
}

int main(void)
{
    // Ulaz
    scanf("%d", &N);
    generisi_stepene();              // neophodno zbog efikasnosti
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, A + N);                 // omogucava binarnu pretragu
    // Upiti
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d", &k);
        // Prvo i poslednje pojavljivanje k u nizu
        prvo_poj = bin_pret_l(k);
        posl_poj = bin_pret_d(k);
        if (A[prvo_poj] == k) {          // postoji neko pojavljivanje k
            p = posl_poj - prvo_poj + 1;
            q = prvo_poj;
            broj_res = ((stepen[p] - 1) * stepen[q]) % MOD;
        } else {                        // ne postoji pojavljivanje k
            broj_res = 0L;
        }
        printf("%lld\n", broj_res);
    }
    return 0;
}
