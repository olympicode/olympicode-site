#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX_N = 500005;
const int MOD = 1000000007;

int s[MAX_N];
int index_left[MAX_N];
int L[MAX_N];
int R[MAX_N];
int d[MAX_N];
int preff_sum[MAX_N];

int sum(int l, int r)
{
	if (l == 0)
		return preff_sum[r];
	else
		return (preff_sum[r] - preff_sum[l - 1]) % MOD;
}

int TamanPodela(int N, int a[])
{
	// index_left[i] = najveci indeks j <= i takav da je a[j..i] taman podniz ili <= 0 ako takvo j ne postoji
	// dovoljno je samo proveravati uslov (i - j + 1) >= min[j..i]
	// koristimo dequeue gde odrzavamo strogo rastuce vrednosti
	int l = 1, r = 0;
	for (int i = 1; i <= N; i++)
	{
		while (l <= r && a[i] <= a[s[r]]) r--;
		s[++r] = i;
		if (l < r && min(s[l], i - a[s[l]] + 1) <= min(s[l + 1], i - a[s[l + 1]] + 1)) l++;
		index_left[i] = min(s[l], i - a[s[l]] + 1);
	}

	// L[i] - najveci indeks j < i tako da je a[j] > a[i]
	for (int i = 1; i <= N; i++)
	{
		int curr = i - 1;
		while (curr != 0 && a[curr] <= a[i])
			curr = L[curr];
		L[i] = curr;
	}
	// R[i] - najmanji indeks j > i tako da je a[j] >= a[i]
	for (int i = N; i >= 1; i--)
	{
		int curr = i + 1;
		while (curr <= N && a[curr] < a[i])
			curr = R[curr];
		R[i] = curr;
	}

	// d[i] = optimalno resenje za podniz a[1..i]
	for (int i = 1; i <= N; i++) d[i] = 0;
	d[0] = 1;
	preff_sum[0] = 1;
	int currSum = 0;
	for (int i = 1; i <= N; i++)
	{
		currSum = (currSum + d[i]) % MOD;
		// dodati d[l..r] trenutnoj sumi
		int r = i - 1;
		int l = max(i - a[i], L[i]);
		currSum = (currSum + sum(l, r)) % MOD;

		// unapred oduzeti d[curr] odgovarajucim d[]-ovima
		int curr = l;
		while (curr + a[i] + 1 < R[i] && curr < i)
		{
			d[curr + a[i] + 1] = (d[curr + a[i] + 1] - d[curr]) % MOD;
			curr++;
		}
		if (curr + a[i] + 1 >= R[i])
			d[R[i]] = (d[R[i]] - sum(curr, r)) % MOD;

		// izracunati d[i]
		if (index_left[i] <= 0)
			d[i] = 0;
		else
			d[i] = (currSum - sum(index_left[i], i - 1)) % MOD;

		if (d[i] < 0) d[i] = (d[i] + MOD) % MOD;
		preff_sum[i] = (preff_sum[i - 1] + d[i]) % MOD;
	}

	return d[N];
}
