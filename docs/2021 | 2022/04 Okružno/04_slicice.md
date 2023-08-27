# A1 - Sličice

| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
|:-:|:-:|:-:|:-:|
| Aleksa Milisavljević | Aleksa Milisavljević | Dragan Urošević | Aleksa Plavšić |

Za početak odredimo koje karte Jakov može skupiti, a koje ne može.

Jakov može skupiti kartu sa bilo kojim parnim brojem, jer je najveći zajednički delilac za $2$ (Jakov ima na raspolaganju proizvoljno mnogo karti sa brojem $2$) i tog parnog broja jednak $2$ što je veće od $1$.

Jakov može skupiti i karte sa neparnim brojevima $p$ ne većim od $\lfloor\frac{n}{2}\rfloor$ (naravno, većim od $1$), jer prvo može kartu sa brojem $2$ razmeniti za kartu sa brojem $2p$, a nakon toga kartu sa brojem $2p$ za kartu sa brojem $p$.

Na kraju može skupiti i karte sa bilo kojim složenim neparnim brojem $m$ iz intervala $\left[\lceil\frac{n}{2}\rceil,n\right]$. Svaki takav neparan složen broj ima bar jedan prost faktor $p\leq \sqrt{m} \leq \sqrt{n} \leq \lfloor\frac{n}{2}\rfloor$. Zbog toga kartu sa brojem $2$ može razmeniti za kartu sa brojem $2p\leq n$, zatim kartu sa brojem $2p$ za kartu sa brojem $p$ i na kraju kartu sa brojem $p$ za kartu sa brojem $m$.

Jakov ne može skupiti karte sa neparnim prostim brojem $p$ većim od $\lfloor\frac{n}{2}\rfloor$. Da bi skupio tu kartu morao bi da ima kartu sa brojem deljivim sa brojem $p$. Ali najmanji broj (različit od $p$) koji je deljiv brojem $p$ je $2p$ koji je veći od $n$.

Zbog toga je broj karti koje Jakov može skupiti jednak razlici brojeva $n-1$ (broj brojeva većih od $1$, ali manjih od ili jednakih $n$) i broja prostih brojeva većih od $\lfloor\frac{n}{2}\rfloor$ i manjih od ili jednakih $n$.

## Rešenje kad je $N \leq 10$
Sve karte koje može skupiti Jakov se mogu odrediti varijacijom pretrage u širinu.

## Rešenje kad je $N, Q \leq 200$, $N, Q \leq 2000$

Za svaki upit se određuje broj prostih brojeva u intervalu $\left[\lfloor\frac{n}{2}\rfloor+1,n\right]$.

## Rešenje kad je $N \leq 100.000$
Neposredno nakon učitavanja vrednosti broja $N$ za sve upite, određuje se najveća vrednost za $N$ (neka je to $N_{\max}$), a nakon toga za svaku vrednost $N \leq N_{\max}$ broj prostih brojeva koji nisu veći od $N$ (označimo taj broj sa $p(N)$).  Vrednost $p(N)$ se određuje na osnovu vrednosti $p(N-1)$. Naime, vrednost $p(N)$ je jednaka $p(N-1)+1$, ako je $N$ prost broj, odnosno $p(N-1)$, ako je $N$ složen broj. Provera da li je broj $N$ prost se može izvesti u složenosti $O(\sqrt{N})$, pa je složenost određivanje svih vrednosti $p(N)$ jednaka $O(N_{\max}\sqrt{N_{\max}})$.
 Nakon toga se broj prostih brojeva u intervalu  $\left[\lfloor\frac{n}{2}\rfloor+1,n\right]$ određuje po formuli $p(N)-p\left(\frac{N}{2}\right)$, tj. u složenosti $O(1)$. Složenost kompletnog algoritma je $O(N_{\max}\sqrt{N_{\max}}+Q)$.

## Glavno rešenje

Neposredno nakon učitavanja vrednosti broja $N$ za sve upite, određuje se najveća vrednost za $N$ (neka je to $N_{\max}$), a nakon toga za svaku vrednost $N \leq N_{\max}$ broj prostih brojeva koji nisu veći od $N$ (označimo taj broj sa $p(N)$).  Za razliku od prethodnog podzadatka, provera da li su prirodni brojevi prosti se izvodi primenom Eratostenovog sita. Zahvaljujući tome, složenost izračunavanja svih vrednosti $p(N)$ je $O(N_{\max}\log N_{\max})$, a složenost kompletnog rešenja je $O(N_{\max}\log N_{\max} + Q)$.

