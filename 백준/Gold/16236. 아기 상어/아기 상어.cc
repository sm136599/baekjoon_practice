#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int N, M;
vector<vector<int>> ocean;
//vector<vector<pair<int, int>>> fish(7);
map<int, int> fish;
int curI, curJ; 
int sharkSize = 2;
int eatCnt = 0;
int di[]{ -1, 0, 0, 1 };
int dj[]{ 0, -1, 1, 0 };

int findNearestFish() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	pq.push(make_pair(0, make_pair(curI, curJ)));
	visited[curI][curJ] = true;
	while (!pq.empty()) {
		int i = pq.top().second.first;
		int j = pq.top().second.second;
		int dist = pq.top().first;
		pq.pop();
		//cout << i << " " << j << " " << dist << " " << endl;
		if (ocean[i][j] != 0 && ocean[i][j] != 9 && ocean[i][j] < sharkSize) {
			fish[ocean[i][j]]--;
			ocean[curI][curJ] = 0;
			curI = i; curJ = j;
			ocean[curI][curJ] = 9;
			return dist;
		}
		for (int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if (!(0 <= ni && ni < N && 0 <= nj && nj < N)) continue;
			if (visited[ni][nj]) continue;
			if (ocean[ni][nj] <= sharkSize) {
				visited[ni][nj] = true;
				pq.push(make_pair(dist + 1, make_pair(ni, nj)));
			}
		}
	}
	
	return -1;
}

int countCanEat() {
	int cnt = 0;
	for (int i = 1; i < 7; i++) {
		if (i >= sharkSize) break;
		cnt += fish[i];
	}
	return cnt;
}

int main(void) {
	sws;
	cin >> N;
	ocean = vector<vector<int>>(N, vector<int>(N));
	for (int i = 1; i < 7; i++) fish[i] = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int n; cin >> n;
			ocean[i][j] = n;
			if (n == 9) {
				curI = i; curJ = j;
			}
			else if (n != 0) {
				fish[n]++;
			}
		}
	int time = 0;
	while (true) {
		if (!countCanEat()) break;
		auto eat = findNearestFish();
		if (eat == -1) break;
		eatCnt++;
		if (sharkSize == eatCnt) {
			sharkSize++;
			eatCnt = 0;
		}

		time += eat;
	}
	cout << time << endl;

	return 0;
}