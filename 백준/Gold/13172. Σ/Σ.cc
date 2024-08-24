#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)
#define MOD 1000000007
typedef long long ll;

ll getInverseNum(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n % 2) {
			res %= MOD;
			res *= a;
			res %= MOD;
		}
		a *= a;
		a %= MOD;
		n /= 2;
	}
	return res;
}

int main(void) {
	sws;
	int M; cin >> M;
	ll answer = 0;
	for (int i = 0; i < M; i++) {
		ll a, b; cin >> a >> b;
		ll a_inv = getInverseNum(a, MOD - 2);
		answer = (answer + (b * a_inv) % MOD) % MOD;
	}
	cout << answer << '\n';

	return 0;
}