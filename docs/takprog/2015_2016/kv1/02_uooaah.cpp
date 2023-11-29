#include <cstdlib>
#include <cstdio>

double t1, t2, t3;

bool eq(double x, double y)
{
    return ((x - y < 0.000001) && (x - y > -0.000001));
}

int main()
{
    for (int tests = 0; tests < 3; tests++)
    {
        scanf("%lf%lf%lf", &t1, &t2, &t3);

        if (eq(t1, t2) && (eq(t2, t3) || t2 < t3)) // t1 = t2 <= t3
        {
            printf("UGA\n");
            printf("%.2lf %.2lf %.2lf\n", 0.0, t1/2, t3);
        }
        else if (eq(t1, t3) && (eq(t1, t2) || t1 < t2)) // t1 = t3 <= t2
        {
            printf("UGA\n");
            printf("%.2lf %.2lf %.2lf\n", 0.0, t2, t3/2);
        }
        else if (eq(t2, t3) && (eq(t3, t1) || t3 < t1)) // t2 = t3 <= t1
        {
            printf("UGA\n");
            printf("%.2lf %.2lf %.2lf\n", t1, 0.0, t2/2);
        }
        else printf("UHUH\n");
    }

    return 0;
}
