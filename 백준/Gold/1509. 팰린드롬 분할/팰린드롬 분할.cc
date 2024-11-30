#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

vector<vector<bool>> isPalin;
string str;
int N;

int main(void) {
	sws;
	cin >> str;
	N = str.length();
	isPalin.resize(N, vector<bool>(N, true));
	for (int i = N - 2; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			isPalin[i][j] = (isPalin[i + 1][j - 1] && !(str[i] ^ str[j]));
		}
	}
	vector<int> dp(N+1, 2501);
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		int minCnt = 2501;
		for (int j = i; j >= 1; j--) {
			if (isPalin[j - 1][i - 1]) {
				minCnt = min(minCnt, dp[j - 1]);
			}
		}
		dp[i] = minCnt + 1;
	}
	cout << dp[N];
	return 0;
}