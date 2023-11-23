# include <stdio.h>
# include <stdlib.h>
#include<math.h> 
//#include<algorithm>
#include<string.h>

# define MAXN 100100
# define MAXN2 ((1<<18)+1)
#define INF 0x1FFFFFFFFFFFFFLL
//#define INF 10000000000LL

using namespace std;

int n;

int ord[MAXN];
int ht[MAXN], ct[MAXN], lc[MAXN], rc[MAXN];

long long ls[MAXN], rs[MAXN];

long long ctc[MAXN];
long long smc[MAXN];


long long tree_sum[MAXN2];
long long lazy_sum[MAXN2];
long long tree_max[MAXN2];
long long lazy_max[MAXN2];

long long sum(long long a, long long b) {
	return a + b;
}

long long max(long long a, long long b) {
	if (a > b) return a; else return b;
}


void build_tree_sum(int node, int a, int b, long long arr[]) {
  	if(a > b) return; 						
  	
  	if(a == b) { 							
    	tree_sum[node] = arr[a]; 		
		return;
	}
	
	build_tree_sum(node*2, a, (a+b)/2, arr); 	
	build_tree_sum(node*2+1, 1+(a+b)/2, b, arr); 
	
	tree_sum[node] = sum(tree_sum[node*2], tree_sum[node*2+1]); 
}

void update_tree_sum(int node, int a, int b, int i, int j, long long value) {
  
  	if(lazy_sum[node] != 0) { 							
   		tree_sum[node] += (b - a + 1) * lazy_sum[node]; 

		if(a != b) {
			lazy_sum[node*2] += lazy_sum[node]; 		
    		lazy_sum[node*2+1] += lazy_sum[node]; 		
		}

   		lazy_sum[node] = 0; 							
  	}
  
	if(a > b || a > j || b < i) 						
		return;
    
  	if(a >= i && b <= j) { 								
    		tree_sum[node] += (b - a + 1) * value;

		if(a != b) { 									
			lazy_sum[node*2] += value;					 
			lazy_sum[node*2+1] += value;				
		}

    	return;
	}

	update_tree_sum(node*2, a, (a+b)/2, i, j, value); 		
	update_tree_sum(1+node*2, 1+(a+b)/2, b, i, j, value); 	

	tree_sum[node] = sum(tree_sum[node*2], tree_sum[node*2+1]); 
}

long long query_tree_sum(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; 					

	if(lazy_sum[node] != 0) { 								
		tree_sum[node] += (b - a + 1) * lazy_sum[node]; 	

		if(a != b) {
			lazy_sum[node*2] += lazy_sum[node]; 			
			lazy_sum[node*2+1] += lazy_sum[node]; 			
		}

		lazy_sum[node] = 0; 								
	}

	if(a >= i && b <= j) 
		return tree_sum[node];

	long long q1 = query_tree_sum(node*2, a, (a+b)/2, i, j); 		
	long long q2 = query_tree_sum(1+node*2, 1+(a+b)/2, b, i, j);	

	long long res = sum(q1, q2); 									
	
	return res;
}

void build_tree_max(int node, int a, int b, long long arr[]) {
  	if(a > b) return; 					
  	
  	if(a == b) { 						
    	tree_max[node] = arr[a]; 
		return;
	}
	
	build_tree_max(node*2, a, (a+b)/2, arr); 		
	build_tree_max(node*2+1, 1+(a+b)/2, b, arr); 	
	
	tree_max[node] = max(tree_max[node*2], tree_max[node*2+1]); 
}

void update_tree_max(int node, int a, int b, int i, int j, long long value) {
  
  	if(lazy_max[node] != 0) { 					
   		tree_max[node] += lazy_max[node]; 		

		if(a != b) {
			lazy_max[node*2] += lazy_max[node]; 		
    			lazy_max[node*2+1] += lazy_max[node]; 	
		}

   		lazy_max[node] = 0; 					
  	}
  
	if(a > b || a > j || b < i) 				
		return;
    
  	if(a >= i && b <= j) { 						
    	tree_max[node] += value;

		if(a != b) { 							
			lazy_max[node*2] += value;			
			lazy_max[node*2+1] += value;
		}

    	return;
	}

	update_tree_max(node*2, a, (a+b)/2, i, j, value); 			
	update_tree_max(1+node*2, 1+(a+b)/2, b, i, j, value); 		

	tree_max[node] = max(tree_max[node*2], tree_max[node*2+1]); 
}

long long query_tree_max(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -2*INF; 		

	if(lazy_max[node] != 0) { 						
		tree_max[node] += lazy_max[node]; 			

		if(a != b) {
			lazy_max[node*2] += lazy_max[node]; 	
			lazy_max[node*2+1] += lazy_max[node]; 	
		}

		lazy_max[node] = 0; 						
	}

	if(a >= i && b <= j) 							
		return tree_max[node];

	long long q1 = query_tree_max(node*2, a, (a+b)/2, i, j); 		
	long long q2 = query_tree_max(1+node*2, 1+(a+b)/2, b, i, j); 	

	long long res = max(q1, q2); 									
	
	return res;
}




void read() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &ht[i], &ct[i], &lc[i], &rc[i]);
	}
}

int cmpht(const void *p1, const void *p2) {
	const int *pi1 = (const int *)p1;
	const int *pi2 = (const int *)p2;
	return ht[*pi1] - ht[*pi2];
}

long long solve() {
	int i, j;
	for (i = 0; i < n; i++) 
		ord[i] = i+1;
	qsort(ord, n, sizeof(int), cmpht);
	ls[n] = smc[n] = -INF;
	ctc[n] = ct[n];
	for (i = n-1; i >= 1; i--) {
		smc[i] = smc[i+1] - ct[i+1];
		ctc[i] = ct[i];
		ls[i] = -INF;
	} 
	smc[0] = smc[1] - ct[1] + INF;
	ctc[0] = 0;
	build_tree_sum(1, 0, n, ctc);
	build_tree_max(1, 0, n, smc);
	memset(lazy_max, 0, sizeof lazy_max);
	memset(lazy_sum, 0, sizeof lazy_sum);
	for (i = 0; i < n; i++) {
		j = ord[i];
		ls[j] = lc[j];
		if (j > 0) 
			ls[j] += query_tree_max(1, 0, n, 0, j-1);
		ls[j] += query_tree_sum(1, 0, n, j, n);
		update_tree_max(1, 0, n, j, j, INF+ls[j]);
		smc[j] += INF + ls[j];
		if (j > 0) {
			update_tree_max(1, 0, n, 0, j-1, ct[j]);
		}
		update_tree_sum(1, 0, n, j, j, -ct[j]);
	}

	rs[1] = smc[1] = -INF;
	ctc[1] = ct[1];
	for (i = 2; i <= n; i++) {
		smc[i] = smc[i-1] - ct[i-1];
		ctc[i] = ct[i];
		rs[i] = -INF;
	} 
	smc[n+1] = smc[n] - ct[n] + INF;
	ctc[n+1] = 0;
	build_tree_sum(1, 1, n+1, ctc);
	build_tree_max(1, 1, n+1, smc);
	memset(lazy_max, 0, sizeof lazy_max);
	memset(lazy_sum, 0, sizeof lazy_sum);
	for (i = 0; i < n; i++) {
		j = ord[i];
		rs[j] = rc[j];
		rs[j] += query_tree_max(1, 1, n+1, j+1, n+1);
		rs[j] += query_tree_sum(1, 1, n+1, 1, j);
		update_tree_max(1, 1, n+1, j, j, INF+rs[j]);
		update_tree_max(1, 1, n+1, j+1, n+1, ct[j]);
		update_tree_sum(1, 1, n+1, j, j, -ct[j]);
	}

	long long rez;
	rez = ls[1] + rs[1];
	for (i = 2; i <= n; i++) 
		if (ls[i] + rs[i] > rez)
			rez = ls[i] + rs[i];
	printf("%lld\n", rez);
	return rez;
}

main() {
	read();
	solve();
	return 0;
}
