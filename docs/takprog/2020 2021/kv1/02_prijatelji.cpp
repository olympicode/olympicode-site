//Prijatelji 100
#include <bits/stdc++.h>
#define MAX_N 100005
#define MAX_M 100005

using namespace std;

int N, M;
long long A[MAX_N];
int X[MAX_M], Y[MAX_M];


int main(){
	ios::sync_with_stdio(false);
	cin>>N>>M;
	for(int i=1; i<=N; i++){
		cin>> A[i];
	}
	for(int i=1; i<=M; i++){
		cin>>X[i]>>Y[i];
	}
	long long max_sreca=0;
	for(int i=1; i<=M; i++){
		max_sreca+=abs(A[X[i]]+A[Y[i]]);
	}
	cout<<max_sreca;
	return 0;
}
