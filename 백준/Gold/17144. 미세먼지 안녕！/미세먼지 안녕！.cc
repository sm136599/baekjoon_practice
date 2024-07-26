#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define I first
#define J second

// 바람이 이동하는 방향
enum DIR { LEFT, RIGHT, UP, DOWN };

void spreadDust();
void removeDust();
void move(pair<int, int>, pair<int, int>, DIR);
void printRoom();

int di[4] = {0, 0, 1, -1};
int dj[4] = {1 ,-1, 0, 0};
int R, C, T;
vector<vector<int>> room;
int change[50][50];

// { 윗 부분, 아랫 부분 } 행 
vector<int> locOfAirCon;

int main(void) {
	sws;
	cin >> R >> C >> T;

	room = vector<vector<int>>(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int n; cin >> n;
			room[i][j] = n;
			if (n == -1) locOfAirCon.push_back(i);
		}
	}

	//printRoom();
	for (int t = 0; t < T; t++) {
		spreadDust();
		//cout << "---------------" << t + 1 << "초-----------------\n";
		//cout << "먼지가 퍼진다\n";
		//printRoom();
		//cout << "먼지 제거\n";
		removeDust();
		//printRoom();
	}
	int sum = 0;
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
		if (room[i][j] > 0) sum += room[i][j];
	}
	cout << sum << '\n';
	return 0;
}

void spreadDust() {
	memset(change, 0, sizeof(int) * 50 * 50);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] >= 5) {
				int miniDust = room[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int ni = i + di[k];
					int nj = j + dj[k];
					if ((0 <= ni && ni < R) && (0 <= nj && nj < C)) {
						if (room[ni][nj] != -1) {
							change[ni][nj] += miniDust;
							change[i][j] -= miniDust;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			room[i][j] += change[i][j];
		}
	}
}

void removeDust() {
	int topI = locOfAirCon[0];
	int bottomI = locOfAirCon[1];

	// 위쪽
	move(make_pair(0, 0), make_pair(topI - 1, 0), DOWN);
	move(make_pair(0, C - 1), make_pair(0, 0), LEFT);
	move(make_pair(topI, C - 1), make_pair(0, C - 1), UP);
	move(make_pair(topI, 1), make_pair(topI, C - 1), RIGHT);

	// 아래쪽
	move(make_pair(R - 1, 0), make_pair(bottomI + 1, 0), UP);
	move(make_pair(R - 1, C - 1), make_pair(R - 1, 0), LEFT);
	move(make_pair(bottomI, C - 1), make_pair(R - 1, C - 1), DOWN);
	move(make_pair(bottomI, 1), make_pair(bottomI, C - 1), RIGHT);

}

void move(pair<int, int> start, pair<int, int> end, DIR dir) {
	if (start.I == end.I) {
		int i = start.I;
		for (int j = end.J; j != start.J; j += dj[dir]) {
			room[i][j] = room[i][j + dj[dir]];
		}
		room[start.I][start.J] = 0;
	}
	else if (start.J == end.J) {
		int j = start.J;
		for (int i = end.I; i != start.I; i += di[dir]) {
			room[i][j] = room[i + di[dir]][j];
		}
		room[start.I][start.J] = 0;
	}
}
void printRoom() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << room[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}