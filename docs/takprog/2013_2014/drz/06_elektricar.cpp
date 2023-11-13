#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int MaxN = 300300;
const long long INF = 2000000000000000000LL;

struct Pole
{
	int x, c;
	bool hasHouseOnTheLeft;
	long long extraVal;

	Pole() {}
	Pole(int _x, int _c)
	{
		x = _x; c = _c;
	}
};

int n, m, C, D;
Pole poles[MaxN];
int hx[MaxN];
long long sol[MaxN];
long long deQueue[2 * MaxN];

// vraca optimalnu cenu sistema za dato S
long long solve(int S)
{
	sol[0] = 0LL;
	int first = 0, last = -1;
	for (int i = 1; i <= n; i++)
	{

// --------------- racunanje optimalnog uparivanja 100p ---------------------- */
		long long optimalPairVal = INF;
		
		while (first <= last && poles[i].x - poles[ deQueue[first] ].x > D)
		{
			first++;
		}
		
		if (first <= last)
		{
			optimalPairVal = poles[ deQueue[first] ].extraVal + (long long)(S) * (long long)(poles[i].x) + poles[i].c;
		}

		if (!poles[i].hasHouseOnTheLeft)
		{
			poles[i].extraVal = sol[i - 1] - (long long)(S) * (long long)(poles[i].x) + poles[i].c;
			while (first <= last && poles[i].extraVal <= poles[ deQueue[last] ].extraVal)
			{
				last--;
			}
			deQueue[++last] = i;
		}
// --------------------------------------------------------------------------- */

		if (poles[i].hasHouseOnTheLeft) // ako je (odmah) levo od i-te bandere kuca, uparivanje sigurno posotji i moramo ga izvrsiti 
		{
			sol[i] = optimalPairVal;
		}
		else
		{
			sol[i] = min(sol[i - 1], optimalPairVal); // inace uzimamo bolju od varijante upariti ili ne upariti (ako ne postoji uparivanje, min(sol[i - 1], INF) = sol[i - 1])
		}

	}

	return sol[n];
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &D, &C);
	for (int i = 1; i <= n; i++)
		scanf("%d", &poles[i].c);
	for (int i = 1; i <= n; i++)
		scanf("%d", &poles[i].x);
	for (int i = 1; i <= m; i++)
		scanf("%d", &hx[i]);

	// prvo odredimo za svaku banderu da li je odmah levo od nje kuca

	int ind = 1;  // indeks trenutne kuce
	poles[1].hasHouseOnTheLeft = false;
	for (int i = 2; i <= n; i++)
	{
		poles[i].hasHouseOnTheLeft = (poles[i].x > hx[ind] && hx[ind] > poles[i - 1].x);
		while (ind < m && hx[ind] < poles[i].x) ind++;
	}

	// S nalazimo uz pomoc binarne pretrage

	int left = 1, right = C, mid;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		long long val = solve(mid);
		if (val == C)
		{
			printf("%d\n", mid);
			return 0;
		}

		if (val < C)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return 0;
}