#include "krug.h"
#include <algorithm>
using namespace std;

int d0[100005], dx[100005], p[200005];

void Resi(int N, int* L, int* H){
	for (int i=1; i<N; i++) d0[i] = Rastojanje(0, i);
	int m=1;
	for (int i=1; i<N; i++) if (d0[i] < d0[m]) m = i;
	for (int i=1; i<N; i++) if (i!=m) dx[i] = Rastojanje(m, i);
	p[0] = 0;
	p[m] = d0[m];
	int lm = 0, rm = m;
	for (int i=1; i<N; i++) if (i!=m){
		if (d0[i] < dx[i]){
			p[i] = -d0[i];
			if (p[i] < p[lm]) lm = i;
		} else {
			p[i] = dx[i] + d0[m];
			if (p[i] > p[rm]) rm = i;
		}
	}
	
	int obim = p[rm] - p[lm] + Rastojanje(lm, rm);
	sort(p, p+N);
	for (int i=0; i<N; i++) p[i+N] = p[i] + obim;
	*L = obim;
	*H = 0;
	for (int i=0; i<N; i++) if (p[i+1] - p[i] < *L) *L = p[i+1] - p[i];
	int j = 0;
	for (int i=0; i<N; i++){
		while (p[j+1] - p[i] <= obim/2) j++;
		if (p[j] - p[i] > *H) *H = p[j] - p[i];
	}
}
