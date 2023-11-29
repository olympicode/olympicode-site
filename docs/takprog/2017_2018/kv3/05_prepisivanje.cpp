#include<bits/stdc++.h>
using namespace std;

#define MAXNODES 12555333
#define MAXN 755333

int n,len;
int p[MAXN],rnd[MAXN],niz[MAXN],tstart[MAXN],tkraj[MAXN];
vector<int> r[MAXN];

int zadnjiput[MAXN];

int num_nodes;
int levi_sin[MAXNODES], desni_sin[MAXNODES], uk_suma[MAXNODES];
int per_time[MAXNODES];

int new_node() {
    num_nodes++;
    levi_sin[num_nodes] = -1;
    desni_sin[num_nodes] = -1;
    uk_suma[num_nodes] = 0;

    return num_nodes;
}

void ubaci(int last_node, int curr_node, int left, int right, int pos, int value) {

    if (last_node != -1) {
        levi_sin[curr_node] = levi_sin[last_node];
        desni_sin[curr_node] = desni_sin[last_node];
    }

    if (left == right) {
        uk_suma[curr_node] = value;
        return;
    }

    int mid = (left+right)/2;
    if (pos <= mid) {
        int nd = new_node();
        ubaci(levi_sin[curr_node], nd, left, mid, pos, value);
        levi_sin[curr_node] = nd;
    } else {
        int nd = new_node();
        ubaci(desni_sin[curr_node], nd, mid+1, right, pos, value);
        desni_sin[curr_node] = nd;
    }

    uk_suma[curr_node] = (levi_sin[curr_node] != -1 ? uk_suma[levi_sin[curr_node]] : 0) +
                         (desni_sin[curr_node] != -1 ? uk_suma[desni_sin[curr_node]] : 0);
}

int query_sum(int curr_node, int left, int right, int sum) {
    if (left == right) return left;

    int mid = (left+right)/2;

    if (levi_sin[curr_node] == -1) return query_sum(desni_sin[curr_node], mid+1, right, sum);
    if (desni_sin[curr_node] == -1) return query_sum(levi_sin[curr_node], left, mid, sum);

    if (uk_suma[levi_sin[curr_node]] >= sum) {
        return query_sum(levi_sin[curr_node], left, mid, sum);
    } else {
        return query_sum(desni_sin[curr_node], mid+1, right, sum - uk_suma[levi_sin[curr_node]]);
    }
}

void init_tree() {

    int nd,tak,last_root;

    for(int i=1; i<=n; i++) {
        zadnjiput[i] = -1;
    }

    last_root = -1;
    for(int i=len; i>=1; i--) {
        tak = niz[i];
        if (zadnjiput[tak] != -1) {
            nd = new_node();
            ubaci(last_root, nd, 1, len, zadnjiput[tak], 0);
            last_root = nd;
        }

        zadnjiput[tak] = i;

        nd = new_node();
        ubaci(last_root, nd, 1, len, i, 1);
        last_root = nd;

        per_time[i] = last_root;
    }
}

int main() {

    //freopen("01.in", "r", stdin);
    //freopen("01.out", "w", stdout);

    int N,R,K,i,j,rj,ti,si,st,zd,tak,last_res;

    scanf("%d%d", &N, &R);

    n = N;

    for(i=1; i<=N; i++) {
        scanf("%d", &p[i]);
        for(j=0; j<p[i]; j++) {
            scanf("%d", &rj);
            r[rj].push_back(i);
        }
    }

    len = 0;

    for(i=1; i<=R; i++) {
        tstart[i] = len+1;
        for(j=0; j<r[i].size(); j++) {
            tak = r[i][j];
            len++;
            rnd[len] = i;
            niz[len] = tak;
        }
        tkraj[i] = len;
    }

    init_tree();

    scanf("%d", &K);

    last_res = 0;
    for(i=0; i<K; i++) {
        scanf("%d%d", &ti, &si);

        st = ti+last_res;

        zd = query_sum(per_time[tstart[st]], 1, len, si);

        last_res = rnd[zd]-st+1;
        printf("%d\n", last_res);
    }

    return 0;
}

