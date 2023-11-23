#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> f[30005];
int a[30005], n;

bool sl[10005];
vector<int> prosti; // 1229 brojeva

// svi brojevi do 100M imaju najvise 8 razlicitih prostih delioca

int moj_lzcnt[256];
int moj_parity[256];

void sito_i_lzcnt() {
	for (int i=2; i<=10000; i++) {
		if (!sl[i]) {
			prosti.push_back(i);
			for (int j=i*i; j<=10000; j+=i) {
				sl[j] = true;
			}
		}
	}
	for (int i=1; i<256; i++) {
		int x = i, c = 0;
		while (x % 2 == 0) {
			c++;
			x >>= 1;
		}
		moj_lzcnt[i] = c;
	}
	moj_parity[0] = 1;
	for (int i=1; i<256; i++) {
		moj_parity[i] = -moj_parity[i - (1 << moj_lzcnt[i])];
	}
}

void ucitaj() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", a+i);
	sort(a, a+n);
}

void faktorisi() {
	for (int i=0; i<n; i++) {
		int k = a[i];
		for (int x : prosti) {
			if (k % x == 0) {
				f[i].push_back(x);
				do {
					k /= x;
				} while (k % x == 0);
			}
			if (x > k) break;
		}
		if (k > 1) {
			f[i].push_back(k);
		}
	}
}

const int MAX = 100'000'000;
const int LIMIT = 10'000'000;
uint16_t br[LIMIT+5];

int br_delioca;
int delioci[256];

// ne idu svi delioci vec samo oni koji nemaju isti prost broj vise puta
void napuni_deliocima(int i) {
	delioci[0] = 1;
	br_delioca = 1 << f[i].size();
	for (int mask=1; mask<br_delioca; mask++) {
		int lz = moj_lzcnt[mask];
		delioci[mask] = delioci[mask - (1 << lz)] * f[i][lz];
	}
}

int broj_deljivih(int x) {
	if (x <= LIMIT) {
		return br[x];
	}
	int c = 0;
	for (int y=x; y<=MAX; y+=x) {
		c += upper_bound(a, a+n, y) - lower_bound(a, a+n, y);
	}
	return c;
}

void resi() {
	for (int i=0; i<n; i++) {
		napuni_deliocima(i);
		for (int mask=1; mask<br_delioca; mask++) {
			if (delioci[mask] <= LIMIT) {
				br[delioci[mask]]++;
			}
		}
	}
	long long sol = 0;
	for (int i=0; i<n; i++) {
		napuni_deliocima(i);
		sol += n;
		for (int mask=1; mask<br_delioca; mask++) {
			sol += moj_parity[mask] * broj_deljivih(delioci[mask]);
		}
	}
	// odbaci jedinice
	sol -= count(a, a+n, 1);
	
	// odbaci simetricne parove
	sol /= 2;
	
	printf("%lld\n", sol);
}

int main() {
	sito_i_lzcnt();
	ucitaj();
	faktorisi();
	resi();
	return 0;
}












