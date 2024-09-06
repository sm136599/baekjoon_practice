#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        if (city_map[i-1][0] == 1) break;
        dp[i][1] = 1;
    }
    for (int j = 1; j <= n; j++) {
        if (city_map[0][j-1] == 1) break;
        dp[1][j] = 1;
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            int curi1 = i - 1, curj1 = j - 1;
            if (city_map[curi1][curj1] == 1) continue;
            if (city_map[curi1][curj1-1] == 2) {
                while (curj1 > 0 && city_map[curi1][curj1 - 1] == 2) curj1--;
            }
            int curi2 = i - 1, curj2 = j - 1;
            if (city_map[curi2-1][curj2] == 2) {
                while (curi2 > 0 && city_map[curi2 - 1][curj2] == 2) curi2--;
            }
            
            dp[i][j] = (dp[curi2][j] + dp[i][curj1]) % MOD;
        }
    }
    
    return dp[m][n];
}