import sys
def Input_Data():
    readl = sys.stdin.readline
    T = int(readl())
    TC = []
    N = []
    for _ in range(T):
        N.append(int(readl()))
        TC.append([list(map(int, readl().split())) for _ in range(2)])
    return T, TC, N

T, TC, N = Input_Data() 

for i in range(T):
    n = N[i]
    stickers0 = TC[i][0]
    stickers1 = TC[i][1]
    
    dp0 = [0] * n
    dp1 = [0] * n
    dp0[0] = stickers0[0]
    dp1[0] = stickers1[0]
    for j in range(1, n):
        dp0[j] = max(dp1[j-1] + stickers0[j], dp0[j-1])
        dp1[j] = max(dp0[j-1] + stickers1[j], dp1[j-1])

    print(max(dp0[n-1], dp1[n-1]))