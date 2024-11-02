#include <queue>
#include <tuple>
#define MAX 2000000000
#define price(a, b) (((a)*500) + ((b)*100))
using namespace std;

int di[]{1, 0, -1, 0};
int dj[]{0, 1, 0, -1};

int solution(vector<vector<int>> board) {
    int answer = MAX;
    int N = board.size();
    // 코너 개수, 직선 개수, 방향, i, j
    queue<tuple<int, int, int, int, int>> q;
    vector<vector<vector<int>>> costs(4, vector<vector<int>>(N, vector<int>(N, MAX)));
    q.emplace(0, 0, -1, 0, 0);
    while(!q.empty()) {
        auto [corners, straights, dir, ci, cj] = q.front();
        q.pop();
        
        int cost = price(corners, straights);
        if (cost >= answer) continue;
        if (ci == N - 1 && cj == N - 1) {
            answer = min(answer, cost);
            continue;
        }
        
        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k],
                nj = cj + dj[k];
            if (!(0 <= ni && ni < N && 0 <= nj && nj < N)) continue;
            if (board[ni][nj]) continue;
            if (dir == -1) {
                q.emplace(0, 1, k, ni, nj);
                costs[k][ni][nj] = 100;
                continue;
            }
            if ((dir + 2) % 4 == k) continue;
            
            int n_cost = price(corners + ((dir == k)?0:1), straights + 1);
            
            if (n_cost < costs[k][ni][nj]) {
                costs[k][ni][nj] = n_cost;
                q.emplace(corners + ((dir == k)?0:1), straights + 1, k, ni, nj);
            }
        }
    }
    return answer;
}