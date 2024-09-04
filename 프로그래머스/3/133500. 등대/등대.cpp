#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
bool isLeaf(vector<vector<int>>& graph, vector<bool>& visited, int cur) {
    int cnt = 0;
    for (auto n : graph[cur]) {
        if (visited[n]) continue;
        cnt++;
    }
    return cnt == 0;
}
int dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur) {
    if (isLeaf(graph, visited, cur)) {
        return 1;
    }
    int result = 0;
    for(auto n : graph[cur]) {
        if (visited[n]) continue;
        visited[n] = true;
        result += dfs(graph, visited, n);
    }
    if (result > 0) {
        answer++;
        return 0;
    }
    return 1;
}
int solution(int n, vector<vector<int>> lighthouse) {
    vector<vector<int>> graph(n+1);
    for (auto p : lighthouse) {
        graph[p[0]].push_back(p[1]);
        graph[p[1]].push_back(p[0]);
    }
    vector<bool> visited(n+1, false);
    visited[1] = true;
    dfs(graph, visited, 1);
    return answer;
}