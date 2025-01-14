#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

typedef long long ll;

ll llsqrt(ll val) {
	ll s = 0, e = 1073741824;
	ll ret;
	while (s <= e) {
		ll m = (s + e) / 2;
		if (m * m <= val) {
			s = m + 1;
			ret = m;
		}
		else {
			e = m - 1;
		}
	}
	return ret;
}

int main(void) {
	sws;
	ll a, b; cin >> a >> b;
	ll s = 0, e = b;
	ll a_sqrt = llsqrt(a), b_sqrt = llsqrt(b);
	ll count = b_sqrt - a_sqrt;
	ll g = gcd(count, b - a);
	if (count) cout << count / g << '/' << (b - a) / g;
	else cout << 0;
	return 0;
}