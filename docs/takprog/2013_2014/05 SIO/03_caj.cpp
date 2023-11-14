#include "caj.h"

#include <cstdlib>
#include <memory.h>
#include <vector>

using namespace std;

const int MaxN = 100100;
const int LogMaxN = 18;
const int MaxM = 200200;

vector<int> adjT[MaxN];  // lista suseda racunajuci samo tree-edges
vector<int> ADJ[MaxN];   // lista suseda u grafu koji pravimo od datog: u->v ako u mora pre v
vector<int> ADJ_REV[MaxN];
int inDeg[MaxN];
int currRoot;
int time;
int dfsIn[MaxN], dfsOut[MaxN];
int level[MaxN], parent[MaxN];
int P[MaxN][LogMaxN];

void DFS(int u)
{
	dfsIn[u] = ++time;

	if (u != 0)
	{
		if (inDeg[u] == 0)
			currRoot = u;
		else
			ADJ[currRoot].push_back(u); // Koren svakog DFS stabla mora biti pre sve svoje dece u listi
	}

	for (int i = 0; i < (int)adjT[u].size(); i++)
	{
		int v = adjT[u][i];
		parent[v] = u;
		level[v] = level[u] + 1;
		DFS(v);
	}

	dfsOut[u] = ++time;
}

int kthAnc(int u, int k)
{
	int i = 0;
	while (k > 0)
	{
		if ((k & 1) != 0)
			u = P[u][i];
		i++;
		k = k >> 1;
	}

	return u;
}

int lca(int u, int v)
{
    if (level[u] < level[v])
	{
          int tmp = u; u = v; v = tmp;
	}

	int log = 1;
	while ((1 << log) <= level[u]) 
		log++;
	log--;
	
    for (int i = log; i >= 0; i--)
	{
		if ((1 << i) <= level[u] - level[v])
              u = P[u][i];
	}

	if (u == v)
		return u;
	
    for (int i = log; i >= 0; i--)
          if (P[u][i] != -1 && P[v][i] != -1 && P[u][i] != P[v][i])
		  {
              u = P[u][i];
			  v = P[v][i];
		  }
	
    return parent[u];
}

void TopSort(int N, int* L)
{
	memset(inDeg, 0, sizeof(inDeg));
	for (int u = 1; u <= N; u++)
	{
		for (int i = 0; i < (int)ADJ[u].size(); i++)
		{
			int v = ADJ[u][i];
			ADJ_REV[v].push_back(u);
			inDeg[u]++;
		}
	}

	int first = 0, last = 0;

	for (int u = 2; u <= N; u++)  // od 2
		if (inDeg[u] == 0)
			L[++last] = u;

	if (last == 0)
	{
		L[++last] = 1;
		if (inDeg[1] != 0) { printf("FAIL\n"); return; }
	}

	while (first < last)
	{
		first++;
		int u = L[first];

		for (int i = 0; i < (int)ADJ_REV[u].size(); i++)
		{
			int v = ADJ_REV[u][i];
			inDeg[v]--;
			if (inDeg[v] == 0 && v != 1)
				L[++last] = v;
		}

		if (first == last && last != N)
		{
			L[++last] = 1;
			if (inDeg[1] != 0) { printf("FAIL\n"); return; }
		}
	}

	if (last != N) { printf("FAIL\n"); return; }

	for (int i = 1; i <= N / 2; i++)
	{
		int tmp = L[i]; L[i] = L[N - i + 1]; L[N - i + 1] = tmp;
	}
}

void OdrediListu(int N, int M, int* c1, int* c2, int* g, int* L)
{
	memset(inDeg, 0, sizeof(inDeg));
	for (int i = 1; i <= M; i++)
	{
		if (g[i] == 1)
		{
			adjT[ c1[i] ].push_back(c2[i]);
			inDeg[ c2[i] ]++;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (inDeg[i] == 0)
			adjT[0].push_back(i);
	}

	level[0] = 0;
	parent[0] = -1;
	time = 0;
	DFS(0);

	// racunamo tablicu za LCA
	for (int i = 0; i <= N; i++)
		P[i][0] = parent[i];

	for (int j = 1; (1 << j) <= N; j++) 
		for (int i = 0; i <= N; i++)
			if (P[i][j - 1] != -1)
				P[i][j] = P[ P[i][j - 1] ][j - 1];
			else
				P[i][j] = -1;

	// na osnovu "cross" i "forward" edges dodajemo jos grana u novom grafu
	for (int i = 1; i <= M; i++)
	{
		if (g[i] == 0)
		{
			int u = c1[i], v = c2[i];

			if (dfsIn[u] < dfsIn[v] && dfsOut[v] < dfsOut[u]) // forward edge
			{
				int v1 = kthAnc(v, level[v] - level[u] - 1);
				ADJ[v1].push_back(v);
			}

			if (dfsOut[u] < dfsIn[v] || dfsOut[v] < dfsIn[u]) // cross edge
			{
				int x = lca(u, v);
				int u1 = kthAnc(u, level[u] - level[x] - 1);
				int v1 = kthAnc(v, level[v] - level[x] - 1);
				ADJ[v1].push_back(u1);
			}
		}
	}

	TopSort(N, L);
}
