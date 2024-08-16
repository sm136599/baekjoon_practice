#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;

	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	vector<int> dp(N); 
	dp[0] = 1;

	for (int i = 1; i < N; i++) {
		// find less than index
		int maxj = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] < a[i]) {
				maxj = max(maxj, dp[j]);
			}
		}
		dp[i] = maxj + 1;
	}

	vector<int> dp_rev(N);
	dp_rev[N - 1] = 1;
	for (int i = N - 2; i >= 0; i--) {
		int maxj = 0;
		for (int j = i + 1; j < N; j++) {
			if (a[j] < a[i]) {
				maxj = max(maxj, dp_rev[j]);
			}
		}
		dp_rev[i] = maxj + 1;
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[i] + dp_rev[i]);
	}
	answer--;
	cout << answer << endl;


	return 0;
}