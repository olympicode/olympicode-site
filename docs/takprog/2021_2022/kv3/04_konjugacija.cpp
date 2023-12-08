#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_N = 150000;
const int TREE_SIZE = (1 << 19);

struct point
{
	int type; // 1 - left query, 2 - value, 3 - right query
	int ind;
	int position;

	point(int t, int i, int p)
	{
		type = t; ind = i; position = p;
	}
};

struct point2
{
	int type; // 1 - query, 2 - array element
	int val;
	int ind;

	point2(int t, int v, int i)
	{
		type = t; val = v; ind = i;
	}
};

struct query
{
	int l, r;
	int val;
};

bool cmp(const point& A, const point& B)
{
	if (A.position != B.position)
		return (A.position < B.position);
	return (A.type < B.type); 
}

bool cmp2(const point2& A, const point2& B)
{
	if (A.val != B.val)
		return (A.val > B.val);
	return (A.type > B.type);
}

struct SegmentTree
{
	int sum[TREE_SIZE];

	void init()
	{
		for (int i = 0; i < TREE_SIZE; i++) sum[i] = 0;
	}

	// add 1 at position pos
	void add(int pos)
	{
		pos = pos + (TREE_SIZE >> 1) - 1;
		while (pos > 0)
		{
			sum[pos] = sum[pos] + 1;
			pos = (pos >> 1);
		}
	}

	// calculate sum[l..r]
	long long calc(int node, int node_L, int node_R, int l, int r)
	{
		if (node_R < l || node_L > r)
			return 0;
		if (l <= node_L && node_R <= r)
			return (sum[node]);

		int node_M = (node_L + node_R) >> 1;
		return calc((node << 1), node_L, node_M, l, r) + calc((node << 1) + 1, node_M + 1, node_R, l, r);
	}
};

int N;
long long sol;
int l[MAX_N + 10], r[MAX_N + 10];

vector<point> points;
vector<point2> points2;
int A[MAX_N + 10];
query Q[MAX_N + 10];
SegmentTree tree;

int main()
{
	scanf("%d", &N);
	sol = 0LL;

	for (int i = 1; i <= N; i++)
	{	// dupliramo koordinate da bi centar bio ceo broj
		scanf("%d%d", &l[i], &r[i]);
		int c = l[i] + r[i];
		l[i] = 2 * l[i];
		r[i] = 2 * r[i];
		points.push_back(point(1, i, l[i]));
		points.push_back(point(2, i, c));
		points.push_back(point(3, i, c - 1));
		Q[i].val = c;
	}

	// kompresujemo koordinate
	sort(points.begin(), points.end(), cmp);

	int currInd = 0;
	for (int i = 0; i < (int)points.size(); i++)
	{
		if (points[i].type == 2)
		{
			A[++currInd] = r[points[i].ind];
		}
		else
		{
			if (points[i].type == 1)
			{
				Q[points[i].ind].l = currInd + 1;
			}
			else
			{
				Q[points[i].ind].r = currInd;
			}
		}
	}

	// posebno racunamo kada se centri segmenata poklapaju
	int lastPos = -1, cnt = 0;
	for (int i = 0; i < (int)points.size(); i++)
	{
		if (points[i].type == 2)
		{
			if (points[i].position == lastPos)
				cnt++;
			else
			{
				cnt = 0;
				lastPos = points[i].position;
			}
			sol = sol + cnt;
		}
	}

	// Sada je problem ekvivalentan sa: dat je niz A[1..N] i N upita (l,r,v) sa znacenjem:
	// koliko ima elemenata u podnizu A[l..r] koji su veci ili jednaki od k?
	// Resenje je suma odgovora na sve upite. Ovo radimo offline sortiranjem upita
	// opadajuce po parametru k i dodavanjem odgovarajucih elemenata niza i brojanjem istih
	// koristeci segmentno stablo.

	for (int i = 1; i <= N; i++)
	{
		points2.push_back(point2(1, Q[i].val, i));
		points2.push_back(point2(2, A[i], i));
	}
	sort(points2.begin(), points2.end(), cmp2);
	tree.init();

	for (int i = 0; i < (int)points2.size(); i++)
	{
		if (points2[i].type == 1) // query
		{
			int left = Q[points2[i].ind].l;
			int right = Q[points2[i].ind].r;
			if (left <= right)
				sol = sol + tree.calc(1, 1, (TREE_SIZE >> 1), left, right);
		}
		if (points2[i].type == 2) // add element
		{
			tree.add(points2[i].ind);
		}
	}

	printf("%lld\n", sol);

	return 0;
}