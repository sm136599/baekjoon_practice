#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int N; cin >> N;
	vector<pair<int, int>> rc(N);
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		rc[i] = make_pair(a, b);
	}

	vector<vector<int>> dp(N, vector<int>(N, 2147483647));
	for (int i = 0; i < N; i++) dp[i][i] = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + rc[i].first * rc[k].second * rc[j].second);
			}
		}
	}

	cout << dp[0][N - 1] << '\n';

	return 0;
}