/*
 Author: Petar 'PetarV' Velickovic
 Task: Dzokeri 
*/

#include <iostream>
#include <string>

#define MAX_N 1005
#define NEGINF -99999999999999999LL

using namespace std;

typedef long long lld;

int n, m;
lld x, y;
string A, B;

lld dn[MAX_N][MAX_N];
lld rt[MAX_N][MAX_N];
lld md[MAX_N][MAX_N];

int main(int argc, char **argv)
{
    cin >> n >> m >> x >> y;
    cin >> A >> B;
    
    // Simple base case: zero-cost to begin with
    dn[0][0] = rt[0][0] = md[0][0] = 0LL;
    
    // Base case: extending an initial wildcard-gap downwards only
    for (int i=1;i<=n;i++)
    {
        dn[i][0] = md[i][0] = -x - i * y;
        rt[i][0] = NEGINF;
    }

    // Base case: extending an initial wildcard-gap rightwards only
    for (int j=1;j<=m;j++)
    {
        rt[0][j] = md[0][j] = -x - j * y;
        dn[0][j] = NEGINF;
    }

    // Recurrence relation
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            dn[i][j] = max(dn[i - 1][j] - y, md[i - 1][j] - x - y);
            rt[i][j] = max(rt[i][j - 1] - y, md[i][j - 1] - x - y);
            md[i][j] = max(dn[i][j], rt[i][j]);
            if (A[i - 1] == B[j - 1])
            {
                md[i][j] = max(md[i][j], md[i - 1][j - 1] + 1);
            }
        }
    }

    cout << md[n][m] << endl;
    return 0;
}
