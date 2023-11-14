#include <iostream>
#include <algorithm>
#include <cstdlib>

#include "restorani.h"

using namespace std;

static int m;
static int n;
static int cur;
static int *a;

void Init(int M) {
    n = 0;
    m = M;
    cur = 0;
    a = (int*) malloc(M * sizeof(int));
}

void NoviSastojak() {
    a[n++] = ++cur;
    int p = n - 1;
    while (p > 0 && Uporedi(a[p], a[p - 1]) == -1) {
        swap(a[p], a[p - 1]);
        --p;
    }
}

void Nadji() {
    int t = n / 2;
    for (int i = 0; i < t; ++i) Izbaci(a[i]);
    for (int i = t; i < n; ++i)
        a[i - t] = a[i];
    n = n - t;
}
