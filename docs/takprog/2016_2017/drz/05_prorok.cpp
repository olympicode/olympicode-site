#include <cstdio>
#include <algorithm>

const int N = 100005;

struct question
{
    int id, pos;
    bool answer;
} ;

int n;
question a[N];
int cnt[N][2];  // cnt[n][x] == # of questions w/ id n and ans x
int n_both;

bool answer[N];
int timestamp[N];

bool is_valid(int k)
{
    int both = n_both, target = 0;
    for(int i = k - 1; i < n; i += k)
	if(timestamp[a[i].id] != k)
	{
	    timestamp[a[i].id] = k;
	    answer[a[i].id] = !a[i].answer;

	    if(cnt[a[i].id][0] && cnt[a[i].id][1])
		both--;
	    target += cnt[a[i].id][a[i].answer];
	}
	else
	{
	    if(answer[a[i].id] != !a[i].answer)
		return false;
	}

    return both == 0 && target == n / k;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
	char ans[10];
	scanf("%d %s", &a[i].id, &ans);
	a[i].answer = (ans[0] == 'd');
	a[i].pos = i;
    }

    // compress ids
    std::sort(a, a + n, [](question a, question b) {
	    return a.id < b.id;
	});

    int curr_val = 0, curr_id = a[0].id;
    a[0].id = curr_val;
    for(int i = 1; i < n; i++)
	if(a[i].id == curr_id)
	    a[i].id = curr_val;
	else
	{
	    curr_id = a[i].id;
	    curr_val++;
	    a[i].id = curr_val;
	}
    
    std::sort(a, a + n, [](question a, question b) {
	    return a.pos < b.pos;
	});

    // precompute cnt
    for(int i = 0; i < n; i++)
	cnt[a[i].id][a[i].answer]++;
    
    for(int i = 0; i < n; i++)
	if(cnt[i][0] && cnt[i][1])
	    n_both++;
    
    // solve
    for(int k = 2; k <= n; k++)
	if(is_valid(k))
	{
	    printf("%d\n", k);
	    return 0;
	}

    printf("-1\n");
    return 0;
}
