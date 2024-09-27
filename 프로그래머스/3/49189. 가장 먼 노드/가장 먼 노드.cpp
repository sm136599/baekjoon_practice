#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    graph = vector<vector<int>>(n+1);
    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    queue<pair<int, int>> q;
    vector<bool> visited(n+1);
    q.push(make_pair(1, 0));
    visited[1] = true;
    int mDist = 0;
    while (!q.empty()) {
        int cur = q.front().first,
            dist = q.front().second;
        q.pop();
        if (mDist == dist) {
            answer++;
        }
        else if (mDist < dist) {
            answer = 1;
            mDist = dist;
        }
        for (int n : graph[cur]) {
            if (visited[n]) continue;
            visited[n] = true;
            q.push(make_pair(n, dist+1));
        }
    }
    
    return answer;
}