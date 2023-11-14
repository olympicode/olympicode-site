#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <ctime>
#include <assert.h>
using namespace std;

#define PI 3.141592653589793
#define INF 2123456789
#define NUL 0.0000001

#define for_each(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define SZ size()
#define CS c_str()
#define PB push_back
#define MP make_pair
#define INS insert
#define EMP empty()
#define CLR clear()
#define LEN length()
#define MS(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))

typedef long long LL;
typedef unsigned long long ULL;

const int MaxN = 530005;

int n;

struct segmentTree{
    LL data[MaxN], lazy[MaxN];
    int left[MaxN], right[MaxN];

    void init(int node = 1, int l = 1, int r = n){
        if (l > r) return;
        if (l == r){
            data[node] = lazy[node] = 0;
            left[node] = 2 * node;
            right[node] = 2 * node + 1;
            return;
        }

        init(2 * node, l, (l + r) / 2);
        init(2 * node + 1, (l + r) / 2 + 1, r);

        data[node] = lazy[node] = 0;
        left[node] = 2 * node;
        right[node] = 2 * node + 1;
    }

    void update(int i, int j, LL val, int node = 1, int l = 1, int r = n){
        lazy_update(node, l, r);

        if (r < i || j < l) return;
        if (i <= l && r <= j){
            lazy[node] += val;
            lazy_update(node, l, r);
            return;
        }

        update(i, j, val, left[node], l, (l + r) / 2);
        update(i, j, val, right[node], (l + r) / 2 + 1, r);

        node_update(node);
    }

    void node_update(int node){
        data[node] = data[ left[node] ] + data[ right[node] ];
    }

    void lazy_update(int node, int l, int r){

        if (lazy[node] != 0){
            data[node] += lazy[node] * (r - l + 1);

            lazy[ left[node] ] += lazy[node];
            lazy[ right[node] ] += lazy[node];

            lazy[node] = 0;
        }
    }

    LL get(int i, int j, int node = 1, int l = 1, int r = n){
        lazy_update(node, l, r);

        if (r < i || j < l) return 0;
        if (i <= l && r <= j) return data[node];

        LL A = get(i, j, left[node], l, (l + r) / 2);
        LL B = get(i, j, right[node], (l + r) / 2 + 1, r);

        return A + B;
    }

    void swap_nodes(vector <int> &nodes, vector <int> &ancs, int i, int j, int node = 1, int anc = 0, int l = 1, int r = n){
        lazy_update(node, l, r);

        if (r < i || j < l) return;
        if (i <= l && r <= j){
            nodes.push_back(node);
            ancs.push_back(anc);
            return;
        }

        swap_nodes(nodes, ancs, i, j, left[node], node, l, (l + r) / 2);
        swap_nodes(nodes, ancs, i, j, right[node], node, (l + r) / 2 + 1, r);
    }

} sTree;

void Init(int _n, int subtask){
    n = _n;
    sTree.init();
}

void Ubaci(int pos, int k, int v){
    sTree.update(pos, pos + (1 << k) - 1, 1 << v);
}

void Izmesaj(int pos, int k){
    //printf("\n\n");
    //sTree.swap_nodes(pos, pos + (1 << (k - 1)) - 1);
    //printf("%d %d %d %d\n", pos, pos + (1 << (k - 1)) - 1, pos + (1 << (k - 1)), pos + (1 << k) - 1);
    //return;
    //printf("pos = %d k = %d\n", pos, k);

    vector <int> nodes_left, nodes_right, ancs_left, ancs_right;
    nodes_left.clear(); nodes_right.clear();
    ancs_left.clear(); ancs_right.clear();

    sTree.swap_nodes(nodes_left, ancs_left, pos, pos + (1 << (k - 1)) - 1);
    sTree.swap_nodes(nodes_right, ancs_right, pos + (1 << (k - 1)), pos + (1 << k) - 1);

    for (int i = 0, sz = nodes_left.size(); i < sz; i++){
        int node = nodes_left[i], node2 = nodes_right[i];
        int anc = ancs_left[i], anc2 = ancs_right[i];

        //printf("node = %d node2 = %d anc = %d anc2 = %d\n", node, node2, anc, anc2);
        //printf("pre: anc [%d, %d]   anc2 [%d, %d]\n", sTree.left[anc], sTree.right[anc], sTree.left[anc2], sTree.right[anc2]);

        swap(sTree.left[anc] == node ? sTree.left[anc] : sTree.right[anc], sTree.left[anc2] == node2 ? sTree.left[anc2] : sTree.right[anc2]);

        //printf("pos: anc [%d, %d]   anc2 [%d, %d]\n", sTree.left[anc], sTree.right[anc], sTree.left[anc2], sTree.right[anc2]);
    }

    for (int i = 0, sz = nodes_left.size(); i < sz; i++){
        int node = ancs_left[i], node2 = ancs_right[i];

        while (node > 0){
            sTree.node_update(node);
            node /= 2;
        }

        while (node2 > 0){
            sTree.node_update(node2);
            node2 /= 2;
        }
    }
}

LL Prebroji(int pos, int k){
    return sTree.get(pos, pos + (1 << k) - 1);
}
