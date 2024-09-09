#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000000;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < roads.size(); i++) {
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);
    }
    vector<int> dist(n+1, MAX);
    vector<bool> visited(n+1, false);
    queue<pair<int, int>> q;
    q.push(make_pair(destination, 0));
    visited[destination] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();
        dist[cur] = d;
        
        for (int next : graph[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(make_pair(next, d+1));
        }
    }
    
    for (int source: sources) {
        if (dist[source] >= MAX) answer.push_back(-1);
        else answer.push_back(dist[source]);
    }
    
    return answer;
}