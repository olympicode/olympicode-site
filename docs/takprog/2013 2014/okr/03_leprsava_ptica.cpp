#include <iostream>
#include <ctime>
#include <stdio.h>
using namespace std;

#define MaxN 1000010

int n,h;
int x[MaxN];
int hg[MaxN];
int hd[MaxN];

int currUp, currDown;

int main()
{
	scanf("%d%d",&h,&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d",&x[i],&hd[i],&hg[i]);
	}

	if ( h % 2 == 1 ) currUp = currDown = (h+1) / 2;
	else currUp = currDown = h / 2;

	int ret = 0;
	int currPosition = 0;
	while ( ret < n && currDown <= currUp ) {
		int distance = x[ret] - currPosition;
		int maxH = currUp + distance;
		int minH = currDown - distance;

		int newCurrUp = min( h - hg[ret], maxH );
		int newCurrDown = max( hd[ret] + 1, minH );

		if ( distance % 2 == 1 ) {
			if ( currUp % 2 == newCurrUp % 2 ) --newCurrUp;
			if ( currDown % 2 == newCurrDown % 2 ) ++newCurrDown;
		}
		else {
			if ( currUp % 2 != newCurrUp % 2 ) --newCurrUp;
			if ( currDown % 2 != newCurrDown % 2 ) ++newCurrDown;
		}

		currPosition = x[ret];
		currUp = newCurrUp;
		currDown = newCurrDown;
		if ( currDown <= currUp ) ++ret;
	}

	printf("%d\n",ret);

	return 0;
}
