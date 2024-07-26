#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define I first
#define J second

// 바람이 이동하는 방향
enum DIR { LEFT, RIGHT, UP, DOWN };
int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1 ,-1, 0, 0 };

class AirCleaner {
	int room[50][50];
	int r;
	int c;
	int topI;
	int bottomI;
public:
	AirCleaner() {
		memset(this->room, 0, sizeof(int) * 50 * 50);
		this->r = -1;
		this->c = -1;
		this->topI = -1;
		this->bottomI = -1;
	}
	AirCleaner(int(*room)[50], int r, int c) {
		memcpy(this->room, room, sizeof(int) * 50 * 50);
		this->r = r;
		this->c = c;
		vector<int> locOfAirCon;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (room[i][j] == -1) locOfAirCon.push_back(i);
			}
		}
		topI = locOfAirCon[0]; 
		bottomI = locOfAirCon[1];
	}
	void spreadDust() {
		int change[50][50];
		memset(change, 0, sizeof(int) * 50 * 50);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (room[i][j] >= 5) {
					int miniDust = room[i][j] / 5;
					for (int k = 0; k < 4; k++) {
						int ni = i + di[k];
						int nj = j + dj[k];
						if ((0 <= ni && ni < r) && (0 <= nj && nj < c)) {
							if (room[ni][nj] != -1) {
								change[ni][nj] += miniDust;
								change[i][j] -= miniDust;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				room[i][j] += change[i][j];
			}
		}
	}
	void removeDust() {
		// 위쪽
		move(make_pair(0, 0), make_pair(topI - 1, 0), DOWN);
		move(make_pair(0, c - 1), make_pair(0, 0), LEFT);
		move(make_pair(topI, c - 1), make_pair(0, c - 1), UP);
		move(make_pair(topI, 1), make_pair(topI, c - 1), RIGHT);

		// 아래쪽
		move(make_pair(r - 1, 0), make_pair(bottomI + 1, 0), UP);
		move(make_pair(r - 1, c - 1), make_pair(r - 1, 0), LEFT);
		move(make_pair(bottomI, c - 1), make_pair(r - 1, c - 1), DOWN);
		move(make_pair(bottomI, 1), make_pair(bottomI, c - 1), RIGHT);

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
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << room[i][j] << '\t';
			}
			cout << endl;
		}
		cout << endl;
	}

	int getDust() {
		int sum = 0;
		for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
			if (room[i][j] > 0) sum += room[i][j];
		}
		return sum;
	}
};

int main(void) {
	sws;
	int R, C, T;
	cin >> R >> C >> T;
	int room[50][50];
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> room[i][j];

	AirCleaner ac(room, R, C);
	
	for (int t = 0; t < T; t++) {
		ac.spreadDust();
		ac.removeDust();
	}
	
	cout << ac.getDust() << '\n';
	return 0;
}
