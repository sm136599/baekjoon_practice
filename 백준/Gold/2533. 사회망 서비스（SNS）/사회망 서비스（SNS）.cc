#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)

int N, answer = 0;
vector<char> visited;
vector<vector<int>> network;

int findEarlyAdopter(int node) {
	visited[node] = 1;

	int isAllFriendsEarlyAdopter = 1;
	for (auto& next : network[node]) {
		if (visited[next]) continue;
		isAllFriendsEarlyAdopter &= findEarlyAdopter(next);
	}
	answer += isAllFriendsEarlyAdopter ^ 1;
	return isAllFriendsEarlyAdopter ^ 1;
}

int main(void) {
	sws;
	cin >> N;
	visited.reserve(N);
	network.reserve(N);
	for (auto& v : network) v.reserve(N);
	for (int i = 1; i < N; i++) {
		int u, v; cin >> u >> v;
		network[u - 1].push_back(v - 1);
		network[v - 1].push_back(u - 1);
	}

	findEarlyAdopter(0);
	cout << answer;

	return 0;
}