#include <cstring>
#include <cstdio>

const int N = 1 << 19, B = 30;

struct segtree {
    int a[2*N];

    void init() {
        memset(a, 0, sizeof(a));
    }

    void set(int pos, int val) {
        pos += N;
        if(a[pos] == val) return;
        a[pos] = val;
        for(pos /= 2; pos; pos /= 2) {
            a[pos] = a[2*pos] + a[2*pos + 1];
        }
    }

    int query(int left, int right) {
        left += N; right += N;
        if(left > right) return 0;
        if(left == right) return a[left];
        int res = a[left] + a[right];
        while(left / 2 != right / 2) {
            if(left % 2 == 0) res += a[left + 1];
            if(right % 2 == 1) res += a[right - 1];
            left /= 2; right /= 2;
        }
        return res;
    }
} ;

segtree bitcount[B];


void set_value(int pos, int val) {
    for(int i = 0; i < B; i++) {
        if(val & (1 << i)) {
            val ^= 1 << i;
            // 1: highest bit, -1: not the highest
            bitcount[i].set(pos, val ? -1 : 1);
        } else {
            bitcount[i].set(pos, 0);
        }
    }
}


bool query(int left, int n) {
    int right = left + n - 1;
    for(int i = 0; i < B; i++) {
        // For each bit i, let a[i] = number of values where it is the
        // highest bit, and b[i] = the number of values where it is
        // set but not the highest. Pass only if a[i] <= b[i] + 1. We
        // keep track of Q = a[i] - b[i], so we need Q <= 1.

        // printf(" %d -> %d\n", i, bitcount[i].query(left, right));
        // printf("    ");
        // for(int j = 1; j <= 7; j++) printf("%3d", bitcount[i].a[j+N]);
        // printf("\n");

        if(bitcount[i].query(left, right) > 1) {
            return false;
        }
    }
    return true;
}


void Resi(int N, int *A, int Q, int *T, int *I, int *X, bool *O) {
    for(int i = 0; i < B; i++) bitcount[i].init();

    for(int i = 1; i <= N; i++) set_value(i, A[i]);
    for(int i = 1; i <= Q; i++) {
        if(T[i] == 1) {
            int pos = I[i], val = X[i];
            A[pos] = val;
            set_value(pos, A[pos]);
        } else {
            O[i] = query(I[i], X[i]);
        }
    }
}
