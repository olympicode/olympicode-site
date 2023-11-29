/*
 Author: Petar 'PetarV' Velickovic
 Task: Simboli
*/

#include <stdio.h>
#include <iostream>

#define MAX_N 1000001

using namespace std;

int n, k;
char sym[MAX_N];

int s[2][MAX_N];

int sol = -MAX_N;

int total(int left)
{
    int right = left + k - 1;
    
    int cnt1 = s[0][n - 1] - (s[0][right] - (left > 0 ? s[0][left - 1] : 0)) + (s[1][right] - (left > 0 ? s[1][left - 1] : 0));
    int cnt2 = s[1][n - 1] - (s[1][right] - (left > 0 ? s[1][left - 1] : 0)) + (s[0][right] - (left > 0 ? s[0][left - 1] : 0));
    
    return cnt1 - cnt2;
}

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", sym);
    
   
    for (int ch=0;ch<26;ch++)
    {
        int opp = 25 - ch;
        
        if (sym[0] - 'A' == ch) s[0][0] = 1;
        else s[0][0] = 0;
        
        if (sym[0] - 'A' == opp) s[1][0] = 1;
        else s[1][0] = 0;
        
        for (int i=1;i<n;i++)
        {
            s[0][i] = s[0][i - 1];
            s[1][i] = s[1][i - 1];
            if (sym[i] - 'A' == ch) s[0][i]++;
            if (sym[i] - 'A' == opp) s[1][i]++;
        }
        if (k == 0)
        {
            sol = max(sol, s[0][n - 1] - s[1][n - 1]);
        }
        else
        {
            int curr_sol = MAX_N;
            for (int l=0;l<n-k+1;l++)
            {
                curr_sol = min(curr_sol, total(l));
            }
            sol = max(sol, curr_sol);
        }
    }
    
    printf("%d\n", sol);
    
    return 0;
}
