#include <iostream>
#include <map>
#include <vector>

const int P = 2000005;
bool is_prime[P];
std::vector<int> primes;

void gen_primes()
{
    for(int i = 0; i < P; i++)
	is_prime[i] = true;

    for(int i = 2; i < P; i++)
	if(is_prime[i])
	{
	    primes.push_back(i);
	    for(int j = 2 * i; j < P; j += i)
		is_prime[j] = false;
	}
}

const int N = 10000;
struct node
{
    int v;
    node *next;
    bool valid;
    node(int vv, node *n, bool x) { v = vv; next = n; valid = x; } 
} *graph[N];

std::map<int, int> factors;
std::vector<int> vals;

int register_factor(int x)
{
    if(factors.find(x) != factors.end())
	return factors[x];
    factors[x] = vals.size();
    vals.push_back(x);

    return vals.size() - 1;
}

void add_edge(int i, int j)
{
    graph[i] = new node(j, graph[i], true);
    graph[j] = new node(i, graph[j], false);
}

bool mark[N];
int prev[N];

bool dfs(int curr, int sink)
{
    if(curr == sink) return true;

    for(node *i = graph[curr]; i; i = i->next)
	if(i->valid && !mark[i->v])
	{
	    mark[i->v] = true;
	    if(dfs(i->v, sink))
	    {
		i->valid = false;
		for(node *j = graph[i->v]; j; j = j->next)
		    if(j->v == curr)
			j->valid = true;
		return true;
	    }
	}

    return false;
}

int matching(int left)
{
    int n = vals.size() + 2;
    int source = n - 2, sink = n - 1;

    for(int i = 0; i < left; i++)
	add_edge(source, i);
    for(int i = left; i < source; i++)
	add_edge(i, sink);

    int res = 0;
    while(true)
    {
	for(int i = 0; i < n; i++)
	    mark[i] = false;
	
	if(!dfs(source, sink)) break;
	res++;
    }

    return res;
}

int main()
{
    gen_primes();

    int n;
    std::cin >> n;
    vals.resize(n);

    for(int i = 0; i < n; i++)
    {
	std::cin >> vals[i];

	int n_f = 0;
	int last = 0;

	int curr = vals[i];
	for(int p : primes)
	{
	    if(p * p > curr) break;
	    if(curr % p == 0)
	    {
		n_f++;
		last = p;
		add_edge(i, register_factor(vals[i] / p));

		curr /= p;
	    }
	}

	if(n_f && curr != 1)
	    add_edge(i, register_factor(vals[i] / curr));
	if(n_f == 0 && vals[i] > 1)
	    add_edge(i, register_factor(1));
    }

    int res = matching(n);
    if(res != n)
	std::cout << -1 << std::endl;
    else
    {
	for(int i = 0; i < n; i++)
	    for(node *j = graph[i]; j; j = j->next)
		if(!j->valid)
		    std::cout << vals[i] / vals[j->v] << " ";
	std::cout << std::endl;
    }

    return 0;
}
