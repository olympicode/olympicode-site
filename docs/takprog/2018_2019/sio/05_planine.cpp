#include "code.h"
#include <set>

struct field
{
	int i, j, val;
	field(int _i, int _j, int _val)
	{
		i = _i; j = _j; val = _val;
	}
};

struct cmp
{
	bool operator () (const field& A, const field& B)
	{
		if (A.val != B.val)
			return (A.val < B.val);
		if (A.i != B.i)
			return (A.i < B.i);
		return (A.j < B.j);
	}
};

std::set<field, cmp> heap;

std::vector<int> Nadji(int N, int K)
{
	heap.clear();
	for (int i = 1; i <= N; i++)
	{
		int val = Pitaj(i, i);
		heap.insert(field(i, i, val));
	}

	while (heap.size() > 1)
	{
		field minF = *heap.begin();
		field maxF = *(--heap.end());

		int i = minF.i;
		int j = minF.j;
		int k = maxF.i;
		int l = maxF.j;

		int val = Pitaj(i, l);

		if (val <= minF.val)
		{
			heap.erase(--heap.end());
		}
		else if (val >= maxF.val)
		{
			heap.erase(heap.begin());
		}
		else
		{
			heap.erase(--heap.end());
			heap.erase(heap.begin());
			heap.insert(field(i, l, val));
		}
	}

	field saddle = *heap.begin();

	int I = saddle.i;
	int J = saddle.j;
	for (int i = 1; i <= N && I != 0 && J != 0; i++)
	{
		if (i != I && Pitaj(i, J) <= saddle.val)
		{
			I = 0; J = 0;
		}
	}
	for (int j = 1; j <= N && I != 0 && J != 0; j++)
	{
		if (j != J && Pitaj(I, j) >= saddle.val)
		{
			I = 0; J = 0;
		}
	}

	std::vector<int> out;
	out.push_back(I);
	out.push_back(J);
	return out;
}
