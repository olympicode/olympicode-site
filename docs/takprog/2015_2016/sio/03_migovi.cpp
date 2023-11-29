#include "migovi.h"

#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 200020;
const int TREE_SIZE = (1 << 19);
const int X_AXIS = 0;
const int Y_AXIS = 1;
const int DIR_UP = 0;
const int DIR_RIGHT = 1;
const int DIR_DOWN = 2;
const int DIR_LEFT = 3;

struct Mig
{
	long long x, y;
	int s;
	int posx, posy;
	Mig(int x, int y, int s) : x(x), y(y), s(s) {}
	Mig() {}
};

Mig migs[MAX_N];
long long pos[MAX_N];
long long dir[MAX_N];
long long sol;

bool cmpX(const Mig& m1, const Mig& m2)
{
	if (m1.x != m2.x) return (m1.x < m2.x);
	return (m1.y < m2.y);
}

bool cmpY(const Mig& m1, const Mig& m2)
{
	if (m1.y != m2.y) return (m1.y < m2.y);
	return (m1.x < m2.x);
}

bool cmpDiffXY(const Mig& m1, const Mig& m2)
{
	if (m1.x - m1.y != m2.x - m2.y) return (m1.x - m1.y < m2.x - m2.y);
	return (m1.x < m2.x);
}

struct SegmentTree
{
	int axis;
	int count[TREE_SIZE];
	long long sum[TREE_SIZE];

	void init(int axis)
	{
		this->axis = axis;
		memset(count, 0, sizeof(count));
		memset(sum, 0, sizeof(sum));
	}

	// add value val at position pos
	void add(int pos, long long val)
	{
		pos = pos + (TREE_SIZE >> 1) - 1;
		while (pos > 0)
		{
			count[pos] = count[pos] + 1;
			sum[pos] = sum[pos] + val;
			pos = (pos >> 1);
		}
	}

	// calculate sum[l..r] - count[l..r] * val
	long long calculate(int node, int node_L, int node_R, int l, int r, long long val)
	{
		if (node_R < l || node_L > r)
			return 0;
		if (l <= node_L && node_R <= r)
			return (sum[node] - val * count[node]);

		int node_M = (node_L + node_R) >> 1;
		return calculate((node << 1), node_L, node_M, l, r, val) + calculate((node << 1) + 1, node_M + 1, node_R, l, r, val);
	}

	void addMig(Mig& mig)
	{
		if (axis == X_AXIS)
			add(mig.posx, mig.x);
		else
			add(mig.posy, mig.y);
	}

	long long extraSum(Mig& mig)
	{
		if (axis == X_AXIS)
			return calculate(1, 1, (TREE_SIZE >> 1), mig.posx, (TREE_SIZE >> 1), mig.x);
		else
			return calculate(1, 1, (TREE_SIZE >> 1), mig.posy, (TREE_SIZE >> 1), mig.y);
	}


};

SegmentTree xTree, yTree;

long long SolveByCoordinate(int N, Mig* migs, int axis, int forwardDir, int backDir)
{
	long long res = 0LL;

	if (axis == X_AXIS)
		sort(migs, migs + N, cmpX);
	else
		sort(migs, migs + N, cmpY);

	for (int i = 0; i < N; i++)
	{
		dir[i] = migs[i].s;
		pos[i] = (axis == X_AXIS ? migs[i].x : migs[i].y);
	}

	// suma svih |pos[i] - pos[j]|
	long long totalSum = 0LL;
	for (int i = 0; i < N; i++)
	{
		res = res + (pos[i] * i - totalSum);
		totalSum = totalSum + pos[i];
	}

	// oduzeti rastojanja izmedju onih migova koji idu jedan ka drugom
	long long forwardSum = 0LL;
	long long forwardNum = 0LL;
	for (int i = 0; i < N; i++)
	{
		if (dir[i] == backDir)
		{
			res = res - (pos[i] * forwardNum - forwardSum);
		}
		else if (dir[i] == forwardDir)
		{
			forwardNum = forwardNum + 1;
			forwardSum = forwardSum + pos[i];
		}
	}

	return res;
}

// Rotiramo ravan za 90 stepeni ulevo
void RotateLeft(int N, Mig* migs)
{
	for (int i = 0; i < N; i++)
	{
		migs[i].s = (migs[i].s + 3) % 4;
		long long x = migs[i].x;
		long long y = migs[i].y;
		migs[i].x = -y;
		migs[i].y = x;
	}
}

// Kompenzacija koju treba oduzeti za migove koji idu
// udesno i na dole jedan ka drugom
long long SolveRightDown(int N, Mig* migs)
{
	long long ret = 0LL;

	sort(migs, migs + N, cmpX);
	for (int i = 0; i < N; i++)
		migs[i].posx = i + 1;

	sort(migs, migs + N, cmpY);
	for (int i = 0; i < N; i++)
		migs[i].posy = i + 1;

	sort(migs, migs + N, cmpDiffXY);

	xTree.init(X_AXIS);
	for (int i = 0; i < N; i++)
	{
		if (migs[i].s == DIR_RIGHT)
		{
			ret = ret + xTree.extraSum(migs[i]);
		}
		if (migs[i].s == DIR_DOWN)
		{
			xTree.addMig(migs[i]);
		}
	}

	yTree.init(Y_AXIS);
	for (int i = N - 1; i >= 0; i--)
	{
		if (migs[i].s == DIR_RIGHT)
		{
			ret = ret + yTree.extraSum(migs[i]);
		}
		if (migs[i].s == DIR_DOWN)
		{
			yTree.addMig(migs[i]);
		}
	}

	return ret * 2;
}


long long ZbirRastojanja(int N, int * x, int * y, int * s)
{
	for (int i = 0; i < N; i++)
		migs[i] = Mig(x[i], y[i], s[i]);

	sol = 0;
	// suma svih pocetnih rastojanja - kompenzacija za one koji idu jedni ka drugima
	sol = sol + SolveByCoordinate(N, migs, X_AXIS, DIR_RIGHT, DIR_LEFT);
	sol = sol + SolveByCoordinate(N, migs, Y_AXIS, DIR_UP, DIR_DOWN);

	// sada je potrebno za svaka dva miga koji idu normalno jedan ka drugom
	// oduzeti 2 * Min(distX, distY), gde su distX i distY pocenta rastojanja po x i y osi
	sol = sol - SolveRightDown(N, migs);
	RotateLeft(N, migs);
	sol = sol - SolveRightDown(N, migs);
	RotateLeft(N, migs);
	sol = sol - SolveRightDown(N, migs);
	RotateLeft(N, migs);
	sol = sol - SolveRightDown(N, migs);

	return sol;
}
