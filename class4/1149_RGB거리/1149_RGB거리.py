import sys

def Input_Data():
    readl = sys.stdin.readline
    N = int(readl())
    color = [list(map(int, readl().split())) for _ in range(N)]
    return N, color

N, color = Input_Data()

dp = [[0] * 3 for _ in range(N)]
dp[0] = color[0]
for i in range(1, N):
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + color[i][0]
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + color[i][1]
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + color[i][2]

print(min(dp[N-1]))

