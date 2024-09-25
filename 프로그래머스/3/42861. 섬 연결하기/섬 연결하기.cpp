#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find_parent(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find_parent(parent[a]);
}

bool union_find(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) {
        return false;
    }
    parent[a] = b;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    parent = vector<int>(n+1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){ return a[2] < b[2]; });
    int count = 0;
    for (int i = 0; i < costs.size(); i++) {
        if (count == n - 1) {
            break;
        }
        if (union_find(costs[i][0], costs[i][1])) {
            answer += costs[i][2];
            count++;
        }
    }
    return answer;
}