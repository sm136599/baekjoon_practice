#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> sum;

int getSum(int start, int end) {
    if (start == 0) return sum[end];
    return sum[end] - sum[start - 1];
}

int solution(vector<int> cookie) {
    int answer = 0;
    int N = cookie.size();
    int l = 0, m, r = cookie.size() - 1;
    sum = vector<int>(N);
    sum[0] = cookie[0];
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + cookie[i];
    }
    
    for (l = 0; l < N; l++) {
        for (r = N - 1; r > l; r--) {
            if (answer > getSum(l, r)) break;
            int ll = l, rr = r;
            while (ll <= rr) {
                int mm = (ll + rr) / 2;
                int left = getSum(l, mm);
                int right = getSum(mm + 1, r);
                if (left == right) {
                    answer = max(answer, left);
                    break;
                }
                if (left < right) {
                    ll = mm + 1;
                }
                else {
                    rr = mm - 1;
                }
            }
        }
    }
    
    return answer;
}