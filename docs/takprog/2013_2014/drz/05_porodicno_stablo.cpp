#include<stdio.h>
#include <stdlib.h>
#include<vector>
#include<math.h>
#include<ctime>

#define MAX_N 10005
#define MAX_S 10005


int N, S, sol, s[MAX_N], parent[MAX_N], added[2 * MAX_S], numAdded[MAX_N], k;
std::vector<int> children[MAX_N];
bool d[MAX_S * 2 + 1], mark[2 * MAX_S + 1];

void input()
{
	scanf("%d %d", &N, &S);
	int deg, child;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = -1;
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &s[i + 1], &deg);
		for (int j = 0; j < deg; j++)
		{
			scanf("%d", &child);
			children[i + 1].push_back(child);
			parent[child] = i + 1;
		}
	}
#endif
}

void Visit(int node)
{
	numAdded[node] = 0;
	for (int currentS = 2 * MAX_S; currentS >= 0; currentS--)
	{
		if (d[currentS])
		{
			if ((currentS + s[node] <= 2 * MAX_S) && (!d[currentS + s[node]]))
			{
				added[k] = currentS + s[node];
				k++;
				numAdded[node]++;
				d[currentS + s[node]] = true;
				mark[currentS + s[node]] = true;

				if (abs(currentS + s [node] - S) < abs(sol - S) ||
					((abs(currentS + s [node] - S) == abs(sol - S)) && (currentS + s[node] < sol)))
				{
					sol = currentS + s[node];
				}
			}
		}
	}
	for(int i = 0; i < children[node].size(); i++)
	{
		Visit(children[node][i]);
	}
	for (int i = 0; i < numAdded[node]; i++)
	{
		d[added[k - i - 1]] = false;
		added[k - i - 1] = 0;
	}
	k = k - numAdded[node];
}

void solve()
{
	int rootNode = 1;
	while (parent[rootNode] != -1)
	{
		rootNode++;
	}
	for (int i = 1; i <= 2 * MAX_S; i++)
	{
		d[i] = false;
		mark[i] = false;
	}
	d[0] = true;
	sol = 0;
	k = 0;
	Visit(rootNode);
}

void output()
{
	printf("%d\n", sol);
}

int main()
{
	input();
	solve();
	output();
	return 0;
}