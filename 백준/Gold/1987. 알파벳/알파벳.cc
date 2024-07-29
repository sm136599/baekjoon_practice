#include "bits/stdc++.h"
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int R, C;
unsigned char board[20][20];
int answer = 0;
int alphaCnt = 0;
bool visited[26]{ false, };

void dfs(int i, int j, int cnt, int history) {
	history |= (1 << board[i][j]);
	if (answer >= alphaCnt) return;
	answer = max(cnt, answer);
	if (i + 1 < R && (!(history & (1 << board[i + 1][j])))) {
		dfs(i + 1, j, cnt + 1, history);
	}
	if (j + 1 < C && (!(history & (1 << board[i][j + 1])))) {
		dfs(i, j + 1, cnt + 1, history);
	}
	if (i - 1 >= 0 && (!(history & (1 << board[i - 1][j])))) {
		dfs(i - 1, j, cnt + 1, history);
	}
	if (j - 1 >= 0 && (!(history & (1 << board[i][j - 1])))) {
		dfs(i, j - 1, cnt + 1, history);
	}
}

int main(void) {
	sws;
	cin >> R >> C;
	string input;
	for (int i = 0; i < R; i++) {
		cin >> input;
		for (int j = 0; j < C; j++) {
			unsigned char c = input[j] - 'A';
			board[i][j] = c;
			if (!visited[c]) {
				visited[c] = true;
				alphaCnt++;
			}
		}
	}
	dfs(0, 0, 1, 0);
	cout << answer << endl;

	return 0;
}