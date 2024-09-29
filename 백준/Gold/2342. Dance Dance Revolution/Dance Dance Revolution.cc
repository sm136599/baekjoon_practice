#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int answer = 400000;

vector<vector<vector<int>>> dp;
vector<int> cmd;
int n;

int getPower(int from, int to) {
	if (from == 0) return 2;
	switch (abs(from - to)) 
	{
	case 0:
		return 1;
	case 1:
	case 3:
		return 3;
	case 2:
		return 4;
	default:
		break;
	}
}

int main(void) {
	sws;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cmd.push_back(n);
	}

	n = cmd.size();
	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}
	dp = vector<vector<vector<int>>>(5, vector<vector<int>>(5, vector<int>(n + 1, 400000)));
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		int to = cmd[i - 1];
		// 오른발 이동
		for (int l = 0; l < 5; l++) {
			for (int r = 0; r < 5; r++) {
				int power = getPower(r, to);
				dp[l][to][i] = min(dp[l][to][i], dp[l][r][i - 1] + power);
			}
		}
		// 왼발 이동
		for (int r = 0; r < 5; r++) {
			for (int l = 0; l < 5; l++) {
				int power = getPower(l, to);
				dp[to][r][i] = min(dp[to][r][i], dp[l][r][i - 1] + power);
			}
		}
	}

	int answer = 400000;
	for (int l = 0; l < 5; l++) {
		for (int r = 0; r < 5; r++) {
			answer = min(dp[l][r][n], answer);
		}
	}

	cout << answer << endl;
	return 0;
}