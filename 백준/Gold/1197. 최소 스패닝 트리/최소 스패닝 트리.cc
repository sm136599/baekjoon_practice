#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

vector<int> group;

int find_group(int node) {
	if (group[node] == node) return node;
	return (group[node] = find_group(group[node]));
}

bool union_group(int a, int b) {
	a = find_group(a);
	b = find_group(b);

	if (a != b) {
		group[b] = a;
		return true;
	}
	return false;
}

int main(void) {
	sws;
	int V, E; cin >> V >> E;
	priority_queue<tuple<int, int, int>> pq;
	for (int i = 0; i < E; i++) {
		int v, w, weight; cin >> v >> w >> weight;
		pq.emplace(-weight , v - 1, w - 1);
	}
	group.resize(V);
	for (int i = 0; i < V; i++) group[i] = i;

	int connect = 0, answer = 0;
	while (connect != V - 1) {
		auto [weight, v, w] = pq.top(); pq.pop();
		if (union_group(v, w)) {
			connect++;
			answer -= weight;
		}
	}
	cout << answer;

	return 0;
}