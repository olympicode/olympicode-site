#include <cstdio>

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a < b ? b : a; }

int main() {
    int n, gb, rb, rg;
    scanf("%d %d %d %d", &n, &gb, &rb, &rg);

    // bez poslednje
    gb--; rb--; rg--;

    // smena da bi garantovali da imamo bar jednu od svake boje
    if(n < 3) {
        printf("nemoguce\n");
        return 0;
    }
    n -= 3;
    rg = max(0, rg - 2);
    gb = max(0, gb - 2);
    rb = max(0, rb - 2);

    /*
      r + g + b == n  (1)
      r + g >= rg     (2)
      g + b >= gb     (3)
      r + b >= rb     (4)

      (2) + (3) + (4):
      2(r + g + b) >= rg + gb + rb
      2n >= rg + gb + rb  (5)

      (5) je potreban uslov -- ako ne vazi nema resenja. Ako vazi, na
      sledeci nacin mozemo naci resenje, tako da je i dovoljan:

      (1) - (2):
      b <= n - rg  (6)
      slicno:
      r <= n - gb  (7)
      g <= n - rb  (8)

      Ako odaberemo bilo koja tri r, g, b za koje vazi (6--8) i (1),
      bice ispunjeni i uslovi (2--4) (npr (2) sledi iz (1)-(6)).
      Mozemo ih odabrati tako sto biramo redom najvece moguce
      vrednosti za koje zbir iz (1) nije premasen -- zbir ce uvek biti
      dostignut zbog sledeceg:

      rmax + gmax + bmax == (n-rg) + (n-gb) + (n-rb) == 3n - (rg + gb + rb)
      (5):
      rmax + gmax + bmax >= 3n - 2n == n
     */

    // NB: rg + gb + rb moze biti vece od INT_MAX
    long long rgb2 = (long long)rg + (long long)gb + (long long)rb;

    if(2*n < rgb2) {
        printf("nemoguce\n");
    } else {
        int r, g, b;
        r = min(n - gb, n);
        g = min(n - rb, n - r);
        b = min(n - rg, n - r - g);

        printf("moguce\n%d %d %d\n", r+1, g+1, b+1);
    }

    return 0;
}
