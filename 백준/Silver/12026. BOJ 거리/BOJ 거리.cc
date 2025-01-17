#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int N; cin >> N;
	vector<char> blocks(N);
	for (int i = 0; i < N; i++) cin >> blocks[i];
	vector<int> dp(N, -1);
	map<char, char> prev{ {'B','J'}, {'O', 'B'}, {'J', 'O'} };
	dp[0] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (dp[j] == -1) continue;
			if (blocks[j] == prev[blocks[i]]) {
				if (dp[i] == -1) dp[i] = dp[j] + (i - j) * (i - j);
				else dp[i] = min(dp[j] + (i - j) * (i - j), dp[i]);
			}
		}
	}
	cout << dp[N - 1];

	return 0;
}