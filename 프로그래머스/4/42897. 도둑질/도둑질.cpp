#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> money) {
    int answer;
    int n = money.size();
    vector<int> dp1(money.size()), dp2(money.size());
    dp1[0] = money[0]; dp1[1] = money[0];
    dp2[1] = money[1];
    for (int i = 2; i < n; i++) {
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
        dp2[i] = max(dp2[i-1] + money[i], dp2[i-1]);
    }
    dp1[n-1] = dp1[n-2];
    answer = max(dp1[n - 1], dp2[n - 1]);
    return answer;
}
