#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int N, answer = 0;
vector<bool> visited;
vector<bool> isEarlyAdopter;
vector<vector<int>> network;

bool findEarlyAdopter(int node) {
	visited[node] = true;

	bool isAllFriendsEarlyAdopter = true;
	for (auto& next : network[node]) {
		if (visited[next]) continue;
		isAllFriendsEarlyAdopter &= findEarlyAdopter(next);
	}
	if (isAllFriendsEarlyAdopter) isEarlyAdopter[node] = false;
	answer += isEarlyAdopter[node];
	return isEarlyAdopter[node];
}

int main(void) {
	sws;
	cin >> N;
	visited.resize(N);
	isEarlyAdopter.resize(N, true);
	network.resize(N);
	for (int i = 1; i < N; i++) {
		int u, v; cin >> u >> v;
		network[u - 1].push_back(v - 1);
		network[v - 1].push_back(u - 1);
	}

	findEarlyAdopter(0);
	cout << answer;

	return 0;
}