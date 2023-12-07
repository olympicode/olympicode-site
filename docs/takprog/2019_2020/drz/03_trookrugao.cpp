#include <cstdlib>
#include <cstdio>

const int MAX_N = 50000;
const int MAX_COORD = 100000;
const int MAX_CIRC_POINTS = 324;

struct point
{
	int x, y;

	point() {}
	point(int x_, int y_)
	{
		x = x_; y = y_;
	}
};

int n, R;
int X[MAX_N + 10], Y[MAX_N + 10];
int N;
point centers[MAX_N * MAX_CIRC_POINTS + 10];
point tmp[MAX_N * MAX_CIRC_POINTS + 10];
int c[4 * MAX_COORD + 10];
int RN;
point circlePoints[MAX_CIRC_POINTS + 10];

void findPointsOnCircle(int R)
{
	RN = 0;
	circlePoints[RN++] = point(0, R);
	circlePoints[RN++] = point(0, -R);
	circlePoints[RN++] = point(R, 0);
	circlePoints[RN++] = point(-R, 0);

	long long rsqr = (long long)R * (long long)R;
	long long b = R - 1;
	for (long long a = 1; a < R; a++)
	{
		while (a*a + b*b > rsqr)
			b--;
		if (a*a + b*b == rsqr)
		{
			circlePoints[RN++] = point((int)a, (int)b);
			circlePoints[RN++] = point((int)a, (int)-b);
			circlePoints[RN++] = point((int)-a, (int)b);
			circlePoints[RN++] = point((int)-a, (int)-b);
		}
	}
}


void countSort(int N, point points[], bool sortByX)
{
	int K = 4 * MAX_COORD;

	for (int i = 0; i <= K; i++)
		c[i] = 0;
	for (int i = 0; i < N; i++)
		c[sortByX ? points[i].x : points[i].y]++;
	for (int i = 1; i <= K; i++)
		c[i] = c[i - 1] + c[i];

	for (int i = N - 1; i >= 0; i--)
	{
		tmp[c[sortByX ? points[i].x : points[i].y] - 1] = points[i];
		c[sortByX ? points[i].x : points[i].y]--;
	}

	for (int i = 0; i < N; i++)
		points[i] = tmp[i];
}

int main()
{
	scanf("%d%d", &n, &R);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &X[i], &Y[i]);
	}

	findPointsOnCircle(R);

	N = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < RN; j++)
		{
			centers[N++] = point(2 * MAX_COORD + X[i] + circlePoints[j].x, 2 * MAX_COORD + Y[i] + circlePoints[j].y);
		}
	}

	countSort(N, centers, false);
	countSort(N, centers, true);

	long long sol = 0;
	int k = 1;
	for (int i = 0; i < N; i++)
	{
		if (i < N - 1 && (centers[i].x == centers[i + 1].x && centers[i].y == centers[i + 1].y))
		{
			k++;
		}
		else
		{
			sol = sol + k * (k - 1) * (k - 2) / 6;
			k = 1;
		}
	}

	printf("%lld\n", sol);

	return 0;
}

