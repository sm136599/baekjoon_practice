#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int n;
vector<vector<char>> board;
string str;
int di[]{ 0, 0, 1, 1 };
int dj[]{ 0, 1, 0, 1 };

int makeBoard(int boardSize, int boardI, int boardJ, int idx) {
	int i = idx + 1;
	for (int k = 0; k < 4; k++) {
		int ni = boardI + di[k] * boardSize;
		int nj = boardJ + dj[k] * boardSize;
		if (str[i] == 'Q') {	
			i = makeBoard(boardSize / 2, ni, nj, i);
		}
		else {
			char c = str[i];
			for (int i = ni; i < ni + boardSize; i++) {
				for (int j = nj; j < nj + boardSize; j++) {
					if (c == 'B') board[i][j] = 1;
				}
			}
			i++;
		}
	}
	return i;
}
void printAnswer() {
	cout << "#define quadtree_width " << n << '\n';
	cout << "#define quadtree_height " << n << '\n';
	cout << "static char quadtree_bits[] = {\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j += 8) {
			unsigned char temp = 0;
			unsigned char plus = 1;
			for (int jj = j; jj < j + 8; jj++) {
				if (board[i][jj]) {
					temp += plus;
				}
				plus <<= 1;
			}
			cout << "0x" << setfill('0') << setw(2) << hex  << (unsigned int)temp << ",";
		}
		cout << '\n';
	}
	cout << "};";
}

int main(void) {
	sws;
	cin >> n;
	board = vector<vector<char>>(n, vector<char>(n, 0));
	cin >> str;
	
	if (str[0] == 'Q') {
		makeBoard(n / 2, 0, 0, 0);
	}
	else if (str[0] == 'B') {
		board = vector<vector<char>>(n, vector<char>(n, 1));
	}
	printAnswer();

	return 0;
}