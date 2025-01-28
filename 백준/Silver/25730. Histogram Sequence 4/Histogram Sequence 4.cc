#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

typedef long long ll;

int main(void) {
	sws;
	ll N, A, L, R;
	cin >> N >> A >> L >> R;
	ll i = 0;
	for (i = N; i >= 1; i--) {
		if (A % i) continue;
		ll h = A / i;
		if (h >= L && h <= R) {
			break;
		}
	}
	if (i == 0 || (L > A / N)) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		ll j = 0;
		for (; j < i; j++) cout << (A / i) << ' ';
		for (; j < N; j++) cout << L << ' ';
	}

	return 0;
}