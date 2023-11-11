#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const double EPS = 1e-7;
const double PI = 3.1415926535;

int n, m;

struct Point
{
	double x, y;
	double angle;

	bool operator < (const Point &p) const
	{
		return angle < p.angle;
	}

	Point(){}

	Point(double _x, double _y)
		: x(_x), y(_y)
	{
		angle = atan2(y, x);
		if (angle < -EPS)
		{
			angle += 2.0 * PI;
		}
	}
};

double angleDifference(double angle1, double angle2)
{
	double angle = angle1 - angle2;
	if (angle < -EPS)
	{
		angle += 2.0 * PI;
	}
	return angle;
}

Point points[MAXN];
Point sorted[MAXN];

bool equals(double a, double b)
{
	return fabs(a - b) < EPS;
}

bool UpdateStart(int j, int &start)
{
	while (equals(sorted[start % m].angle, sorted[j].angle)) start++;	// preskocim kolinearne

	while (true)
	{
		double diff = angleDifference(sorted[start % m].angle, sorted[j].angle);

		if (diff > PI / 2.0 - EPS && diff < PI - EPS)	// ako je >= 90 stepeni && < 180 stepeni (nadje start i prekine)
		{
			return true;
		}
		else if (diff >= PI - EPS)	// ako je >= 180 stepeni onda nije naisao na ugao koji je izmedju [90, 180) pa kaze nije nasao start
		{
			return false;
		}
		start++;

		if (equals(sorted[start % m].angle, sorted[j].angle))	// ako sam naisao na neku kolinearnu opet onda znaci da ne postoji nijedan od gore navedenih uglova
		{
			return false;
		}
	}
	return false;
}

// sve isto kao UpdateStart samo sto ovde izlazim kad naidjem na ugao >= 180
bool UpdateEnd(int j, int &end)
{
	while (equals(sorted[end % m].angle, sorted[j].angle)) end++;

	while (true)
	{
		double diff = angleDifference(sorted[end % m].angle, sorted[j].angle);
		if (diff >= PI - EPS)
		{
			return true;
		}

		end++;
		if (equals(sorted[end % m].angle, sorted[j].angle))
		{
			return false;
		}
	}
	return false;
}

int CalculateDegen()
{
	int ans = 0;

	int j = 0;
	for (int i = 0; i < m; j++)
	{
		while (equals(sorted[i].angle, sorted[j].angle))
		{
			j++;
		}
		ans += (j - i) * (j - i - 1) / 2;
		i = j + 1;
	}
	return ans;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf", &points[i].x, &points[i].y);
	}

	int total = 0;
	int totalDegen = 0;

	for (int i = 0; i < n; i++)
	{
		m = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			
			sorted[m++] = Point(points[j].x - points[i].x, points[j].y - points[i].y);
		}
		
		sort(sorted, sorted + m);		// sorted sadrzi tacke koje su sortirane u odnosu na fiksiranu tacku p[i]
		totalDegen += CalculateDegen();

		int start = 0, end = 0;	// start je prvi prav ili tup ugao, end je prvi >= 180 (tj. interval [start, end) predstavlja prave/tupe)
		int degenStart = 0, degenEnd = 0;

		for (int j = 0; j < m; j++)
		{
			// fiksiram drugu tacku, updatujem start i end
			bool existsStart = UpdateStart(j, start);
			bool existsEnd = UpdateEnd(j, end);

			// ako start postoji (onda postoji i end sigurno) i updatujem broj tupih/pravih uglova
			if (existsStart)
			{
				total += end - start;
			}
			else if (!existsEnd)	// ako ne postoji ni start ni end onda je pretpostavka da dalje ne postoji nijedan tup/prav ugao
									// za trenutno fiksiranu tacku (mislim da je tacno jer ce se uglovi samo smanjivati 
									// a kako ne postoji >= 90 nijedan onda su svi ostri)
			{
				break;
			}
		}
	}

	int totalTriangles = n * (n - 1) * (n - 2) / 6;
	totalDegen /= 2;
	printf("%d %d\n", total, totalDegen);

	printf("%d\n", totalTriangles - total - totalDegen);

	return 0;
}