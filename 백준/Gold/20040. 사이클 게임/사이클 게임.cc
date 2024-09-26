#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

vector<int> parent;

int find_parent(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find_parent(parent[a]);
}

bool is_cycle(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);

	if (a == b) return true;
	else {
		parent[a] = b;
		return false;
	}
}


int main(void) {
	sws;

	int n, m; cin >> n >> m;
	int answer = 0;
	for (int i = 0; i < n; i++) parent.push_back(i);
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		if (is_cycle(a, b)) {
			answer = i;
			break;
		}
	}
	cout << answer << '\n';
	
	return 0;
}