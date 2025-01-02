#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int h, w, c; cin >> h >> w >> c;
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= c; i++) {
		int count; cin >> count;
		pq.emplace(make_pair(count, i));
	}

	vector<vector<int>> answer(h, vector<int>(w));
	int direction = 1;
	int i = h - 1, j = 0;
	while (!pq.empty()) {
		int count = pq.top().first,
			color = pq.top().second;
		pq.pop();
		for (int k = 0; k < count; k++) {
			answer[i][j] = color;

			if (j == 0 && direction == -1) {
				direction = 1;
				i--;
			}
			else if (j == w - 1 && direction == 1) {
				direction = -1;
				i--;
			}
			else {
				j += direction;
			}
		}
	}

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			cout << answer[i][j];
		}
		cout << '\n';
	}
	return 0;
}