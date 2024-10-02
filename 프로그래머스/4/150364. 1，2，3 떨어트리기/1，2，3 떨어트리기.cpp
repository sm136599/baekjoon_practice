#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int isValid(vector<int>& target, vector<int>& count) {
    /* return value
        1 : valid | 0 : not valid | -1 : not valid and no answer */
    int N = target.size();
    for (int i = 0; i < N; i++) {
        if (target[i] == 0) continue;
        if (count[i] > target[i]) return -1;
        else if (!(count[i] <= target[i] && target[i] <= 3*count[i])) return 0;
    }
    return 1;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    int N = target.size();
    sort(edges.begin(), edges.end());
    vector<deque<int>> tree(N);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0], v = edges[i][1];
        tree[u-1].push_back(v-1);
    }
    
    vector<int> check;
    vector<int> count(N);
    int n;
    // 트리 조회
    while (true) {
        n = 0;
        // leaf node 찾기
        while (true) {
            if (tree[n].empty()) {
                check.push_back(n);
                count[n]++;
                break;
            }
            int temp = tree[n].front();
            tree[n].push_back(temp);
            tree[n].pop_front();
            n = temp;
        }
        int result = isValid(target, count);
        if (result == 0) continue;
        else if (result == 1) {
            break;
        }
        else if (result == -1) {
            answer.push_back(-1);
            return answer;
        }
    }
    vector<vector<int>> rock(N);
    vector<int> idx(N);
    
    for (int i = 0; i < N; i++) {
        rock[i] = vector<int>(count[i], 1);
        vector<int>& tmp = rock[i];
        
        int c = count[i];
        while (c < target[i]) {
            for (int j = count[i] - 1; j >= 0; j--) {
                while (tmp[j] < 3) {
                    tmp[j]++;
                    c++;
                    if (c == target[i]) break;
                }
                if (c == target[i]) break;
            }
        }
    }
    
    for (int i = 0; i < check.size(); i++) {
        answer.push_back(rock[check[i]][idx[check[i]]++]);
    }
    
    return answer;
}