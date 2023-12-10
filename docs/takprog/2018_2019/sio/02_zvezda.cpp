#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

static const int M = 1000000007;
static const int N = 1005;


long long d[2 * N][2 * N][3];
int b[2 * N];

int Zvezda(int n, int* a)
{
    for(int i = 1; i <= n; i++)
    {
        b[i] = a[i];
        b[i + n] = a[i];
    }

    for(int i = 1; i <= 2 * n; i++)
        for(int j = 1; j <= 2 * n; j++)
            for(int k = 0; k < 3; k++)
                d[i][j][k] = 0;

    for(int i = 1; i <= 2 * n; i++)
    {
        d[i][i][2] = 1;
        d[i][i + 1][b[i]] = 1;
    }

    for(int g = 4; g <= n; g += 4)
    {
        // deo za ceo

        for(int i = 1; i <= n; i++)
        {
            int j = i + g;
            for(int s = i + 2; s + 1 < j; s += 4)
            {
                if(b[i] == b[s])
                {
                    d[i][j][2] += d[i + 1][s][0] * d[s + 1][j][1];
                    d[i][j][2] += d[i + 1][s][1] * d[s + 1][j][0];
                }
                else
                {
                    d[i][j][2] += d[i + 1][s][0] * d[s + 1][j][0];
                    d[i][j][2] += d[i + 1][s][1] * d[s + 1][j][1];
                }
            	d[i][j][2] %= M;
            }
        }

        // deo sa ostatkom

        for(int i = 1; i <= n; i++)
        {
            int j = i + g + 1;
            for(int s = i; s <= j; s += 4)
	    {
                d[i][j][b[s]] += d[i][s][2] * d[s + 1][j][2];
	        d[i][j][b[s]] %= M;
	    }   
        }
    }

    return d[1][n + 1][2];
}

int main()
{
    int A[N];
    int n;

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> A[i];

    cout << Zvezda(n, A) << endl;
    return 0;
}
