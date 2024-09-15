#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)
int N, M; 
vector<pair<int, pair<int, int>>> edge;
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
	edge = vector<pair<int, pair<int, int>>>(M);
	parent = vector<int>(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[i] = make_pair(c, make_pair(a, b));
	}
	sort(edge.begin(), edge.end());
	for (int i = 1; i <= N; i++) parent[i] = i;
	int answer = 0, count = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		a = edge[i].second.first;
		b = edge[i].second.second;
		c = edge[i].first;
		
		if (count == N - 2) break;
		if (union_find(a, b)) {
			answer += c;
			count++;
		}
	}
	cout << answer << endl;

	return 0;
}