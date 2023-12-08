#include<cstdlib>
#include<cstdio>
#include<vector>

using namespace std;

const int MOD = 1000000007;
const int MAX_N = 2000;

int n, m, k;
char a[MAX_N + 10][MAX_N + 10];
int dp[MAX_N + 10][2];
vector<int> v;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", a[i] + 1);
	}

	int curr = 0;
	for (int j = 1; j <= m; j++)
		if (a[n][j] == '0')
			dp[j][curr] = 1;
		else
			dp[j][curr] = 0;

	for (int i = n; i > 1; i--)
	{
		curr = 1 - curr;
		for (int j = 0; j <= m; j++)
			dp[j][curr] = 0;

		// left
		v.clear();
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == '1')
				v.push_back(j);
			else
			{
				int left = 0;
				if ((int)v.size() > k)
					left = v[v.size() - (k + 1)] + (k + 1);
				else
					left = v.size() + 1;
				dp[left][curr] = (dp[left][curr] + dp[j][1 - curr]) % MOD;
				dp[j][curr] = (dp[j][curr] - dp[j][1 - curr]) % MOD;
			}
		}

		// right
		v.clear();
		for (int j = m; j >= 1; j--)
		{
			if (a[i][j] == '1')
				v.push_back(j);
			else
			{
				int right = 0;
				if ((int)v.size() > k)
					right = v[v.size() - (k + 1)] - (k + 1);
				else
					right = m - v.size();
				dp[j][curr] = (dp[j][curr] + dp[j][1 - curr]) % MOD;
				dp[right + 1][curr] = (dp[right + 1][curr] - dp[j][1 - curr]) % MOD;
			}
		}

		for (int j = 1; j <= m; j++)
			dp[j][curr] = (dp[j][curr] + dp[j - 1][curr]) % MOD;
		for (int j = 1; j <= m; j++)
			if (a[i - 1][j] == '1') dp[j][curr] = 0;
	}

	int sol = 0;
	for (int j = 1; j <= m; j++)
		sol = (sol + dp[j][curr]) % MOD;
	if (sol < 0)
		sol = sol + MOD;
	printf("%d\n", sol);

	return 0;
}