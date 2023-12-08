//SIO 2022 - Zadatak 4 - Dugmici 

#include <bits/stdc++.h>
#define INF INT_MAX
#define MAX_N 200005

using namespace std;

int A[4*MAX_N], B[4*MAX_N];
int N, Q;
int *X, *Y, *Z, *T;

void segtree(int* tree, int v, int l, int r, int sign){
	if(l+1 == r){
		tree[v]=T[l]+2*sign*l;
		return;
	}
	int m=(l+r)/2;
	segtree(tree, 2*v+1, l, m, sign);
	segtree(tree, 2*v+2, m, r, sign);
	tree[v]=tree[2*v+1]<tree[2*v+2]?tree[2*v+1]:tree[2*v+2];
}

int query(int* tree, int v, int tl, int tr, int l, int r){
	if(l >= tr || r <= tl){
		return INF;
	}
	if(tl >= l && tr <= r){
		return tree[v];
	}
	int tm=(tl+tr)/2;
	int val1=query(tree, 2*v+1, tl, tm, l, r);
	int val2=query(tree, 2*v+2, tm, tr, l, r);
	return val1<val2?val1:val2;
}

void update(int* tree, int v, int l, int r, int i, int val, int sign) {
    if (l+1 == r) {
        tree[v] = val+2*sign*l;
        return;
    } 
	int m = (l+r)/2;
    if (i < m)
        update(tree, v*2+1, l, m, i, val, sign);
	else
        update(tree, v*2+2, m, r, i, val, sign);  
    tree[v]=tree[2*v+1]<tree[2*v+2]?tree[2*v+1]:tree[2*v+2];
}

void Trening(int n, int* t, int q, int* x, int* y, int* z, int* Ans){
	
	X=x+1, Y=y+1, Z=z+1, T=t+1;
	N=n, Q=q;
	
	segtree(A, 0, 0, N, -1);
	segtree(B, 0, 0, N, 1);
	
	for(int i=0; i<Q; ++i){
		if(X[i]==1){
			update(A, 0, 0, N, Y[i]-1, Z[i], -1);
			update(B, 0, 0, N, Y[i]-1, Z[i], +1);
		}
		
		if(X[i]==2){
			int L=Y[i]-1;
			int R=Z[i]-1;
			int Aquery=query(A, 0, 0, N, L, R+1);
			int Bquery=query(B, 0, 0, N, L, R+1);
			if(Aquery>=-2*L && Bquery>=2*R)
				Ans[i+1]=1;
			else 
				Ans[i+1]=0;
		}
	}
}

