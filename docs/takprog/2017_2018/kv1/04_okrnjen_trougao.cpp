#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

const int MAXN = 200050;

typedef long long ll;
typedef double real_t;

struct pt {
	ll x, y;

	pt operator- (const pt& other) const {
		return {x - other.x, y - other.y};
	}

	bool operator< (const pt& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
};

ll det(pt a, pt b) {
	return a.x * b.y - b.x * a.y;
}

ll det(pt a, pt b, pt c) {
	return det(a-c, b-c);
}

set<pair<pt, pt>> s;

int n;
pt a[MAXN], h[MAXN];
int n1, n2, m;

void scan(int dir, pt* b, int& num) {
	int s = dir > 0 ? 0 : n-1;
	int e = dir > 0 ? n : -1;

	num = 0;

	for (int i=s; i!=e; i+=dir) {
		while (num >= 2 && det(b[num-2], b[num-1], a[i]) <= 0) {
			num--;
		}
		b[num++] = a[i];
	}

	num--;
}

real_t sol = 0.0;
bool sol_found = false;

void process_sol(pt a, pt b, pt c, pt d, ll cross_det) {
	// naci povrsinu trougla cije su dve tacke b, c
	// a treca nastala presekom polupravih b->a i c->d
	// 
	real_t area = det(a, b, c);
	area *= det(b, c, d);
	area /= cross_det;
	area /= 2;

	if (area < 0) {
		area *= -1;
	}

	if (!sol_found || area < sol) {
		sol_found = true;
		sol = area;
	}
}

int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%lld%lld", &a[i].x, &a[i].y);
	}

	a[n] = a[0];
	real_t poly_area = 0.0;
	for (int i=0; i<n; i++) {
		s.insert({a[i], a[i+1]});
		poly_area += det(a[i], a[i+1]);
	}

	poly_area /= 2;

	if (poly_area < 0) {
		poly_area *= -1;
	}

	sort(a, a+n);
	scan(+1, h, n1);
	scan(-1, h+n1, n2);
	m = n1 + n2;

	h[m] = h[0];
	h[m+1] = h[1];
	h[m+2] = h[2];
	
	for (int i=0; i<m; i++) {
		pt a = h[i];
		pt b = h[i+1];
		pt c = h[i+2];
		pt d = h[i+3];

		// Ne nalazimo duz u skupu originalnih duzi
		if (s.count({b, c}) + s.count({c, b}) == 0) {
			continue;
		}

		// proverimo da li je zbir spoljnjih uglova abc i bcd > 180
		// ako jeste imamo resenje

		ll cross_det = det(b-a, d-c);

		if (cross_det < 0) {
			// imamo levo skretanje
			process_sol(a, b, c, d, cross_det);
		}
	}

	// fprintf(stderr, "%.9f\n", poly_area);
	// fprintf(stderr, "%.9f\n", sol);

	// odstampaj povrsinu
	if (sol_found) {
		cout.precision(20);
		cout << fixed << (sol - poly_area) * 1.000002 << '\n';
	} else {
		cout << "-1\n";
	}
}
