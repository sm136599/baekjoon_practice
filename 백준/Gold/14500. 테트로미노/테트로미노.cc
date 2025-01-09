#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

/* 
* 브루트포스 문제, 모든 상황을 보고 답을 내야 한다.
* 테트로미노는 정사각형 4개를 이어붙인 모양
* dfs를 사용해 현재 위치에서 최대 4칸까지 가게 하면 테트로미노가 만들어진 모양대로 점수를 매길 수 있다.
* 다만 ㅗ 모양의 테트리노는 일반적인 dfs로 만들 수 없기 때문에, 
* 길이가 2일 때는 현재 좌표를 넘겨주는 식으로 한 번 더 체크해야 한다.
* 시간 복잡도는 O(4^3*N*M) = O(N*M)
*/

int N, M;
vector<vector<short>> paper;
vector<vector<char>> visited;
int di[]{ 0, 0, -1, 1 };
int dj[]{ 1, -1, 0, 0 };
short answer = 0;

void checkTetromino(int ci, int cj, int depth, short score) {
	if (depth == 4) {
		answer = max(answer, score);
		return;
	}

	for (int k = 0; k < 4; k++) {
		int ni = ci + di[k];
		int nj = cj + dj[k];
		if (!(0 <= ni && ni < N && 0 <= nj && nj < M)) continue;
		if (visited[ni][nj]) continue;
		visited[ni][nj] = 1;
		checkTetromino(ni, nj, depth + 1, score + paper[ni][nj]);
		if (depth == 2) checkTetromino(ci, cj, depth + 1, score + paper[ni][nj]);
		visited[ni][nj] = 0;
	}
}

int main(void) {
	sws;
	cin >> N >> M;
	paper.resize(N, vector<short>(M));
	visited.resize(N, vector<char>(M));

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> paper[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			checkTetromino(i, j, 1, paper[i][j]);
			visited[i][j] = 0;
		}
	}
	cout << answer;

	return 0;
}