#include <bits/stdc++.h>
#define maxN 200005

using namespace std;

struct Task{

Task(int a,int b, int i){
    start = a;
    end = b;
    id = i;
};

int start, end, id, ans;
};

bool cmp_start(Task a,Task b){
    return a.start < b.start;
}

bool cmp_id(Task a,Task b){
    return a.id < b.id;
}

vector <Task> tasks;

int main(){
    int n;
    cin >> n;
    assert(n<=2e5);
    
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        assert(a<=1e9);
        assert(b<=1e9);
        tasks.push_back({a,b,i});
    }
    
    sort(tasks.begin(),tasks.end(),cmp_start);
    
    int m=-1;
    for(int i=0;i<n;i++){
        m=max(m,tasks[i].end);
        tasks[i].ans = m;
    }
    
    sort(tasks.begin(),tasks.end(),cmp_id);
    
    for(int i=0;i<n;i++){
        cout<<tasks[i].ans<<endl;
    }
    return 0;
}