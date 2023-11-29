/* online solution with implicit segment tree */

#include <cstdlib>
#include <cstdio>

const int MAX_N = 250000;
const int MAX_LOG_M = 31;

struct SegmentTree
{
	struct node
	{
		int left, right;
		long long sumVal;
		long long sumProd;
		node()
		{
			left = 0; right = 0;
			sumVal = 0LL; sumProd = 0LL;
		}
	};

	node nodes[MAX_N * MAX_LOG_M];
	int currNode;
	int M;

	void init(int m)
	{
		M = m;
		currNode = 1;
	}

	void update(int nodeNum, int curr_l, int curr_r, int ind, int val)
	{
		if (ind < curr_l || ind > curr_r)
			return;
		nodes[nodeNum].sumVal += val;
		nodes[nodeNum].sumProd += (long long)ind * val;

		if (curr_l != curr_r)
		{
			int mid = (curr_l + curr_r) / 2;

			if (nodes[nodeNum].left == 0)
				nodes[nodeNum].left = ++currNode;
			update(nodes[nodeNum].left, curr_l, mid, ind, val);
			if (nodes[nodeNum].right == 0)
				nodes[nodeNum].right = ++currNode;
			update(nodes[nodeNum].right, mid + 1, curr_r, ind, val);
		}
	}

	long long query(int nodeNum, int curr_l, int curr_r, int l, int r, int ind)
	{
		if (nodeNum == 0 || r < curr_l || l > curr_r)
			return 0LL;
		if (l <= curr_l && curr_r <= r)
		{
			return (nodes[nodeNum].sumVal * ind - nodes[nodeNum].sumProd);
		}

		int mid = (curr_l + curr_r) / 2;
		return query(nodes[nodeNum].left, curr_l, mid, l, r, ind) + query(nodes[nodeNum].right, mid + 1, curr_r, l, r, ind);
	}

	void bulidKiosk(int ind, int val)
	{
		update(1, 1, M, ind, val);
	}

	long long getTotalTime(int ind)
	{
		long long sol = query(1, 1, M, 1, ind, ind);
		sol = sol * 2 - nodes[1].sumVal * ind + nodes[1].sumProd;
		return sol;
	}
};

SegmentTree treex, treey;

int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	treex.init(m);
	treey.init(m);

	for (int i = 1; i <= n; i++)
	{
		int type, x, y, v;
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d%d%d", &x, &y, &v);
			treex.bulidKiosk(x, v);
			treey.bulidKiosk(y, v);
		}
		else
		{
			scanf("%d%d", &x, &y);
			long long sol = treex.getTotalTime(x) + treey.getTotalTime(y);
			printf("%lld\n", sol);
		}

	}
	return 0;
}