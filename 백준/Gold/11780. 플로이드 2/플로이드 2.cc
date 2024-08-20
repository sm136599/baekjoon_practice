#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)
#define MAX 100000000
vector<vector<int>> dist;
vector<vector<int>> mid;
void getRoute(vector<int>& midd, int start, int end) {
	if (start == end) return;
	if (dist[start][end] == MAX) return;
	if (mid[start][end] == 0) {
		if (midd.empty()) midd.push_back(start);
		midd.push_back(end);
	}
	else {
		getRoute(midd, start, mid[start][end]);
		getRoute(midd, mid[start][end], end);
	}
}

int main(void) {
	sws;

	int n, m; cin >> n >> m;
	dist = vector<vector<int>>(n + 1, vector<int>(n + 1, MAX));
	mid = vector<vector<int>>(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					mid[i][j] = k;
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == MAX)	cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << '\n';
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<int> midd;
			getRoute(midd, i, j);
			cout << midd.size() << " ";
			for (auto m : midd)  cout << m << " ";
			cout << '\n'; 
		}
	}


	return 0;
}