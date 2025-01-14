#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

typedef long long ll;

int main(void) {
	sws;
	ll a, b; cin >> a >> b;
	ll count = 0;
	for (ll i = 1; i * i <= b; i++) {
		if (i * i > a) count++;
	}
	ll g = gcd(count, b - a);
	if (count) cout << count / g << '/' << (b - a) / g;
	else cout << 0;
	return 0;
}