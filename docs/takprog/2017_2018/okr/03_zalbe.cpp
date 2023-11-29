#include <cstdlib>
#include <cstdio>

const int MAX_N = 200010;

int p[MAX_N], a[MAX_N], blockLen[MAX_N];
char s[MAX_N];
bool mark[MAX_N];

int n, k, bNum;

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);

	// podela stringa s na blokove oblika GPPP...P (uz vestacko 'G' na pocetku)
	bNum = 0;
	blockLen[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (s[i] == 'P')
			blockLen[bNum]++;
		else
			blockLen[++bNum] = 1;
	}
	
	int curr = 0;
	while (curr <= bNum && blockLen[curr] == 1) curr++;
	// curr simbola 'G' (ne ukljucujuci vestacki) pa onda PPP.. => permutacija sigurno krece (k, k+1, ..., k+curr-1)
	// a naredni korak zavisi od duzine niza PPP... (pomeranje ulevo) - ako nije predugacak, pomeraj na k+curr a inace mora 'desnije'
	for (int i = 0; i < curr; i++)
		mark[k + i] = true;
	if (curr <= bNum)
	{
		if (blockLen[curr] <= k)
			mark[k + curr] = true;
		else
			mark[blockLen[curr] + curr] = true;
		blockLen[curr]--;
	}

	// ubaciti markirane elemente na pocetak permutacije p[] i napraviti niz a preostalih slobodnih elemenata;
	int m = 0;
	int currP = 0;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i])
			p[++currP] = i;
		else
			a[++m] = i;
	}
	
	// sada resavamo subtask 4 gde je niz (a[1], a[2], ..., a[m]) pocevsi od bloka curr
	int pos = 0;
	for (int i = curr; i <= bNum; i++)
	{
		pos = pos + blockLen[i];
		for (int j = 0; j < blockLen[i]; j++)
			p[++currP] = a[pos - j];
	}

	for (int i = 1; i < n; i++)
		printf("%d ", p[i]);
	printf("%d\n", p[n]);
	
	return 0;
}