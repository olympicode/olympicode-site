#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

int n, m;
int a[MAX_N + 10];
long long pref[MAX_N + 10];

// max ind tako da a[ind] < val
int lastLessThan(int l, int r, int a[], double val)
{
	if (l > r || !(val > a[l]))
		return l - 1;
	while (l < r)
	{
		int m = (l + r + 1) / 2;
		if (a[m] < val)
			l = m;
		else
			r = m - 1;
	}
	return l;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	sort(a + 1, a + n + 1);
	pref[0] = 0LL;
	for (int i = 1; i <= n; i++)
		pref[i] = pref[i - 1] + a[i];

	for (int i = 1; i <= m; i++)
	{
		int A, B;
		scanf("%d%d", &A, &B);
		if (A > B)
			swap(A, B);
		int Y = lastLessThan(1, n, a, (A + B) / 2.0);
		// [1, Y] u A, [Y + 1, n] u B
		
		int X = lastLessThan(1, Y, a, A);
		int Z = lastLessThan(Y + 1, n, a, B);
		// a[1] <= a[2] <= ... <= a[X] < A <= a[X+1] <= ... <= a[Y] < (A + B)/2 < a[Y+1] <= ... <= a[Z] < B <= a[Z+1] <= ... <= a[n]
		long long sol 
			= ((long long)A * X - pref[X]) 
			+ (pref[Y] - pref[X] - (long long)A * (Y - X))
			+ ((long long)B * (Z - Y) - (pref[Z] - pref[Y])) 
			+ (pref[n] - pref[Z] - (long long)B * (n - Z));
		printf("%lld\n", sol);
	}

	return 0;
}