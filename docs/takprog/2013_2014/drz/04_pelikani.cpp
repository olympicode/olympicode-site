#include <cstdlib>
#include <cstdio>

const int MaxN = 1010;

const int c = 0;
const int u = 1;
const int l = 2;
const int d = 3;
const int r = 4;
const int ur = 5;
const int ru = 6;
const int dr = 7;
const int rd = 8;
const int dl = 9;
const int ld = 10;
const int ul = 11;
const int lu = 12;

int n, q;
bool a[MaxN][MaxN], b[MaxN][MaxN];
int ns[13][5]; // next state
int col[13][MaxN], row[13][MaxN];
int cnt[MaxN];
char s[MaxN];
int state, dir;

void transform(int old[], int new1[], int new2[], int currDir)
{
	for (int i = 0; i <= n; i++)
		cnt[i] = 0;

	for (int i = 1; i <= n; i++)
	{
		new1[i] = old[i];
		cnt[ old[i] ]++;
	}

	new2[n] = cnt[n];
	for (int i = n - 1; i >= 1; i--)
		new2[i] = new2[i + 1] + cnt[i];

	if (currDir > 2)
	{
		for (int i = 1; i <= n / 2; i++)
		{
			int tmp = new2[i]; new2[i] = new2[n - i + 1]; new2[n - i + 1] = tmp;
		}
	}
}

int answer(int x, int y)
{
	if (state == 0) return (a[x][y] ? 1 : 0);

	if (dir == 1) return (col[state][y] >= x ? 1 : 0);
	if (dir == 2) return (row[state][x] >= y ? 1 : 0);
	if (dir == 3) return (col[state][y] >= n - x + 1 ? 1 : 0);
	if (dir == 4) return (row[state][x] >= n - y + 1 ? 1 : 0);
	return 0;

}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 1; j <= n; j++)
			a[i][j] = (s[j - 1] == '1' ? true : false);
	}

	for (int i = 1; i <= n; i++)
	{
		row[c][i] = 0;
		col[c][i] = 0;
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j]) row[c][i]++;
			if (a[j][i]) col[c][i]++;
		}
	}
	
	transform(row[c], row[l], col[l], l);
	transform(row[c], row[r], col[r], r);
	transform(col[c], col[u], row[u], u);
	transform(col[c], col[d], row[d], d);

	transform(row[u], row[ur], col[ur], r);
	transform(row[u], row[ul], col[ul], l);
	transform(row[d], row[dr], col[dr], r);
	transform(row[d], row[dl], col[dl], l);

	transform(col[l], col[lu], row[lu], u);
	transform(col[l], col[ld], row[ld], d);
	transform(col[r], col[ru], row[ru], u);
	transform(col[r], col[rd], row[rd], d);

	ns[c][u] = u; ns[c][l] = l; ns[c][d] = d; ns[c][r] = r;

	ns[u][u] = u; ns[u][l] = ul; ns[u][d] = d; ns[u][r] = ur;
	ns[l][u] = lu; ns[l][l] = l; ns[l][d] = ld; ns[l][r] = r;
	ns[d][u] = u; ns[d][l] = dl; ns[d][d] = d; ns[d][r] = dr;
	ns[r][u] = ru; ns[r][l] = l; ns[r][d] = rd; ns[r][r] = r;

	ns[ul][u] = ul; ns[ul][l] = ul; ns[ul][d] = dl; ns[ul][r] = ur;
	ns[ur][u] = ur; ns[ur][l] = ul; ns[ur][d] = dr; ns[ur][r] = ur;
	ns[dl][u] = ul; ns[dl][l] = dl; ns[dl][d] = dl; ns[dl][r] = dr;
	ns[dr][u] = ur; ns[dr][l] = dl; ns[dr][d] = dr; ns[dr][r] = dr;

	ns[lu][u] = lu; ns[lu][l] = lu; ns[lu][d] = ld; ns[lu][r] = ru;
	ns[ru][u] = ru; ns[ru][l] = lu; ns[ru][d] = rd; ns[ru][r] = ru;
	ns[ld][u] = lu; ns[ld][l] = ld; ns[ld][d] = ld; ns[ld][r] = rd;
	ns[rd][u] = ru; ns[rd][l] = ld; ns[rd][d] = rd; ns[rd][r] = rd;

	scanf("%d", &q);
	state = 0;
	dir = 0;

	for (int num = 1; num <= q; num++)
	{
		int val, x, y;
		scanf("%d", &val);
		if (val == 1)
		{
			scanf("%d", &dir);
			state = ns[state][dir];
		}
		else
		{
			scanf("%d%d", &x, &y);
			printf("%d\n", answer(x, y));
		}

	}

	return 0;
}