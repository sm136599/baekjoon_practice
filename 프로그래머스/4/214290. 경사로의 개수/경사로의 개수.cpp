#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define MOD 1000000007

typedef long long ll;

vector<vector<int>> index;
vector<vector<ll>> matrix;
int n, m;

int di[]{0, 0, 1, -1};
int dj[]{1, -1, 0, 0};

vector<vector<ll>> mmul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    int N = a.size();
    vector<vector<ll>> ret(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return ret;
}

vector<vector<ll>> matrix_power(vector<vector<ll>> matrix, long long k) {
	int N = matrix.size();
    vector<vector<ll>> res(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        res[i][i] = 1;
    }
    while (k > 0) {
        if (k % 2 == 1) {
            res = mmul(res, matrix);
        }
        matrix = mmul(matrix, matrix);
        k /= 2;
    }
    return res;
}

int solution(vector<vector<int>> grid, vector<int> d, int k) {
    n = grid.size();
    m = grid[0].size();
    int N = n*m;
    index = vector<vector<int>>(n, vector<int>(m));
    matrix = vector<vector<ll>>(N, vector<ll>(N));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            index[i][j] = i * m + j;
        }
    }
    
    vector<vector<vector<vector<vector<ll>>>>> dp(d.size() + 1, 
                        vector<vector<vector<vector<ll>>>>(n, 
                                vector<vector<vector<ll>>>(m,
                                        vector<vector<ll>>(n,
                                                vector<ll>(m, 0)))));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int diff = d[0];
            for (int l = 0; l < 4; l++) {
                int ni = i + di[l];
                int nj = j + dj[l];
                if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                    if (grid[ni][nj] - grid[i][j] == diff)
                        dp[1][ni][nj][i][j] += 1;
                }
            }
        }
    }
    
    for (int k = 2; k <= d.size(); k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diff = d[k-1];
                for (int l = 0; l < 4; l++) {
                    int ni = i + di[l];
                    int nj = j + dj[l];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                        if (grid[ni][nj] - grid[i][j] == diff) {
                            for (int a = 0; a < n; a++) {
                                for (int b = 0; b < m; b++) {
                                    dp[k][ni][nj][a][b] = (dp[k][ni][nj][a][b]+dp[k-1][i][j][a][b]) % MOD;
                                }
                            }
                        }
                    }
                }
                
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < m; b++) {
                    matrix[index[a][b]][index[i][j]] = (matrix[index[a][b]][index[i][j]]+dp[d.size()][i][j][a][b]) % MOD;
                }
            }
        }
    }
    
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    vector<vector<ll>> temp = matrix_power(matrix, k);
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer = (answer + temp[i][j]) % MOD;
        }
    }
    
    return answer;
}