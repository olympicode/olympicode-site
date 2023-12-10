#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
int nums[7];
int main() {
    for(int i=0;i<7;i++) {
        scanf("%d",&nums[i]);
    }
    sort(nums,nums+7);
    cout<<nums[0]<<" "<<nums[1]<<" "<<nums[6]-nums[0]-nums[1]<<endl;
    return 0;
}
