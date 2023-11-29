#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 100010;
const double EPS = 1e-8;

struct point
{
	point() {}
	point(int x1, int y1) : x(x1), y(y1) {}
	int x, y;
};

struct pointVal
{
	pointVal() {}
	pointVal(double x1, int v1) : x(x1), val(v1) {}
	double x;
	int val;
};

point points[MAX_N];
int n;
int x, y, a, b;
int opt_sol;

double eq(double a, double b)
{
	return (fabs(a - b) < EPS);
}

bool cmp(pointVal& A, pointVal& B)
{
	if (!eq(A.x, B.x))
		return A.x < B.x;
	return A.val > B.val;
}

// rotacija za 90 stepeni ulevo, (x, y) -> (-y, x)
void rotatePlane(int n, int& w, int& h, point p[])
{
	swap(w, h);
	w = -w; h = -h;
	for (int i = 1; i <= n; i++)
	{
		swap(p[i].x, p[i].y);
		p[i].x = -p[i].x;
	}
}

int outside(int cx, int cy, int x, int y, int n, point p[])
{
	int ret = 0;
	long long rSqr = ((long long)cx - x) * ((long long)cx - x) + ((long long)cy - y) * ((long long)cy - y);
	for (int i = 1; i <= n; i++)
	{
		long long distSqr = ((long long)cx - p[i].x) * ((long long)cx - p[i].x) + ((long long)cy - p[i].y) * ((long long)cy - p[i].y);
		if (distSqr > rSqr) ret++;
	}
	return ret;
}

// (w, h) - gornje-levo teme pravougaonika, centar u (0, 0)
// trazimo optimalan centar na duzi (0,0) - (0, -w) (centar pravougaonika - sredina desne strane)
void solveLine(int n, int w, int h, point p[])
{
	opt_sol = max(opt_sol, outside(-w, 0, w, h, n, p)); // proverimo desni kraj

	double L = 0.0, R = -w;
	vector<pointVal> v; v.clear();
	for (int i = 1; i <= n; i++)
	{
		if (p[i].x == w)
		{
			v.push_back(pointVal(L, 1));
			v.push_back(pointVal(R, -1));
			continue;
		}

		double x = (((double)p[i].y - h) / ((double)p[i].x - w) * ((double)p[i].y + h) + ((double)p[i].x + w)) / 2;

		if (p[i].x > w && x > L)
		{
			v.push_back(pointVal(L, 1));
			v.push_back(pointVal(min(x, R), -1));
		}
		if (p[i].x < w && x < R)
		{
			v.push_back(pointVal(max(L, x), 1));
			v.push_back(pointVal(R, -1));
		}	
	}

	if (v.size() > 0)
	{
		sort(v.begin(), v.end(), cmp);
		int sum = 0, maxSum = -1, optInd = 0;
		for (int i = 0; i < (int)v.size() - 1; i++)
		{
			sum = sum + v[i].val;
			if (!eq(v[i].x, v[i + 1].x))
			{
				if (sum > maxSum)
				{
					maxSum = sum;
					optInd = i;
				}
			}
		}
		opt_sol = max(opt_sol, maxSum);
	}
}

int solve(int n, int a, int b, int x, int y, point p[])
{
	// centriranje pravougaonika i ostalih tacaka
	int w = -a / 2, h = b / 2; // (koordinata novog gornjeg-levog temena)
	for (int i = 1; i <= n; i++)
	{
		p[i].x = p[i].x + (w - x);
		p[i].y = p[i].y + (h - y);
	}
	
	opt_sol = outside(0, 0, w, h, n, p); // provera za centar

	solveLine(n, w, h, p);
	rotatePlane(n, w, h, p);
	solveLine(n, w, h, p);
	rotatePlane(n, w, h, p);
	solveLine(n, w, h, p);
	rotatePlane(n, w, h, p);
	solveLine(n, w, h, p);

	return opt_sol;
}

int main()
{
	scanf("%d", &n);
	scanf("%d%d%d%d", &x, &y, &a, &b);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &points[i].x, &points[i].y);
	}

	int sol = solve(n, a, b, x, y, points);
	printf("%d\n", n - sol);
	return 0;
}
