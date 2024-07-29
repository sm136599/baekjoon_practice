#include "bits/stdc++.h"
#include <unordered_map>
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int R, C;
unsigned char board[20][20];
int di[4]{ 0 ,1 , 0, -1 };
int dj[4]{ 1, 0, -1, 0 };
int answer = 0;
int alphaCnt = 0;
bool visited[26];
void dfs(int i, int j, int cnt, int history) {
	history |= (1 << board[i][j]);
	if (answer >= alphaCnt) return;
	answer = max(cnt, answer);
	for (int d = 0; d < 4; d++) {
		int ni = i + di[d];
		int nj = j + dj[d];
		if ((0 <= ni && ni < R) && (0 <= nj && nj < C)) {
			char nchar = board[ni][nj];
			if (!(history & (1 << nchar))) {
				dfs(ni, nj, cnt + 1, history);
			}
		}
	}
}

int main(void) {
	sws;
	cin >> R >> C;
	memset(visited, 1, 26);
	string input;
	for (int i = 0; i < R; i++) {
		cin >> input;
		for (int j = 0; j < C; j++) {
			unsigned char c = input[j] - 'A';
			board[i][j] = c;
			if (visited[c]) {
				visited[c] = false;
				alphaCnt++;
			}
		}
	}
	visited[board[0][0]] = true;
	dfs(0, 0, 1, 0);
	cout << answer << endl;

	return 0;
}