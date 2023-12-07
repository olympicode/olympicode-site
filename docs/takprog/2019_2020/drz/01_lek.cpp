#include <bits/stdc++.h>

using namespace std;

int n;
void rev(int l,int r,vector<int> &p){
	for(int j=l;r-j+l>j;j++)
  	swap(p[j],p[r-j+l]);
}
bool ok(vector<int> &p){
	for(int i=0;i<p.size();i++)
		if(p[i]!=i)
			return 0;
	return 1;
}
int main(){
	scanf("%i",&n);
  vector<int> perm(n+2);
  for(int i=1;i<=n;i++)
  	scanf("%i",&perm[i]);
  perm[n+1]=n+1;
  vector<pair<int,int> > sol;
  int lst=-1;
  for(int i=1;i<=n+1;i++){
  	if(perm[i]>perm[i-1]){
  		if(lst!=-1){
  			rev(lst,i-1,perm);
  			sol.push_back({lst,i-1});
  			lst=-1;
  		}
  	}
  	else{
  		if(lst==-1)
  			lst=i-1;
  	}
  }
  if(!ok(perm)){
  	printf("Nema spasa\n");
  	return 0;
  }
  printf("Svet je spasen\n%i\n",sol.size());
  for(auto p:sol)
  	printf("%i %i\n",p.first,p.second);
  return 0;
}
