#include "bits/stdc++.h"
#include <unordered_map>
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

typedef long long ll;
int main(void) {
	sws;
	int n; cin >> n;
	unordered_map<ll, int> count;
	while (n--) {
		count.clear();
		int t; cin >> t;
		for (int i = 0; i < t; i++) {
			ll N; cin >> N;
			count[N]++;
		}
		ll answer = 1000000000000;
		for (auto& p : count) {
			if (p.second >= t / 2  + 1) {
				answer = p.first;
			}
		}
		if (answer == 1000000000000) {
			cout << "SYJKGW\n";
		}
		else {
			cout << answer << '\n';
		}
	}

	return 0;
}