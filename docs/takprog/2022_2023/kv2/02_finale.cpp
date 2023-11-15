#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    if(n == 1){
        cout<<m;
    }
    else if(m == 1){
        cout<<n;
    }
    else
    {
        cout<<2ll*n + 2ll*m - 4 + 1ll*(n-2)*(m-2)/2;
    }
}
