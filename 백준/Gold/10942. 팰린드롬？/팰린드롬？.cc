#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int N; cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++) cin >> nums[i];
	vector<vector<bool>> dp(N, vector<bool>(N, true));
	for (int k = 1; k < N; k++) {
		for (int i = 0; i + k < N; i++) {
			int j = i + k;
			dp[i][j] = (dp[i + 1][j - 1] && !(nums[i] ^ nums[j]));
		}
	}
	int M; cin >> M;
	int s, e;
	while (M--) {
		cin >> s >> e;
		cout << dp[s - 1][e - 1] << '\n';
	}
	return 0;
}