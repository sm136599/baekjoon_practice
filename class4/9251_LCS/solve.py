import sys

readl = sys.stdin.readline
s1 = str(readl())
s2 = str(readl())

s1 = s1.strip()
s2 = s2.strip()

dp = [[0] * (len(s1) + 1) for _ in range(len(s2) + 1)]

for i in range(1, len(s2) + 1):
    for j in range(1, len(s1) + 1):
        dp[i][j] = max(max(dp[i-1][j-1] + (1 if s1[j-1] == s2[i-1] else 0), dp[i-1][j]), dp[i][j-1]) 

print(*dp, sep='\n')
print(dp[len(s2)][len(s1)])