#include <bits/stdc++.h>
#define MAXN 255

using namespace std;

int N;
char A[MAXN];
unordered_map<char, int> cnt;

int main() {
	scanf("%d", &N);
	scanf("%s", A);
	for (int i = 0; i < N; i++) {
		cnt[A[i]]++;
		if (A[i] >= 'a' && A[i] <= 'z' && cnt[A[i]] == 2) {
			// neko slovo se pojavilo dvaput
			// nemoguce napraviti pangram
			printf("SAN\n");
			return 0;
		}
	}
	// skupimo slova koja fale
	vector<char> missing;
	for (int c = 'a'; c <= 'z'; c++) {
		if (cnt[c] == 0) {
			missing.push_back(c);
		}
	}
	// ne mora, naravno
	reverse(missing.begin(), missing.end()); 
	if (missing.size() > cnt['?']) {
		// nema dovoljno '?' da dodamo sva slova
		printf("SAN\n");
		return 0;
	}
	// koliko razmaka treba dodati?
	int spaces = cnt['?'] - missing.size();
	for (int i = 0; i < N; i++) {
		if (A[i] == '?') {
			if (i > 0 && i < N-1 && spaces > 0 && A[i-1] != '_' & A[i+1] != '_') {
				// treba i moze razmak
				A[i] = '_';
				spaces--;
			} else {
				// ne treba razmaka vise ili ne moze razmaka vise
				if (missing.empty()) {
					// nemoguce staviti dovoljno razmaka
					printf("SAN\n");
					return 0;
				} else {
					A[i] = missing.back();
					missing.pop_back();
				}
			}
		}
	}
	printf("%s\n", A);
	return 0;
}
