#include <bits/stdc++.h>
using namespace std;

const int MAXNODES = 1000005;
const int MAXN = 505;

struct node {
	int p[26];
	int c;
} d[MAXNODES];
int z;

int f[MAXN][MAXN];

int Resi(int n, char* a, int m, int* l, char** b) {
	// nadji najmanju periodu stringa i promeni n
	a++;
	for (int i=1; i<=n; i++) {
		if (n % i)
			continue;
		bool ok = true;
		for (int j=0; j<n; j++)
			if (a[j] != a[j % i]) {
				ok = false;
				break;
			}
		if (ok) {
			n = i;
			break;
		}
	}

	// napravi trie
	for (int i=1; i<=m; i++) {

		int r = 0;

		for (int j=1; j<=l[i]; j++) {
			int x = b[i][j] - 'a';

			if (!d[r].p[x])
				d[r].p[x] = ++z;

			r = d[r].p[x];
		}

		d[r].c = 1;
	}

	memset(f, 11, sizeof(f));

	// nadji grane
	for (int i=0; i<n; i++) {
		int r = 0;
		for (int j=0;; j++) {
			int x = a[(i+j) % n] - 'a';
			if (d[r].p[x])
				r = d[r].p[x];
			else
				break;

			if (d[r].c)
				f[i][(i+j+1) % n] = 1;
		}
	}

	for (int j=0; j<n; j++)
		for (int i=0; i<n; i++)
			for (int k=0; k<n; k++)
				f[i][k] = min(f[i][k], f[i][j] + f[j][k]);

	int sol = 123123123;
	for (int i=0; i<n; i++)
		sol = min(sol, f[i][i]);

	if (sol > n)
		sol = -1;
	return sol;
}