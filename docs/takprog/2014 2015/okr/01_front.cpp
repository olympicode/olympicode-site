/* 
 Author: Petar 'PetarV' Velickovic
 Task: Front
*/

#include <stdio.h>
#include <algorithm>

#define MAX_N 1000001

using namespace std;

int n;
int X[MAX_N], Y[MAX_N];
int currX, currmY, maxY;
int sol;

int main()
{
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d%d", &X[i], &Y[i]);
    
    currX = X[n - 1], currmY = Y[n - 1], maxY = -1;
    for (int i=n-1;i>=0;i--)
    {
        if (X[i] == currX) currmY = max(currmY, Y[i]);
        else
        {
            if (currmY > maxY) maxY = currmY, sol++;
            currmY = Y[i];
            currX = X[i];
        }
    }
    if (currmY > maxY) sol++;
    
    printf("%d\n", sol);
    return 0;
}
