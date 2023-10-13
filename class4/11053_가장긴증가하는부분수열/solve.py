import sys
def Input_Data():
    readl = sys.stdin.readline
    N = int(readl())
    l = list(map(int, readl().split()))
    return N, l

N, l = Input_Data()

dp = [1 for _ in range(N)]

for i in range(1, N):
    for j in range(i):
        if l[i] > l[j]:
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))
