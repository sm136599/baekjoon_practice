#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int N = rocks.size();
    if (N == n) return distance;
    sort(rocks.begin(), rocks.end());
    int l = 0, r = distance;
    while (l <= r) {
        int cnt = 0;
        int mid = (l + r) / 2;
        int start = 0,
            end = mid;
        
        for (int i = 0; i < N; i++) {
            if (start < rocks[i] && rocks[i] < end) {
                cnt++;
            }
            else {
                start = rocks[i];
                end = rocks[i] + mid;
                if (end > distance) cnt++;
            }
        }
        if (cnt > n) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
            answer = mid;
        }
    }
        
    return answer;
}