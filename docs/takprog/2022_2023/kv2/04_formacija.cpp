#include <iostream>
#include <algorithm>
#define MAXN 100010
#define MOD 1000000007
#define x first
#define y second
#define Point pair<int, int>
using namespace std;
Point p[2*MAXN], o;
int st2[MAXN];

long long crossProduct(Point a, Point b, Point c) {
  return (long long)(b.x-a.x)*(c.y-b.y) - (long long)(b.y-a.y)*(c.x-b.x);
}

bool collinear(Point a, Point b, Point c) {
  return crossProduct(a, b, c) == 0;
}
bool leftTurn(Point a, Point b, Point c) {
  return crossProduct(a, b, c) > 0;
}
bool rightTurn(Point a, Point b, Point c) {
  return crossProduct(a, b, c) < 0;
}

int quadrant(Point a) {
  if(a.x > 0) {
    if(a.y >= 0) return 0;
    if(a.y <  0) return 3;
  } else if(a.x < 0) {
    if(a.y >  0) return 1;
    if(a.y <= 0) return 2;
  } else {
    if(a.y >  0) return 1;
    if(a.y <  0) return 3;
  }
}

bool cmp(Point a, Point b) {
  int kA = quadrant(a), kB = quadrant(b);
  if(kA != kB) return kA < kB;
  if(!collinear(o, a, b)) return leftTurn(o, a, b);
  return abs(a.x) <= abs(b.x) && abs(a.y) <= abs(b.y);
}

bool shouldPop(Point A, Point B) {
  if(rightTurn(A, o, B)) return true;
  if(collinear(A, o, B) && quadrant(A) != quadrant(B)) return true;
  if(collinear(A, o, B) && (abs(B.x) > abs(A.x) || abs(B.y) > abs(A.y))) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int N; cin >> N;
  st2[0] = 1;
  for(int i = 1; i <= N; i++) {
    st2[i] = st2[i-1]*2;
    if(st2[i] >= MOD) st2[i] %= MOD;
  }
  o = {0, 0};
  for(int i = 1; i <= N; i++) {
    cin >> p[i].x >> p[i].y;
  }
  sort(p+1, p+1+N, cmp);
  int idx = 2, sol = 0;
  for(int i = N+1; i <= 2*N; i++) {
    p[i] = p[i-N];
    while(idx < i && (shouldPop(p[i], p[idx]) || idx+N == i)) idx++;
    sol += st2[i-idx];
    if(sol >= MOD) sol %= MOD;
  }
  cout << (st2[N]-1-sol+MOD)%MOD;
  return 0;
}
