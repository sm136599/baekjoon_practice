#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int sheep_count = 0;
    for (int i : info) sheep_count += !i;
    vector<vector<int>> graph(info.size());
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    int iter = 0;
    vector<vector<vector<vector<bool>>>> visited_state(sheep_count+1, vector<vector<vector<bool>>>(info.size()-sheep_count+1, vector<vector<bool>>(info.size(), vector<bool>(1<<(info.size())))));
    // 양 수, 늑대 수, 방문여부, 현재 노드
    queue<tuple<int, int, int, int>> q;
    q.emplace(1, 0, 1, 0);
    while (!q.empty()) {
        if (sheep_count == answer) break;
        auto [sheep, wolf, visited, cur] = q.front();
        q.pop();
        answer = max(answer, sheep);
        for (auto next : graph[cur]) {
            int next_sheep = sheep + ((visited & (1 << next))?0:!info[next]);
            int next_wolf = wolf + ((visited & (1 << next))?0:info[next]);
            if (next_sheep <= next_wolf) continue;
            if (visited_state[next_sheep][next_wolf][next][visited | (1 << next)]) continue;
            visited_state[sheep][wolf][next][visited] = true;
            q.emplace(next_sheep, next_wolf, visited | (1 << next), next);
        }
    }
    
    return answer;
}