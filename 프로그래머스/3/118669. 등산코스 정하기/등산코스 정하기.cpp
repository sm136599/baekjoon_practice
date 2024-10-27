#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<tuple<int, int>>> graph;
vector<bool> isGate;
vector<bool> isSummit;
vector<bool> visited;
vector<int> answer;
bool found = false;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    graph.resize(n + 1);
    for (auto& path : paths) {
        graph[path[0]].emplace_back(path[1], path[2]);
        graph[path[1]].emplace_back(path[0], path[2]);
    }
    isGate.resize(n + 1, false);
    isSummit.resize(n + 1, false);
    answer.resize(2, 10000001);
    
    for (auto& gate : gates) isGate[gate] = true;
    for (auto& summit : summits) isSummit[summit] = true;
    
    sort(summits.begin(), summits.end());
    
    for (auto& summit : summits) {
        visited.clear();
        visited.resize(n + 1, false);
        // intensity, curNode
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
        pq.emplace(0, summit);
        while (!pq.empty()) {
            int curNode = get<1>(pq.top());
            int intensity = get<0>(pq.top());
            pq.pop();
            visited[curNode] = true;
            
            if (intensity >= answer[1]) continue;
            
            if (isSummit[curNode] && summit != curNode) continue;
            
            if (isGate[curNode]) {
                if (answer[1] > intensity) {
                    answer[0] = summit;
                    answer[1] = intensity;
                }
                continue;
            }
            
            for (auto& next : graph[curNode]) {
                int nextNode = get<0>(next);
                int weight = get<1>(next);
                if (visited[nextNode]) continue;
                if (weight >= answer[1]) continue;
                pq.emplace(max(intensity, weight), nextNode);
            }
        }
    }
    
    return answer;
}