#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#define MAX 2147483147
#define price(a, b) (((a)*500) + ((b)*100))
using namespace std;

int di[]{1, 0, -1, 0};
int dj[]{0, 1, 0, -1};

int solution(vector<vector<int>> board) {
    int answer = MAX;
    int N = board.size();
    // 코너 개수, 직선 개수, 방향, i, j
    queue<tuple<int, int, int, int, int>> q;
    vector<vector<int>> value(N, vector<int>(N, MAX));
    q.emplace(0, 0, -1, 0, 0);
    while(!q.empty()) {
        int corner_cnt = -get<0>(q.front()),
            straight_cnt = -get<1>(q.front()),
            dir = get<2>(q.front()),
            ci = get<3>(q.front()),
            cj = get<4>(q.front());
        q.pop();
        
        value[ci][cj] = price(corner_cnt, straight_cnt);
        if (value[ci][cj] > answer) continue;
        // cout << corner_cnt << straight_cnt << dir << ci << cj << endl;
        if (ci == N - 1 && cj == N - 1) {
            if (answer > value[ci][cj]) {
                answer = value[ci][cj];
            }
        }
        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k],
                nj = cj + dj[k];
            if (!(0 <= ni && ni < N && 0 <= nj && nj < N)) continue;
            if (board[ni][nj]) continue;
            if (dir == -1) {
                q.emplace(0, -1, k, ni, nj);
            }
            else {
                if ((dir + 2) % 4 == k) continue;
                if (dir == k) {
                    if (value[ni][nj] + 400 < price(corner_cnt, straight_cnt+1)) continue;
                    value[ni][nj] = price(corner_cnt, straight_cnt+1);
                    q.emplace(-corner_cnt, -(straight_cnt + 1), k, ni, nj);
                }
                else {
                    if (value[ni][nj] + 400 < price(corner_cnt+1, straight_cnt+1)) continue;
                    value[ni][nj] = price(corner_cnt+1, straight_cnt+1);
                    q.emplace(-(corner_cnt + 1), -(straight_cnt + 1), k, ni, nj);
                }
            }
        }
    }
    return answer;
}