#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

const int MAXTOTLEN = 200;
const int MAXN = 15;

struct node {
	int next[26], link[26], mask;
} b[MAXTOTLEN]; int sz = 1;

char hi;

void trie_dodaj(const string& s) {
	int t = 0;
	for (char x : s) {
		int y = x - 'a';
		if (!b[t].next[y])
			t = b[t].next[y] = sz++;
		else
			t = b[t].next[y];
	}
}

int trie_trazi(const string& s) {
	int t = 0;
	for (char x : s) {
		int y = x - 'a';
		if (!b[t].next[y])
			return -1;
		else
			t = b[t].next[y];
	}
	return t;
}

void nadji_linkove(int t, string s) {
	for (char x='a'; x<=hi; x++) {
		string p = s + x;
		int y = -1;
		while ((y = trie_trazi(p)) == -1)
			p = p.substr(1);
		b[t].link[x - 'a'] = y;
	}

	for (char x='a'; x<='z'; x++) {
		int y = b[t].next[x-'a'];
		if (y)
			nadji_linkove(y, s+x);
	}
}

void nadji_maske(int t, string s, vector<string>& vs) {
	for (int i=0; i<(int)vs.size(); i++) {
		if (s.size() >= vs[i].size() && equal(vs[i].begin(), vs[i].end(),
			s.begin() + (s.size() - vs[i].size())))
		{
			b[t].mask |= 1 << i;
		}
	}	

	for (char x='a'; x<='z'; x++) {
		int y = b[t].next[x - 'a'];
		if (y)
			nadji_maske(y, s+x, vs);
	}
}

int dist[1 << MAXN][MAXTOTLEN];
tuple<char, int, int> pre[1 << MAXN][MAXTOTLEN];

int Resi(int N, int K, int* L, char** A, char* S) {
	hi = 'a' + K - 1;
	// konstruisi trie
	vector<string> vs(N);
	for (int i=1; i<=N; i++) {
		vs[i-1] = string(A[i]+1, A[i]+L[i]+1);
		trie_dodaj(vs[i-1]);
	}
	nadji_linkove(0, "");
	nadji_maske(0, "", vs);
	memset(dist, 255, sizeof(dist));
	dist[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	while (q.size()) {
		auto ee = q.front(); q.pop();
		int mask = ee.first;
		int cvor = ee.second;
		for (char x='a'; x<=hi; x++) {
			int tgt = b[cvor].link[x-'a'];
			int mask2 = b[tgt].mask;
			if (mask2 & mask)
				continue;
			mask2 |= mask;
			if (dist[mask2][tgt] == -1) {
				dist[mask2][tgt] = dist[mask][cvor] + 1;
				pre[mask2][tgt] = {x, mask, cvor};
				q.push({mask2, tgt});
			}
		}
	}
	int sol = 123123123, idx = -1;
	for (int i=0; i<MAXTOTLEN; i++) {
		int d = dist[(1<<N)-1][i];
		if (d != -1) {
			if (d < sol) {
				sol = d;
				idx = i;
			}
		}
	}
	if (sol == 123123123) {
		return -1;
	} else {
		int pos = sol;
		int mask = (1 << N) - 1;
		int cvor = idx;
		while (get<0>(pre[mask][idx])) {
			S[pos--] = get<0>(pre[mask][idx]);
			int mask_tmp = get<1>(pre[mask][idx]);
			int idx_tmp  = get<2>(pre[mask][idx]);

			mask = mask_tmp;
			idx = idx_tmp;
		}
		return sol;
	}
}
