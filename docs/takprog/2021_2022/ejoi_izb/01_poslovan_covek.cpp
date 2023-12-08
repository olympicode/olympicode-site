#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 10;
int N, A, C;
int B[maxN];
long long sufBest[maxN];

int main() {

	cin >> N >> A >> C;
    
  for (int i = 1 ; i <= N; i++) {
    cin >> B[i];
  }

  for (int i = N; i > 0; i--) {
    sufBest[i] = sufBest[i  + 1] + max(A, 2 * B[i]);
  }
  
  multiset<int> taken;
  long long setSum = 0;
  long long answer = 0;
  long long totalSum = 0;
  for (int i = 1; i <= N; i++) {
   	totalSum+=max(A, B[i]);
    taken.insert(B[i]);
    setSum+=B[i];
    while(setSum - *taken.begin() > C && *taken.begin() < A) {
     	setSum-= *taken.begin();
     	taken.erase(taken.begin());
    }

    if (setSum > C) {
      int setSize = taken.size();
      answer = max(answer, setSum + 1ll * (i - setSize) * A  + sufBest[i + 1]);
    }
  }

  answer = max(answer, totalSum);

  cout << answer << endl;
}