#include "bits/stdc++.h"
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PII pair<int, int>
#define DIST first
#define NODE second
#define MAX 2000000000

int N, E, v1, v2;
vector<vector<PII>> graph;

int dijkstra(int start, int end) {
	vector<int> dist(N + 1, MAX);
	dist[start] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int distance = pq.top().DIST;
		int cur = pq.top().NODE;
		pq.pop();
		if (dist[cur] < distance) continue;
		for (auto next : graph[cur]) {
			if (dist[next.NODE] > distance + next.DIST) {
				dist[next.NODE] = distance + next.DIST;
				pq.push(make_pair(distance + next.DIST, next.NODE));
			}
		}
	}
	if (dist[end] >= MAX) return -1;
	else return dist[end];
}

int main(void) {
	sws;
	cin >> N >> E;
	graph = vector<vector<PII>>(N + 1);
	for (int i = 1; i <= E; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(make_pair(c, b));
		graph[b].emplace_back(make_pair(c, a));
	}
	cin >> v1 >> v2;

	int answer1 = 0, d;
	int answer2 = 0;
	if ((d = dijkstra(1, v1)) == -1) {
		cout << -1 << endl;
		return 0;
	}
	answer1 += d;
	if ((d = dijkstra(v1, v2)) == -1) {
		cout << -1 << endl; return 0;
	}
	answer1 += d;
	if ((d = dijkstra(v2, N)) == -1) {
		cout << -1 << endl;
		return 0;
	}
	answer1 += d;

	if ((d = dijkstra(1, v2)) == -1) {
		cout << -1 << endl;
		return 0;
	}
	answer2 += d;
	if ((d = dijkstra(v2, v1)) == -1) {
		cout << -1 << endl; return 0;
	}
	answer2 += d;
	if ((d = dijkstra(v1, N)) == -1) {
		cout << -1 << endl;
		return 0;
	}
	answer2 += d;


	cout << min(answer1, answer2) << endl;
	return 0;
}