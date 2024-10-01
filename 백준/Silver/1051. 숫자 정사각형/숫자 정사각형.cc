#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int N, M; cin >> N >> M;
	vector<vector<int>> grid(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		string n; cin >> n;
		for (int j = 0; j < M; j++) {
			grid[i][j] = n[j] - '0';
		}
	}

	int answer = 0;
	for (int k = min(N, M); k > 0; k--) {
		if (answer != 0) break;
		for (int i = 0; i <= N - k; i++) {
			if (answer != 0) break;
			for (int j = 0; j <= M - k; j++) {
				int n = grid[i][j];
				if (n == grid[i + k - 1][j] && n == grid[i + k - 1][j + k - 1] && n == grid[i][j + k - 1]) {
					answer = k;
					break;
				}
			}
		}
	}
	cout << answer * answer << endl;

	return 0;
}