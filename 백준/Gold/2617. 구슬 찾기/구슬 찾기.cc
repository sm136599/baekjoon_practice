#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int n, m;
int answer = 0;
void get(vector<vector<int>>& target) {
	for (int i = 1; i <= n; i++) {
		vector<bool>visited(n + 1, false);
		visited[i] = true;
		queue<int> q;
		q.push(i);
		int cnt = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : target[cur]) {
				if (visited[next]) continue;
				visited[next] = true;
				cnt++;
				q.push(next);
			}
		}
		if (cnt > n / 2) answer++;
	}
}

int main(void) {
	sws;
	cin >> n >> m;
	vector<vector<int>> bigger(n + 1);
	vector<vector<int>> smaller(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		bigger[b].push_back(a);
		smaller[a].push_back(b);
	}
	get(smaller);
	get(bigger);
	cout << answer << '\n';
	return 0;
}