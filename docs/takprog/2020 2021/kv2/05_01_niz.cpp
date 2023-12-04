#include <bits/stdc++.h>
using namespace std;

const int N=200050;
const int M=2*N;
const int inf=1e9+7;

int ls[M],rs[M],tsz,root;
int dp[M][2][2][2],lzy[M];

char s[N];
int C;
void init(int c){for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)dp[c][i][j][k]=inf;}
void pull(int c){
	for(int t=0;t<2;t++){
		for(int l=0;l<2;l++){
			for(int r=0;r<2;r++){
				dp[c][t][l][r]=inf;
				for(int a=0;a<2;a++){
					for(int b=0;b<2;b++){
						dp[c][t][l][r]=min(dp[c][t][l][r],dp[ls[c]][t][l][a]+dp[rs[c]][t][b][r]+(a==1&&b==1?-C:0));
					}
				}
			}
		}
	}
}

void Flip(int c){
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)swap(dp[c][0][i][j],dp[c][1][i][j]);
	lzy[c]^=1;
}

void push(int c){
	if(lzy[c]){
		Flip(ls[c]);
		Flip(rs[c]);
		lzy[c]=0;
	}
}

void Build(int&c,int ss,int se){
	c=++tsz;init(c);
	if(ss==se){
		if(s[ss]=='1'){
			dp[c][0][0][0]=1;
			dp[c][0][1][1]=C;
			dp[c][1][0][0]=0;
			dp[c][1][1][1]=C+1;
		}else{
			dp[c][0][0][0]=0;
			dp[c][0][1][1]=C+1;
			dp[c][1][0][0]=1;
			dp[c][1][1][1]=C;
		}
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	pull(c);
}

void Flip(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){Flip(c);return;}
	int mid=ss+se>>1;
	push(c);
	Flip(ls[c],ss,mid,qs,qe);
	Flip(rs[c],mid+1,se,qs,qe);
	pull(c);
}

int Ans(){return min({dp[root][0][0][0],dp[root][0][0][1],dp[root][0][1][0],dp[root][0][1][1]});}

int main(){
	int n,q;
	scanf("%i %i %i",&n,&C,&q);
	assert(1<=n && n<=200000);
	assert(1<=C && C<=200000);
	assert(1<=q && q<=200000);

	scanf("%s",s+1);
	assert(strlen(s+1)==n);
	for(int i=1;i<=n;i++)assert(s[i]=='0' || s[i]=='1');

	Build(root,1,n);

	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%i %i",&l,&r);
		assert(1<=l && l<=r && r<=n);
		Flip(root,1,n,l,r);
		printf("%i\n",Ans());
	}
	return 0;
}
