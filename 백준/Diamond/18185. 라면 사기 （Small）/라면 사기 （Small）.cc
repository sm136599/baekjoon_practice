#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int N;
vector<int> factory;
int answer = 0;

int count(int idx) {
	int cnt = 0;
	if (factory[idx] > 0) cnt++;
	else return cnt;

	if (idx + 1 < N && factory[idx + 1] >= factory[idx]) cnt++;
	else return cnt;

	if (idx + 2 < N && factory[idx + 2] >= factory[idx+1]) cnt++;
	else return cnt;
	return cnt;
}

int main(void) {
	sws;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		factory.push_back(n);
	}

	for (int i = 0; i < N; i++) {
		
		while (true) {
			int cnt = count(i);
			if (cnt == 0) break;
			int buy = factory[i];
		
			if (cnt == 1) {
				if (i + 1 < N) buy = factory[i] - factory[i + 1];
				answer += 3 * buy;
			}
			else if (cnt == 2) {
				if (i + 2 < N) buy = factory[i + 1] - factory[i + 2];
				if (buy > factory[i]) buy = factory[i];
				answer += 5 * buy;
			}
			else if (cnt == 3) {
				answer += 7 * buy;
			}

			for (int j = 0; j < cnt; j++) {
				factory[i + j] -= buy;
			}

			
		}
	}
	cout << answer << endl;

	return 0;
}