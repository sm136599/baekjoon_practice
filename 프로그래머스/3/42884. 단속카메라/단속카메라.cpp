#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int maxx = routes[0][1];
    for (auto r : routes) {
        if (r[0] > maxx) {
            answer++;
            maxx = r[1];
        }
        maxx = min(maxx, r[1]);
    }
    return answer;
}