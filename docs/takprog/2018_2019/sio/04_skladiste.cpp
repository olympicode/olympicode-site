#include <iostream>
#include <algorithm>
#include <vector>

struct event
{
    int t, box;
    bool delivery;
} ;

bool operator<(event a, event b)
{
    return a.t < b.t;
}

struct segtree
{
    static const int N = 1 << 18;
    int tree[2 * N];

    void set(int pos, int val)
    {
        tree[pos += N] = val;
        for(pos /= 2; pos; pos /= 2)
            tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
    }

    int query(int left, int right)
    {
        if(left == right) return tree[left + N];
        int res = tree[left += N] + tree[right += N];
        while(left / 2 != right / 2)
        {
            if(left % 2 == 0) res += tree[left + 1];
            if(right % 2 == 1) res += tree[right - 1];
            left /= 2; right /= 2;
        }
        return res;
    }
} ;

segtree active;

long long Resi(int N, int *A, int *B)
{
    std::vector<event> events;
    for(int i = 0; i < N; i++)
    {
        events.push_back({A[i], i, true});
        events.push_back({B[i], i, false});
    }
    std::sort(events.begin(), events.end());
    
    long long res = 0;
    for(event e : events)
    {
        if(e.delivery)
        {
            int pre = active.query(B[e.box] + 1, 2 * N);
            int post = active.query(0, B[e.box] - 1);
            res += std::min(pre, post);
            active.set(B[e.box], 1);
        }
        else
        {
            active.set(B[e.box], 0);
        }
    }

    return res;
}
