#include <bits/stdc++.h>

using namespace std;

int n[3], l[3];

int Stage2()
{
	int neutral[3];
	int score = 0;
	for(int i = 0; i <= 2; i++)
	{
		neutral[i] = min(l[i], n[i]);
		score += neutral[i];
	}
	for(int i = 0; i <= 2; i++)
	{
		int j = (i + 2) % 3;
		int bad = min((l[i] - neutral[i]) / 2, (n[j] - neutral[j]));
		score += bad;
	}
	return score;
}

int Branch(int i)
{
	if(i == 3)
	{
		return Stage2();
	}
	int score_stage2 = Branch(i + 1);
	int j = (i + 1) % 3;
	if(l[i] > 0 && n[j] == 1)
	{
		l[i]--;
		n[j]--;
		score_stage2 = max(score_stage2, 1 + Branch(i + 1));
		l[i]++;
		n[j]++;
	}
	return score_stage2;
}

int main()
{
	scanf("%d %d %d", &n[0], &n[1], &n[2]);
	scanf("%d %d %d", &l[0], &l[1], &l[2]);
	int score = 0;
	for(int i = 0; i <= 2; i++)
	{
		int j = (i + 1) % 3;
		int good = min(l[i], n[j] / 2);
		l[i] -= good;
		n[j] -= good * 2;
		score += good * 2;
	}
	score += Branch(0);
	printf("%d\n", score);
	return 0;
}