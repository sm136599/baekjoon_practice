#include "bits/stdc++.h"
using namespace std;
#define sws cin.tie(NULL)->ios::sync_with_stdio(false)
#define MAX 100000000
typedef pair<int, int> pii;
vector<vector<pii>> graph;
int n, m;

void dijkstra(int start, int end) {
	priority_queue<pii, vector<pii>, greater<>> pq;
	vector<int> dist(n + 1, MAX);
	dist[start] = 0;
	vector<int> route(n + 1);
	int answer = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int curDist = pq.top().first,
			cur = pq.top().second;
		pq.pop();
		if (curDist > dist[cur]) continue;
		
		for (auto& next : graph[cur]) {
			int nextDist = next.second,
				nextN = next.first;
			if (curDist + nextDist < dist[nextN]) {
				dist[nextN] = curDist + nextDist;
				pq.push(make_pair(curDist + nextDist, nextN));
				route[nextN] = cur;
			}
		}
	}
	stack<int> st;
	int cur = end;
	while (cur) {
		st.push(cur);
		cur = route[cur];
	}
	cout << dist[end] << '\n';
	cout << st.size() << '\n';
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

}

int main(void) {
	sws;
	cin >> n >> m;
	graph = vector<vector<pii>>(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back(pii(b, c));
	}
	int A, B; cin >> A >> B;
	dijkstra(A, B);
	

	return 0;
}