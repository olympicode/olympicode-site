#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


struct Vector2D {
    int x, y;

    Vector2D(int _x, int _y) : x(_x), y(_y) {
    }

    Vector2D(istream& is) {
        int _x, _y;
        is >> x >> y;
        Vector2D(x, y);
    }

    Vector2D operator -(const Vector2D& o) const {
        return {x - o.x, y - o.y};
    }

    long long operator ^(const Vector2D& o) const {
        return 1ll*x*o.y - 1ll*y*o.x;
    }
};


long long areaTarget, areaBest;
vector<Vector2D> points;


void solve() {
    long long diffBest = LLONG_MAX;

    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            long long t[points.size() - 2];
            int nt = 0;
            for (int k = 0; k < points.size(); k++) {
                if (k != i && k != j) {
                    t[nt++] = (points[j] - points[i]) ^ (points[k] - points[i]);
                }
            }
            sort(t, t + nt);

            int k = 0;
            int l = 0;

            while (l < nt) {
                long long area = t[l] - t[k];
                long long diff = llabs(area - areaTarget);

                if (t[k] < 0 && t[l] > 0) {
                    if ((diff < diffBest) || ((diff == diffBest) && (area > areaBest))) {
                        areaBest = area;
                        diffBest = diff;
                    }
                }

                if (area < areaTarget) {
                    l++;
                } else {
                    k++;
                }
            }
        }
    }
}


int main() {
    int n;
    cin >> n >> areaTarget;
    areaTarget *= 2;

    for (int i = 0; i < n; i++) {
        points.push_back(Vector2D(cin));
    }

	solve();

    cout << areaBest / 2 << ((areaBest % 2 == 0) ? ".00\n" : ".50\n");

    return 0;
}
