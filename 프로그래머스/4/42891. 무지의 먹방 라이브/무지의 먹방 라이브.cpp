#include <string>
#include <vector>
#include <algorithm>

#define IDX second
#define VAL first

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    int n = food_times.size();
    
    vector<pair<int, int>> food_times_index(n);
    for (int i = 0; i < n; i++) {
        food_times_index[i] = make_pair(food_times[i], i);
    }
    sort(food_times_index.begin(), food_times_index.end());
    
    long long stack = 0;
    for (int i = 0; i < n; i++) {
        long long temp = (n - i) * (food_times_index[i].VAL - stack);
        k -= temp;
        if (k < 0) {
            k += temp;
            sort(food_times_index.begin() + i, food_times_index.end(), 
                 [](const pair<int, int>& a, const pair<int, int>& b) {
                     return a.IDX < b.IDX;
                 });
            k %= (n - i);
            answer = food_times_index[i+k].IDX + 1;
            break;
        }
        stack = food_times_index[i].VAL;
    }
    return answer;
}