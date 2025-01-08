#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

/*
* 시간이 지날 수록 주변에 토마토에 영향을 끼치는 문제
* 시간이지나 스스로 익는 토마토는 없기 때문에, 
* 단순히 현재 시간과 익은 토마토의 위치를 넣고 빼는 큐를 사용해 BFS를 사용해 풀면된다.
* 시간 복잡도는 O(M*N)이다.
*/

int di[]{ 0, 0, 1, -1 };
int dj[]{ 1, -1, 0, 0 };

int main(void) {
	sws;
	int M, N; cin >> M >> N;
	vector<vector<char>> tomatos(N, vector<char>(M));
	//queue<tuple<int, int, int>> q;
	queue<tuple<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int n; cin >> n;
			tomatos[i][j] = n;
			if (n == 1) {
				q.emplace(i, j);
			}
		}
	}

	int answer = -1;
	while (!q.empty()) {
		int n = q.size();
		while (n--) {
			for (int k = 0; k < 4; k++) {
				int ni = get<0>(q.front()) + di[k];
				int nj = get<1>(q.front()) + dj[k];
				if (!(0 <= ni && ni < N && 0 <= nj && nj < M)) continue;
				if (tomatos[ni][nj]) continue;
				tomatos[ni][nj] = 1;
				q.emplace(ni, nj);
			}
			q.pop();
		}
		answer++;
	}

	int tomato = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomatos[i][j] == 0) {
				tomato = 1;
				break;
			}
		}
	}
	if (tomato) {
		cout << -1;
	}
	else {
		cout << answer;
	}


	return 0;
}