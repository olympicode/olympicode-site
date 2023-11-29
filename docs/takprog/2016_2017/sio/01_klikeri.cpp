#include <iostream>
#include <cstdio>
#include <algorithm>

const int N = 30005;
int marble[N], target[N];
int n, len;

int left[2 * N], right[2 * N]; // targets represented as N and above

int abs(int x) { return x < 0 ? -x : x; } 

int shift(int pos, int diff)
{
    pos += diff;
    if(pos <= 0) pos = 1 - pos;
    if(pos > len) pos = 2 * len - pos + 1;
    return pos;
}

void make_jumps(int from[], int to[], int left[], int right[], int t)
{   
    int j = n - 1;
    for(int i = 0; i < n; i++)
    {
	int pos = shift(from[i], -t);
	if(from[i] <= t)
	    while(j && to[j] > pos) j--;
	else
	{
	    if((i && from[i - 1] <= t) || (i == 0)) j = 0;
	    while(j < n - 1 && to[j] < pos) j++;
	}
	
	if(to[j] == pos) left[i] = j;
	else left[i] = -1;
    }

    j = 0;
    for(int i = 0; i < n; i++)
    {
	int pos = shift(from[i], t);
	if(from[i] >= len - t + 1)
	{
	    if((i && from[i - 1] < len - t + 1) || (i == 0)) j = n - 1;
	    while(j && to[j] > pos) j--;
	}
	else
	    while(j < n - 1 && to[j] < pos) j++;

	if(to[j] == pos) right[i] = j;
	else right[i] = -1;
    }
}

bool can_activate(int t)
{
    make_jumps(marble, target, left, right, t);
    for(int i = 0; i < n; i++)
    {
	if(left[i] != -1) left[i] += N;
	if(right[i] != -1) right[i] += N;
    }
    
    make_jumps(target, marble, left + N, right + N, t);
    
    for(int i = 0; i < n; i++)
    {
       	if(left[i] == -1 && right[i] == -1)
	    return false; 

	else if((left[i] == -1) != (right[i] == -1))
	{
	    int curr = (left[i] == -1) ? right[i] : left[i];
	    int prev = i;
	    int cnt = 2;

	    while(1)
	    {
	        if(left[curr] == -1 || right[curr] == -1)
		    break;

		int tmp = curr;
		curr = left[curr] + right[curr] - prev; // stupid hack
		prev = tmp;
		
		cnt++;
	    }

	    if(cnt % 2 != 0) return false;
	}

	// don't care about those with two matches: either in cycle
	// (so OK) or on path (will check when starting from an end of
	// the path)
    }

    return true;
}

int main()
{
    scanf("%d %d", &len, &n);
    for(int i = 0; i < n; i++)
	scanf("%d", &marble[i]);
    for(int i = 0; i < n; i++)
	scanf("%d", &target[i]);

    std::sort(marble, marble + n);
    std::sort(target, target + n);

    int res = 1 << 30;
    for(int i = 0; i < n; i++)
    {
	// go directly
	int t = abs(marble[0] - target[i]);
	if(can_activate(t))
	    res = std::min(res, t);

	// bounce off a wall
	t = std::min(abs(marble[0] + target[i] - 1), abs(marble[0] - (2 * len - target[i] + 1)));
	if(can_activate(t))
	    res = std::min(res, t);
    }

    if(res == (1 << 30))
	res = -1;
    printf("%d\n", res);
    
    return 0;
}
