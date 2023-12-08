#include <bits/stdc++.h>
#define MAX_N 3005

using namespace std;

struct tacka{
	int x, y;
};

bool comp(tacka p1, tacka p2){
	return p1.x<p2.x or (p1.x==p2.x and p1.y<p2.y);
}

int N, x[MAX_N], y[MAX_N];//Podaci sa ulaza

vector<tacka> p;//Vektor u kome ce biti smestene preslikane tacke

int main(){
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=0; i<N; ++i){
		cin>>x[i]>>y[i];
	}
	//Racunanje slika tacaka pri preslikavanju preko druge tacke
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(i==j)
				continue;
			tacka P;
			P.x=2*x[i]-x[j];
			P.y=2*y[i]-y[j];
			p.push_back(P);
		}
	}
	
	sort(p.begin(), p.end(), comp);
	
	long long total=0;//Ukupan broj sumnjivih cetvorki
	long long d=0;//Trenutna duzina niza istih elemenata u vektoru p
	
	int l=p.size();
	
	for(int i=0; i<l; ++i){
		d+=1;
		if(i==l-1 or p[i].x!=p[i+1].x or p[i].y!=p[i+1].y){
			total+=d*(d-1)/2;
			d=0;
		}
	}
	
	cout<<total;
	
	return 0;
}
