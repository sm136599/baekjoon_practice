#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

vector<int> parent;
vector<int> new_parent;
vector<vector<int>> query;

int find_parent(int node) {
	if (new_parent[node] == node) return node;
	return new_parent[node] = find_parent(new_parent[node]);
}

void uni(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	new_parent[b] = a;
}

int main(void) {
	sws;
	int n, q; cin >> n >> q;
	parent.resize(n + 1);
	new_parent.resize(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		cin >> parent[i];
		new_parent[i] = i;
	}

	q += n - 1;
	while (q--) {
		int c; cin >> c;
		if (c) {
			int v, w; cin >> v >> w;
			query.push_back({ c, v, w });
		}
		else {
			int v; cin >> v;
			query.push_back({ c,v });
		}
	}
	
	vector<bool> answer;
	for (auto it = query.rbegin(); it != query.rend(); it++) {
		if ((*it)[0]) {
			answer.push_back(find_parent((*it)[1]) == find_parent((*it)[2]));
		}
		else {
			uni((*it)[1], parent[(*it)[1]]);
		}
	}
	for (auto it = answer.rbegin(); it != answer.rend(); it++) {
		cout << ((*it) ? "YES\n" : "NO\n");
	}

	return 0;
}