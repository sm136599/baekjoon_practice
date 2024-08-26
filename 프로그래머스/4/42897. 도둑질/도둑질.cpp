#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> money) {
    int answer,
    	answer1 = 0,
    	answer2 = 0;
    int n = money.size();
    vector<int> dp1(money.size()), dp2(money.size());
    dp1[0] = money[0];
    dp2[1] = money[1];
    for (int i = 2; i < n; i++) {
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    dp1[n-1] = max(dp1[n-2], dp1[n-3]);
    answer1 = max(dp1[n - 1], dp2[n - 1]);
    
    dp1 = vector<int>(money.size());
    dp2 = vector<int>(money.size());
    dp1[n-1] = money[n-1];
    dp1[n-2] = money[n-2];
    for (int i = n-3; i >= 0; i--) {
        dp1[i] = max(dp1[i+2] + money[i], dp1[i+1]);
        dp2[i] = max(dp2[i+2] + money[i], dp2[i+1]);
    }
    dp1[0] = max(dp1[1], dp1[2]);
    answer2 = max(dp1[0], dp2[0]);
    answer = max(answer1, answer2);
    return answer;
}