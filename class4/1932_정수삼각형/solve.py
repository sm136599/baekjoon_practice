import sys
def Input_Data():
    readl = sys.stdin.readline
    N = int(readl())
    input = [list(map(int, readl().split())) for _ in range(N)]
    return N, input

N, input = Input_Data()

dp = [[0] * len(input[i]) for i in range(N)]
dp[0][0] = input[0][0]
for i in range(1, N):
    for j in range(i+1):
        if j - 1 < 0:
            dp[i][j] = dp[i-1][j] + input[i][j]
        elif j >= i:
            dp[i][j] = dp[i-1][j-1] + input[i][j]
        else:
            dp[i][j] = max(dp[i-1][j] + input[i][j], dp[i-1][j-1] + input[i][j])

print(max(dp[N-1]))