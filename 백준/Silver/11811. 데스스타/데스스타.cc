#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a_i = 0;
		for (int j = 0; j < N; j++) {
			int mij; cin >> mij;
			if (i == j) continue;
			a_i |= mij;
		}
		cout << a_i << ' ';
	}


	return 0;
}