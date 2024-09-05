#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int n = scores.size();
    
    for (int i = 1; i < n; i++) {
        if (scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) {
            return -1;
        }
    }
    
    
    int target = scores[0][0] + scores[0][1];
    sort(scores.begin(), scores.end());
    for (int i = 0; i < n; i++) {
        if (target >= scores[i][0] + scores[i][1]) continue;
        
        bool canGetInsentive = true;
        for (int j = n-1; j > i; j--) {
            if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]) {
                canGetInsentive = false;
                break;
            }
            if (scores[i][0] == scores[j][0]) break;
        }
        if (canGetInsentive) {
            if (target < scores[i][0] + scores[i][1]) {
                answer++;
            }
        }
    }
    return answer;
}
