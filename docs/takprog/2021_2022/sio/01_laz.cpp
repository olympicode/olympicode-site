#include "code.h"

#include <vector>
#include <random>

using namespace std;

bool Pitaj(vector<int> s) {
	int x = s.back();
	s.pop_back();
	return Pitaj(x, s);
}

int NadjiLazova(int n, int q) {
	mt19937 rng;

	vector<int> svi;
	for (int i = 1; i <= n; ++i)
		svi.push_back(i);

	vector<int> podskup;
	bool nasao = false;

	for (int pokusaj = 1; pokusaj <= 20; ++pokusaj) {
		podskup.clear();
		for (int i = 1; i <= n; ++i)
			if (rng() % 2 == 0)
				podskup.push_back(i);
		if (Pitaj(podskup)) {
			nasao = true;
			break;
		}
	}

	if (!nasao)
		return -1;

	while (podskup.size() > 1) {
		vector<int> levo, desno;
		int mid = podskup.size() / 2;
		for(int i = 0; i < podskup.size(); ++i) {
			if (i < mid)
				levo.push_back(podskup[i]);
			else
				desno.push_back(podskup[i]);
		}
		if (Pitaj(levo))
			podskup = levo;
		else
			podskup = desno;
	}

	return podskup[0];
}
