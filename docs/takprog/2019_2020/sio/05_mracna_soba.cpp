#include <bits/stdc++.h>
#define MAXN 507
using namespace std;
int v[MAXN][MAXN],h[MAXN][MAXN],nz[MAXN];
vector<int> w[2][MAXN];
long long cl[MAXN];
long long Prebroj(int N, int M, int** A)
{
	long long sol=0;
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) h[i][j]=h[i][j-1]^A[i][j];
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) v[i][j]=v[i-1][j]^A[i][j];
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<M;j++) w[0][j].clear();
		for(int j=0;j<M;j++) w[1][j].clear();
		for(int j=0;j<=M;j++) w[0][0].push_back(j);
		int t=0,cc=1,cp;
		for(int k=i-1;k>=0;k--)
		{
			cp=cc; cc=0;
			for(int j=0;j<cp;j++)
			{
				if(w[t][j].size()==1) {w[t][j].clear(); continue;}
				bool z[2]={false,false};
				for(int x=0;x<w[t][j].size();x++) z[h[k+1][w[t][j][x]]]=true;
				for(int y=0;y<2;y++) if(z[y]) 
				{
					for(int x=0;x<w[t][j].size();x++) if(h[k+1][w[t][j][x]]==y) w[t^1][cc].push_back(w[t][j][x]);	
					cc++;
				}
				w[t][j].clear();
			} 
			t^=1;
			int p=-1;
			nz[0]=-1;
			for(int j=1;j<=M;j++)
			{
				if(v[i][j]!=v[k][j]) p=-1;
				else if(p==-1) p=j;
				nz[j]=p;
			}
			for(int j=1;j<=M;j++) cl[j]=0;
			for(int j=0;j<cc;j++) 
			{
				for(int x=0;x<w[t][j].size();x++) 
				{
					if(nz[w[t][j][x]]!=-1) sol+=cl[nz[w[t][j][x]]];
					if(nz[w[t][j][x]+1]!=-1) cl[nz[w[t][j][x]+1]]++;
				}
				for(int x=0;x<w[t][j].size();x++) if(nz[w[t][j][x]+1]!=-1) cl[nz[w[t][j][x]+1]]--;
			}
		}
	}
	return sol;
}
