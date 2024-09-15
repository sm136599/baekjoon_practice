#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)
int N, M; 
vector<vector<pair<int, int>>> edge;
vector<int> parent;

int find_root(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find_root(parent[a]);
}

bool union_find(int a, int b) {
	a = find_root(a);
	b = find_root(b);

	if (a != b) {
		parent[b] = a;
		return true;
	}
	return false;
}

int main(void) {
	sws;
	cin >> N >> M;
	edge = vector<vector<pair<int, int>>>(1001);
	parent = vector<int>(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[c].push_back(make_pair(a, b));
	}
	for (int i = 1; i <= N; i++) parent[i] = i;
	int answer = 0, count = 0;
	for (int i = 1; i <= 1000; i++) {
		if (edge[i].empty()) continue;
		for (auto p : edge[i]) {
			if (count == N - 2) {
				cout << answer << endl;
				return 0;
			}
			int a = p.first,
				b = p.second;
			if (union_find(a, b)) {
				answer += i;
				count++;
			}
		}
	}

	return 0;
}