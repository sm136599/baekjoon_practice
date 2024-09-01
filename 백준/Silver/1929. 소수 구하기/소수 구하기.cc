#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int M, N; cin >> M >> N;
	vector<bool> isPrime(N + 1, true);
	isPrime[1] = false;
	for (int i = 2; i <= N; i++) {
		if (!isPrime[i]) continue;
		for (int j = 2; i * j <= N; j++) {
			isPrime[i * j] = false;
		}
	}
	for (int i = M; i <= N; i++) {
		if (isPrime[i]) cout << i << '\n';
	}
	return 0;
}