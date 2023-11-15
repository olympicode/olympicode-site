#include <bits/stdc++.h>

using namespace std;

long long a, b;
string A, B, res="";

int main() {
	cin >> a>>b;

	if(b>a) swap(a,b);

	A = to_string(a);
	B = to_string(b);

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	for(int i=0;i<A.size();i++){
        if(i>=B.size()){
            res+=A[i];
            continue;
        }
		if(A[i]>=B[i]) res+=A[i];
		if(A[i]<=B[i]) res+=B[i];
	}

	reverse(res.begin(),res.end());

	cout<<res<<endl;
	return 0;
}
