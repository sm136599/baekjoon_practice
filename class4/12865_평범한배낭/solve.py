import sys

readl = sys.stdin.readline
N, K = map(int, readl().split())
luggage = [list(map(int, readl().split())) for _ in range(N)]
luggage = [[0, 0]] + luggage

dp = [[0] * (K+1) for _ in range(N + 1)]

for i in range(N+1):
    w = luggage[i][0]
    v = luggage[i][1]
    for j in range(K+1):

        if j < w:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(v + dp[i-1][j-w], dp[i-1][j])

# print(*dp, sep='\n')
print(dp[-1][-1])

### 다시보기 