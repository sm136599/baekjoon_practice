#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int getIncentive = true;
    int n = scores.size();
    int target = scores[0][0] + scores[0][1];
    for (int i = 1; i < n; i++) {
        if (scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) {
            return -1;
        }
    }
    sort(scores.begin(), scores.end());
    for (int i = 0; i < n; i++) {
        if (target >= scores[i][0] + scores[i][1]) continue;
        bool flag = true;
        for (int j = n-1; j > i; j--) {
            if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]) {
                flag = false;
                break;
            }
            if (scores[i][0] == scores[j][0]) break;
        }
        if (flag) {
            if (target < scores[i][0] + scores[i][1]) {
                answer++;
            }
        }
    }
    return answer;
}