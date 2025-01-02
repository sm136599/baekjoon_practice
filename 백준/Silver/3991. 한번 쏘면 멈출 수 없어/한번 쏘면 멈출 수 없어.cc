#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int main(void) {
	sws;
	int h, w, c; cin >> h >> w >> c;
	priority_queue<pair<int, int>> pq;
	vector<vector<int>> answer(h, vector<int>(w));
	int direction = 1;
	int i = h - 1, j = 0;
	for (int color = 1; color <= c; color++) {
		int count; cin >> count;
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