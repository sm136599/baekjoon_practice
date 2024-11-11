#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> graph(info.size());
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    int iter = 0;
    // 양 수, 늑대 수, 방문여부, 현재 노드
    // priority_queue<tuple<int, int, int, int>> pq;
    queue<tuple<int, int, int, int>> pq;
    pq.emplace(1, 0, 1, 0);
    while (!pq.empty()) {
        if (iter++ >= 30000000) break;
        auto [sheep, wolf, visited, cur] = pq.front();
        pq.pop();
        // cout << sheep << ' ' << wolf << ' ' << cur << ' ' << visited << '\n';
        answer = max(answer, sheep);
        for (auto next : graph[cur]) {
            int next_sheep = sheep + ((visited & (1 << next))?0:!info[next]);
            int next_wolf = wolf + ((visited & (1 << next))?0:info[next]);
            if (next_sheep <= next_wolf) continue;
            pq.emplace(next_sheep, next_wolf, visited | (1 << next), next);
        }
    }
    
    return answer;
}