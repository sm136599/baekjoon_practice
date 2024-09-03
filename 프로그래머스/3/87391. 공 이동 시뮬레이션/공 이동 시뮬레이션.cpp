#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int di[]{0, 0, 1, -1};
int dj[]{1, -1, 0, 0};
typedef long long ll;
long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    int x1 = x, x2 = x;
    int y1 = y, y2 = y;
    
    for (int i = queries.size() - 1; i >= 0; i--) {
        int cmd = queries[i][0], dx = queries[i][1];
        switch(cmd) {
            case 0:
                if (y1 == 0) {
                    y2 += dj[cmd] * dx;
                }
                else {
                    y1 += dj[cmd] * dx;
                    y2 += dj[cmd] * dx;
                }
                if (y1 >= m) return 0;
                if (y2 >= m) y2 = m - 1;
                break;
            case 1:
                if (y2 == m - 1) {
                    y1 += dj[cmd] * dx;
                }
                else {
                    y1 += dj[cmd] * dx;
                    y2 += dj[cmd] * dx;
                }
                if (y2 < 0) return 0;
                if (y1 < 0) y1 = 0;
                break;
            case 2:
                if (x1 == 0) {
                    x2 += di[cmd] * dx;
                }
                else {
                    x1 += di[cmd] * dx;
                    x2 += di[cmd] * dx;
                }
                if (x1 >= n) return 0;
                if (x2 >= n) x2 = n - 1;
                break;
            case 3:
                if (x2 == n - 1) {
                    x1 += di[cmd] * dx;
                }
                else {
                    x1 += di[cmd] * dx;
                    x2 += di[cmd] * dx;
                }
                if (x2 < 0) return 0;
                if (x1 < 0) x1 = 0;
                break;
        }
    }
    answer = ((ll)x2 - (ll)x1 + 1) * ((ll)y2 - (ll)y1 + 1);
    return answer;
}