import sys
def Input_Data():
    readl = sys.stdin.readline
    N, M = map(int, readl().split())
    matrix = [[0] + list(map(int, readl().split())) if 1 <= n <= N else [0] * (N+1) for n in range(N + 1)]
    points = [list(map(int, readl().split())) for _ in range(M)]
    return N, M, matrix, points

N, M, matrix, points = Input_Data()

dp = [[0] * (N+1) for _ in range(N+1)]
for i in range(1, N+1):
    for j in range(1, N+1):
        dp[i][j] = matrix[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]

for x1, y1, x2, y2 in points:
    print(dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1])
