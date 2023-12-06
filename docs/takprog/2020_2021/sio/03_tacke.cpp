#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair

struct pt{
	ll x,y;
	pt(){}
	pt(ll a,ll b):x(a),y(b){}
};

pt operator - (pt a,pt b){return pt(a.x-b.x,a.y-b.y);}
ll cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
int part(pt a){return (a.y>0||(a.y==0&&a.x>0))?0:1;}
bool operator < (pt a,pt b){
	return mp(part(a),(ll)0)<mp(part(b),cross(a,b));
}
bool operator == (pt a,pt b){return mp(a.x,a.y)==mp(b.x,b.y);}

map<pt,int> pts;
int cntZero=0,badAngles=0;

bool bad(pt a,pt b){
	ll c=cross(a,b);
	if(c<0)return true;
	//if(c==0&&part(a)==part(b)){
	//	if(b<a)return true;
	//}
	return false;
}

void Add(pt a,pt b){
	//printf("Add (%lld %lld) (%lld %lld)\n",a.x,a.y,b.x,b.y);
	if(bad(a,b))badAngles++;
}

void Del(pt a,pt b){
	//printf("Del (%lld %lld) (%lld %lld)\n",a.x,a.y,b.x,b.y);
	if(bad(a,b))badAngles--;
}

void Add(pair<pt,int> a,pair<pt,int> b){
	Add(a.first,b.first);
}

void Del(pair<pt,int> a,pair<pt,int> b){
	Del(a.first,b.first);
}

map<pt,int>::iterator getPrev(map<pt,int>::iterator it){
	if(it==pts.begin())return prev(pts.end());
	else return prev(it);
}

map<pt,int>::iterator getNext(map<pt,int>::iterator it){
	if(next(it)==pts.end())return pts.begin();
	else return next(it);
}

void AddPoint(pt a){
	//printf("AddPt (%lld %lld)\n",a.x,a.y);
	if(a==pt(0,0)){
		cntZero++;
		return;
	}
	pts[a]++;
	auto it=pts.find(a);
	if(pts[a]==1){
		if(pts.size()>2)Del(*getPrev(it),*getNext(it));
		if(pts.size()>1)Add(*getPrev(it),*it);
		if(pts.size()>1)Add(*it,*getNext(it));
	}
}

void DelPoint(pt a){
	//printf("DelPt (%lld %lld)\n",a.x,a.y);
	if(a==pt(0,0)){
		cntZero--;
		return;
	}
	pts[a]--;
	auto it=pts.find(a);
	if(pts[a]==0){
		if(pts.size()>1)Del(*getPrev(it),*it);
		if(pts.size()>1)Del(*it,*getNext(it));
		if(pts.size()>2)Add(*getPrev(it),*getNext(it));
		pts.erase(it);
	}
}

bool IsOk(){
	return cntZero==0&&(pts.size()<=1||badAngles>0);
}

void Resi(int N, int Px, int Py, int *X, int *Y, int Q, int *L, int *R, bool *O){
	assert(1<=N && N<=300000);
	assert(1<=Q && Q<=300000);
	assert(-1000000000<=Px && Px<=1000000000);
	assert(-1000000000<=Py && Py<=1000000000);
	for(int i=1;i<=N;i++){
		assert(-1000000000<=X[i] && X[i]<=1000000000);
		assert(-1000000000<=Y[i] && Y[i]<=1000000000);
	}
	for(int i=1;i<=Q;i++){
		assert(1<=L[i] && L[i]<=R[i] && R[i]<=N);
	}
	pt P(Px,Py);
	vector<int> ptr(N+1,0);
	for(int i=1;i<=N;i++){
		int j=ptr[i-1];
		while(j<=N&&IsOk()){
			j++;
			if(j<=N)AddPoint(pt(X[j],Y[j])-P);
		}
		ptr[i]=j;
		//printf("%i %i badAngles:%i cntZero:%i : ",i,j,badAngles,cntZero);
		//for(auto p:pts)printf("(%lld %lld) ",p.x,p.y);printf("\n");
		DelPoint(pt(X[i],Y[i])-P);
	}
	for(int i=1;i<=Q;i++){
		//printf("%i: %i %i\n",i,ptr[L[i]],R[i]);
		if(ptr[L[i]]<=R[i])O[i]=true;
		else O[i]=false;
	}
}
