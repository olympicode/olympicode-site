#include <iostream>
#include <string>

#define MAXN 3000

int poklapanje(std::string& s, int n, int p, int j) {
  if (p - j < 0 || p + j - 1 >= n) {
    return 0;
  }
  return s[p - j] == s[p + j - 1];
}

int min(int x, int y) {
  return x < y? x : y;
}

int max(int x, int y) {
  return x > y? x : y;
}

std::string s;
int n;
int dp[MAXN + 1][MAXN + 1];
int sufiks_max[MAXN + 1][MAXN + 1];
int broj_poklapanja[MAXN + 1];
int poklapanje_plus_ostatak[MAXN + 1];
int resenje;

int main() {
  // efikasnost standardnog ulaza i izlaza
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // ulaz
  std::cin >> s;
  n = s.length();

  // inicijalizacija DP
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = (i == j) - 1;
      sufiks_max[i][j] = 0;
    }
    broj_poklapanja[i] = 0;
    poklapanje_plus_ostatak[i] = 0;
  }

  // DP rekurentna veza
  for (int d = 2; d <= n; d++) {
    broj_poklapanja[1] = poklapanje(s, n, n - d, 1);
    // racunanje sufiksnih maksimuma za dp[d]
    sufiks_max[d][d] = dp[d][d];
    poklapanje_plus_ostatak[0] = 0;
    for (int k = 1; k <= d; k++) {
      sufiks_max[d][d - k] = max(sufiks_max[d][d - k + 1], dp[d][d - k]);
      poklapanje_plus_ostatak[k] = 0;
    }
    // t: razlicite duzine sledeceg reda
    for (int t = 2; t <= min(d, n - d); t++) {
      broj_poklapanja[t] = broj_poklapanja[t - 1] + poklapanje(s, n, n - d, t);
      poklapanje_plus_ostatak[t] = broj_poklapanja[t] + dp[d][t];
      dp[d + t][t] = max(dp[d + t][t], sufiks_max[d][t] + broj_poklapanja[t]);
    }
    // slucaj kada je trenutni red duzi od sledeceg
    int max_do_sad = 0;
    for (int j = 2; j <= n - d; j++) {
      if (j <= d) {
        max_do_sad = max(max_do_sad, poklapanje_plus_ostatak[j]);
      }
      dp[d + j][j] = max(dp[d + j][j], max_do_sad);
    }
  }
  
  // resenje: sve dozvoljene duzine prvog reda
  resenje = dp[n][0];
  for (int i = 1; i <= n; i++) {
    resenje = max(resenje, dp[n][i]);
  }

  // izlaz
  std::cout << resenje << std::endl;
  return 0;
}
