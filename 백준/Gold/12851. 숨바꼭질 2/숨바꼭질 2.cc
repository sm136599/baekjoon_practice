#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int N, K;

struct compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first) return abs(K - a.second) > abs(K - b.second);
		return a.first > b.first;
	}
};

int main(void) {
	sws;

	cin >> N >> K;

	if (N >= K) {
		cout << N - K << endl << 1;
		return 0;
	}

	int answer = 100000, answerCnt = 0;
	vector<int> visitTime(100001, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	pq.push(make_pair(0, N));
	visitTime[N] = 0;
	while (!pq.empty()) {
		int time = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cur == K) {
			answerCnt++;
			answer = time;
			continue;
		}

		if (time > visitTime[cur]) continue;

		if (cur - 1 >= 0) {
			if (answer > time) {
				if (visitTime[cur - 1] == -1) visitTime[cur - 1] = time + 1;
				pq.push(make_pair(time + 1, cur - 1));
			}
		}

		if (cur + 1 <= 100000) {
			if (answer > time) {
				if (visitTime[cur + 1] == - 1) visitTime[cur + 1] = time + 1;
				pq.push(make_pair(time + 1, cur + 1));
			}
		}

		if (cur * 2 <= 100000) {
			if (answer > time) {
				if (visitTime[cur * 2] == -1) visitTime[cur * 2] = time + 1;
				pq.push(make_pair(time + 1, cur * 2));
			}
		}
	}
	cout << answer << endl << answerCnt << endl;

	return 0;
}