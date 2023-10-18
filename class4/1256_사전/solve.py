import sys
from collections import deque

readl = sys.stdin.readline
N, M, K = map(int, readl().split())

answer = -1
comb = [[0]*(N+M+1) for _ in range(N+M + 1)]
for i in range(1, N+M+1):
    comb[i][1] = i
    comb[i][i] = 1

for i in range(2, N+M+1):
    for j in range(2, i):
        comb[i][j] = comb[i-1][j-1] + comb[i-1][j]

total_words = comb[N+M][N]

if K > total_words:
    print(-1)
else:
    n, m, k = N, M, K
    s = ''
    while n or m:
        if total_words * n // (n+m) >= k and n >= 0:
            s += 'a'
            total_words = total_words * n // (n+m)
            n -= 1
        elif total_words * n // (n+m) < k  and m >= 0:
            s += 'z'
            k -= total_words * n // (n+m)
            total_words = total_words * m // (n+m)
            m -= 1
        
    print(s)
