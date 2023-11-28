#include <iostream>

using namespace std;

const long long MOD = 1000000007;

int main()
{
	long long n, m, id;
	cin >> n >> m >> id;

	int high = m / id - 1;
	int low = 0;
	for(int i = 1; i * i <= id; i++)
		if(id % i == 0)
		{
			low++;
			if(i*i != id && id/i < id) low++;
		}

	if(high + 1 < n || low + 1 < n)
	{
		cout << 0 << endl;
		return 0;
	}
	
	long long res = 2;
	for(int i = 0; i < n - 1; i++)
	{
		res *= high - i;
		res %= MOD;
		res *= low - i;
		res %= MOD;
	}

	cout << res << endl;
	return 0;
}
