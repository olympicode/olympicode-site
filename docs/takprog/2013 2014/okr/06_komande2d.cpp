#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 1000005;
const int MAX_K = 1005;

int n, k, x, y;
char s[MAX_N];
int pos[2 * MAX_K][2 * MAX_K];
vector<int> List[2 * MAX_K][2 * MAX_K];

int dx[] = {0,  -1, 1,  0};
int dy[] = {1,   0, 0, -1};

int decode(char ch) {
	if (ch == 'U') return 0;
	if (ch == 'L') return 1;
	if (ch == 'R') return 2;
	return 3;
}

int main() {
	scanf("%d%d%d%d", &n, &k, &x, &y);
	scanf("%s", s);
	int sx = 0;
	int sy = 0;
	for (int i = 0; i < n; ++i) {
		sx += dx[decode(s[i])];
		sy += dy[decode(s[i])];
		if (sx < -k || sx > k) break;
		if (sy < -k || sy > k) break;
		List[sx + k][sy + k].push_back(i);
	}

	for (int i = 0; i < 2 * MAX_K; ++i)
		for (int j = 0; j < 2 * MAX_K; ++j)
			pos[i][j] = List[i][j].size() - 1;

	sx = x;
	sy = y;
	int res = 987654321;
	int sta, end;
	for (int i = n - 1; i >= 0; --i) {
		sx += dx[3 - decode(s[i])];
		sy += dy[3 - decode(s[i])];
		if (sx < -k || sx > k) break;
		if (sy < -k || sy > k) break;
		while (pos[sx + k][sy + k] >= 0 && 
			   List[sx + k][sy + k][pos[sx + k][sy + k]] >= i)
			--pos[sx + k][sy + k];

		if (pos[sx + k][sy + k] >= 0) {
			int tmp = i - List[sx + k][sy + k][pos[sx + k][sy + k]];
			if (res > tmp) {
				res = tmp;
				sta = i - tmp + 1;
				end = i - 1;
			}
		}
	}

	if (res != 987654321) printf("%d %d\n", sta + 1, end + 1);
	else printf("-1\n");

	return 0;
}