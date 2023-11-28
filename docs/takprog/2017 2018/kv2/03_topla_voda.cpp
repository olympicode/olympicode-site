#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> e[300005];
int p[300005];
bool topla[300005];

int main() {
	scanf("%d", &n);
	for (int i=1; i<n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	queue<int> q;
	p[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (!p[y]) {
				p[y] = x;
				q.push(y);
			}
		}
	}

	topla[1] = true;

	int m;
	scanf("%d", &m);
	while (m--) {
		int x, y = 0;
		scanf("%d", &x);
		while (!topla[x]) {
			topla[x] = true;
			x = p[x];
			y++;
		}
		printf("%d\n", y);
	}
}