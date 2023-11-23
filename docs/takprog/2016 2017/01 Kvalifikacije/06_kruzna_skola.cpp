#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>


using namespace std;

const int maxN = 10000000;

int state[maxN];
int n, t;


struct Particle {
	int p, dir;
	bool used = false;
	int annihilated = 0;

	Particle(int _p, int _dir):p(_p), dir(_dir) {}
};

vector<Particle> particles;


void solve() {

	for (int i = 0; i < n; i++) {
		int c = state[i];
		int r = state[(i + 1) % n];
		if (c == r) {
			Particle p = Particle(i, c ? -1 : 1);
			particles.push_back(p);
		}
	}

	stack<int> s;
	int last = -1;

	for (int z = 0; z < 2; z++) {
		for (int i = 0; i < particles.size(); i++) {
			Particle *p = &particles[i];
			if (!p->used) {
				if (p->dir == 1) {
					p->used = true;
					s.push(i);
				} else {
					if (!s.empty()) {
						p->used = true;
						Particle *q = &particles[s.top()];
						s.pop();
						int d = (p->p - q->p + n) % n;
						q->annihilated = p->annihilated = (d / 2 <= t ? 2 : 1);
						last = i;
					}
				}
			}
		}
	}

	int j = -1;
	for (int i = 0; i < particles.size(); i++) {
		if (particles[i].annihilated == 0) {
			j = i;
			break;
		}
	}

	int k, st;

	if (j != -1) {
		k = ((particles[j].p + particles[j].dir * t) % n + n) % n;
		st = state[particles[j].p % n];
	} else {
		if (last != -1) {
			k = ((particles[last].p - t + 2) % n + n) % n;
			st = state[(particles[last].p + 2) % n];
		} else {
			k = t % n;
			st = state[0];
		}
	}

	std::fill(state, state + n, 0);

	for (int i = 0; i < particles.size(); i++) {
		if (particles[i].annihilated != 2) {
			state[((particles[i].p + particles[i].dir * t) % n + n) % n] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		int j = (k + i) % n;
		int nextState = (state[j] == st);
		state[j] = st;
		st = nextState;
	}
}

char ulaz[10000555];

int main() {
    scanf("%i %i\n", &n, &t);
    t--;

    gets(ulaz);
    for (int i = 0; i < n; i++) {
		state[i] = ulaz[i] - '0';
    }

	solve();

	int d = 100000;
	int l = min(n, d);
	for (int i = 0; i < l; i++) {
		int a = 0;
		for (int j = i; j < n; j += d) {
			a ^= state[j];
		}
		printf("%i", a);
	}
    printf("\n");

    return 0;
}
