#include "hoteli.h"
#include <cstdio>
#include <algorithm>
#include <ctime>
#define MOD 1000000007L
using namespace std;

int leftdp[310][310];
int rightdp[310][310];

int diagonalSum[310][310];
int columnSum[310][310];

int getDiagonalSum (int i, int j)
{
    if (i<0 || j<0) return 0;
    return diagonalSum[i][j];
}
int getColumnSum(int i, int j)
{
     if (i<0 || j<0) return 0;
    return columnSum[i][j];
}
int BrojIzgradnji(int n,int x, int p, int* H)
{
    int sol=0;
    p--;
    for (int k=0;x+k<n || x-k>0;k++)
    {
        int r = 2*k+1;

        if (x-k+1>0 && k!=0) H[x-k]=0;
        if (x+k-1<=n && k!=0)H[x+k-2]=0;

        //solve left side
        leftdp[0][0]=diagonalSum[0][0]=columnSum[0][0]=1;
        for (int i=1;i<=x;i++)
        {
            for (int j=0;j<=i;j++)
            {
                if ( i-1-k < 0 || H[i-1-k]==0)leftdp[i][j]=0;
                else
                {
                    leftdp[i][j] = getDiagonalSum(i-1,j-1)-getDiagonalSum(i-r,j-r);
                    leftdp[i][j]=(leftdp[i][j]+MOD)%MOD;
                    leftdp[i][j]+=getColumnSum(i-r,j-r);
                    leftdp[i][j]%=MOD;
                }
                diagonalSum[i][j] = ((i>0 && j>0)?diagonalSum[i-1][j-1]:0) + leftdp[i][j];
                diagonalSum[i][j]%=MOD;
                columnSum[i][j] = columnSum[i-1][j] + leftdp[i][j];
                columnSum[i][j]%=MOD;
            }
        }
        //solve right side
       r-=2;
       rightdp[0][0]=diagonalSum[0][0]=columnSum[0][0]=1;
       if (k!=0)
       for (int i=1;n-i>=x;i++)
       {
            for (int j=0;j<=i;j++)
            {
                if (n-i+k-1>=n || H[n-i+k-1]==0)rightdp[i][j]=0;
                else
                {
                    rightdp[i][j] = getDiagonalSum(i-1,j-1)-getDiagonalSum(i-r,j-r);
                    rightdp[i][j]=(rightdp[i][j]+MOD)%MOD;
                    rightdp[i][j]+=getColumnSum(i-r,j-r);
                    rightdp[i][j]%=MOD;
                }
                diagonalSum[i][j] = ((i>0 && j>0)?diagonalSum[i-1][j-1]:0) + rightdp[i][j];
                diagonalSum[i][j]%=MOD;
                columnSum[i][j] = columnSum[i-1][j] + rightdp[i][j];
                columnSum[i][j]%=MOD;
            }
        }
        //sum the solution
        if (k==0)
        {
            long long solI = leftdp[x][p+1];
            solI%=MOD;
            for (int i=x;i<n;i++)
            {
                if (H[i]==1)
                {
                    solI*=2;
                    solI%=MOD;
                }
            }
            sol+=solI;
            sol%=MOD;
        }
        else
        {
            for (int i=0;i<=p;i++)
            {
                long long leftLastTaken = 0;
                long long leftLastNotTaken = 1;
                if (i!=0)
                {
                    leftLastTaken =i+1<=x?leftdp[x][i+1]:0;
                    leftLastNotTaken = 0;
                    for (int j=1;j<x;j++)
                    {
                        leftLastNotTaken += leftdp[j][i];
                        leftLastNotTaken%=MOD;
                    }
                }
                long long rightLastTaken = 0;
                long long rightLastNotTaken = 1;
                if (i!=p)
                {
                    rightLastTaken = rightdp[n-x][p-i];
                    rightLastNotTaken = 0;
                    for (int j=1;j<n-x;j++)
                    {
                        rightLastNotTaken+=rightdp[j][p-i];
                        rightLastNotTaken%=MOD;
                    }
                }
                long long solForI = (leftLastTaken * rightLastNotTaken )%MOD;
                solForI+=(leftLastTaken*rightLastTaken)%MOD;
                solForI%=MOD;
                solForI+=(leftLastNotTaken*rightLastTaken)%MOD;
                solForI%=MOD;
                sol+=solForI;
                sol%=MOD;
            }
        }
    }
    return sol;
}

