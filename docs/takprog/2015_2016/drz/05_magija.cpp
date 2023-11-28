#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MaxN 100010

struct Vestica {
	int t;
	int id;

	Vestica() {}
	Vestica(int _t, int _id) {
		t = _t;
		id = _id;
	}

	bool operator < (const Vestica &other) const {
		if (t != other.t) return t < other.t;
		return id < other.id;
	}
};

int n;
Vestica a[MaxN];
Vestica b[MaxN];
vector<int> edge[MaxN];
bool deleted[MaxN];
vector<int> output;
int currTime;

bool DFS(int node) {
	if (deleted[node]) return true;
	
	for (int i = 0; i < edge[node].size(); ++i) {
		int v = edge[node][i];

		if (!DFS(v)) return false;
	}

	if (currTime > a[node].t) return false;

	currTime++;
	deleted[node] = true;
	output.push_back(node);

	return true;
}

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&a[i].t);
		a[i].id = i;
		b[i] = a[i];
	}

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		scanf("%d %d",&u,&v);

		u--; v--;
		edge[u].push_back(v);
	}

	sort(b, b+n);
	memset(deleted, 0, sizeof(deleted));
	output.clear();
	
	currTime = 1;
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		ok &= DFS(b[i].id);
	}

	if (output.size() == n) {
		for (int i = 0; i < output.size(); ++i) {
			printf("%d ",output[i]+1);
		}
		printf("\n");
	}
	else {
		printf("Pobedila je crna magija\n");
	}

	return 0;
}