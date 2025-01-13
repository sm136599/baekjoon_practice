#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

vector<int> parent;
vector<int> p;
vector<vector<int>> children;

string is_same_parent(int v, int w) {
	return (parent[v] == parent[w]) ? "YES" : "NO";
}

void update_parent(int node, int p) {
	parent[node] = p;
	for (auto child : children[node]) {
		update_parent(child, p);
	}
}

void remove_child(int parent, int child) {
	for (auto it = children[parent].begin(); it != children[parent].end(); it++) {
		if (*it == child) {
			children[parent].erase(it);
			break;
		}
	}
}

int main(void) {
	sws;
	int n, q; cin >> n >> q;
	parent.resize(n + 1, 1);
	p.resize(n + 1);
	children.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		children[p[i]].push_back(i);
	}
	q += n - 1;
	while (q--) {
		int c; cin >> c;
		if (c) {
			int v, w; cin >> v >> w;
			cout << is_same_parent(v, w) << '\n';
		}
		else {
			int v; cin >> v;
			remove_child(p[v], v);
			update_parent(v, v);
		}
	}

	return 0;
}