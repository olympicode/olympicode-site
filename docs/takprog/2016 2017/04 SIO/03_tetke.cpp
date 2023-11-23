#include <bits/stdc++.h>
#define MAXN 100005
#define MAXH 100000005
#define INF 2110000000
#define mid (l+r)/2
using namespace std;

struct house
{
    int r, c;
    int h;
    int newc;
    int idx;
};

int N, A, B;
house a[MAXN];

// indeks onog koji kvari parnost, N+1 ako su svi ok
int ParityCheck() 
{
    int val = (a[1].h + a[1].r + a[1].c) % 2;
    for(int i = 1; i <= N; i++)
    {
        if((a[i].h + a[i].r + a[i].c) % 2 != val)
        {
            return i;
        }
    }
    return N+1;
}

bool ManhattanCheck(const house &a, const house &b) 
{
    int dist = abs(a.r - b.r) + abs(a.c - b.c);
    return dist >= abs(a.h - b.h);
}


struct VS
{
    int v1, v2, v3, v4;
};
// Node template
struct node
{
    bool NULLNODE;
    VS minv;
    VS maxv;
    node(){ NULLNODE = false; }
    node(bool nullNode) {NULLNODE = nullNode;}
    void print()
    {
        cout<<"MIN: ["<<minv.v1<<", "<<minv.v2<<", "<<minv.v3<<", "<<minv.v4<<"]"<<endl;
        cout<<"MAX: ["<<maxv.v1<<", "<<maxv.v2<<", "<<maxv.v3<<", "<<maxv.v4<<"]"<<endl;
    }
};

struct seg3
{

    // Merging function
    node segMerge(node a, node b)
    {
        // RMinQ
        if(a.NULLNODE) return b;
        if(b.NULLNODE) return a;
        node ret;
        ret.minv.v1 = min(a.minv.v1, b.minv.v1);
        ret.minv.v2 = min(a.minv.v2, b.minv.v2);
        ret.minv.v3 = min(a.minv.v3, b.minv.v3);
        ret.minv.v4 = min(a.minv.v4, b.minv.v4);
        ret.maxv.v1 = max(a.maxv.v1, b.maxv.v1);
        ret.maxv.v2 = max(a.maxv.v2, b.maxv.v2);
        ret.maxv.v3 = max(a.maxv.v3, b.maxv.v3);
        ret.maxv.v4 = max(a.maxv.v4, b.maxv.v4);
        return ret;
    }

    // Original array, segment tree
    node seg[MAXN*4];

    // Build
    void init(int idx, int l, int r)
    {
        if(l == r)
        {
            // Leaf node
            seg[idx].minv.v1 = seg[idx].minv.v2 = 
            seg[idx].minv.v3 = seg[idx].minv.v4 = INF;
            seg[idx].maxv.v1 = seg[idx].maxv.v2 = 
            seg[idx].maxv.v3 = seg[idx].maxv.v4 = -INF;
            return;
        }
        init(2*idx, l, mid);
        init(2*idx+1, mid+1, r);
        seg[idx] = segMerge(seg[2*idx], seg[2*idx+1]);
    }

    // a[qi] = v
    void update(int qi, node v, int idx, int l, int r)
    {
        if(l == r)
        {
            // Leaf node
            seg[idx] = v;
            return;
        }
        if(qi <= mid) update(qi, v, 2*idx, l, mid);
        else update(qi, v, 2*idx+1, mid+1, r);
        seg[idx] = segMerge(seg[2*idx], seg[2*idx+1]);
    }

    // max & min[lq..rq]?
    node query(int lq, int rq, int idx, int l, int r)
    {
        if(lq <= l && rq >= r)
        {
            // Canonic cover
            return seg[idx];
        }
        node ret(true);
        if(lq <= mid) ret = segMerge(ret, query(lq, rq, 2*idx, l, mid));
        if(rq > mid) ret = segMerge(ret, query(lq, rq, 2*idx+1, mid+1, r));
        return ret;
    }
};

const bool operator<(const house& a, const house& b) 
{
    if(a.r == b.r)
    {
        return a.c < b.c;
    }
    return a.r < b.r;
}

bool cmpc(house a, house b)
{
    if(a.c == b.c)
    {
        return a.r < b.r;
    }
    return a.c < b.c;
}

seg3 seg;

int scaling_cols = 0;

bool IsValid(int k)
{
    // take first k
    vector<house> houses(a+1, a+k+1);
    sort(houses.begin(), houses.end());
    seg.init(1, 1, scaling_cols);
    for(house& H : houses) 
    {
        // build me
        node me;
        me.minv.v1 = H.h - H.r - H.c;
        me.minv.v2 = H.h - H.r + H.c;
        me.minv.v3 = H.h + H.r - H.c;
        me.minv.v4 = H.h + H.r + H.c;
        me.maxv = me.minv;
        // do queries
        node lres = seg.query(1, H.newc, 1, 1, scaling_cols);
        node rres = seg.query(H.newc, scaling_cols, 1, 1, scaling_cols);
        // query, use minv for me always
        // DIRECT LEFT V1
        // DIRECT RIGHT V2
        if(me.minv.v1 > lres.minv.v1 || me.minv.v2 > rres.minv.v2)
        {
            return false;
        }
        // INDIRECT LEFT V3
        // INDIRECT RIGHT V4
        if(lres.maxv.v4 > me.minv.v4 || rres.maxv.v3 > me.minv.v3)
        {
            return false;
        }
        // update
        seg.update(H.newc, me, 1, 1, scaling_cols);
    }
    return true;
}

bool cmpidx(house a, house b)
{
    return a.idx < b.idx;
}

int main() 
{
    scanf("%d %d %d", &N, &A, &B);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d %d", &a[i].r, &a[i].c, &a[i].h);
        a[i].idx = i;
    }
    sort(a+1, a+N+1, cmpc);
    a[1].newc = 1;
    for(int i = 2; i <= N; i++)
    {
        if(a[i].c == a[i-1].c)
        {
            a[i].newc = a[i-1].newc;
        } else {
            a[i].newc = a[i-1].newc + 1; 
        }
    }
    scaling_cols = a[N].newc;
    sort(a+1, a+N+1, cmpidx);

    // Scale
    // Dp
    int pidx = ParityCheck();
    int midx = N+1;
    int hi = N, lo = 2, pivot;
    while(hi > lo)
    {
        pivot = (hi + lo) / 2;
        bool valid = IsValid(pivot);
        if(valid)
        {
            lo = pivot + 1;
        }
        else
        {
            hi = pivot;
        }
    }
    if(!IsValid(hi))
    {
        midx = hi;
    }
    int sol = min(pidx, midx);
    if(sol == N+1)
    {
        printf("bravo komisijo\n");
    }
    else
    {
        printf("%d\n", sol);
    }
    return 0;
}
