import sys

readl = sys.stdin.readline
N = int(readl())

dp_max = [[0] * 3 for _ in range(2)]
dp_min = [[0] * 3 for _ in range(2)]

a, b, c = list(map(int, readl().split()))
dp_max[0] = [a, b, c]
dp_min[0] = [a, b, c]

for i in range(1, N):
    matrix = list(map(int, readl().split()))
    for j in range(3):
        if j == 1:
            dp_max[1][j] = max(max(dp_max[0][j-1], dp_max[0][j]), dp_max[0][j+1]) + matrix[j] 
            dp_min[1][j] = min(min(dp_min[0][j-1], dp_min[0][j]), dp_min[0][j+1]) + matrix[j] 
        elif j == 0:
            dp_max[1][j] = max(dp_max[0][j], dp_max[0][j+1]) + matrix[j] 
            dp_min[1][j] = min(dp_min[0][j], dp_min[0][j+1]) + matrix[j] 
        elif j == 2:
            dp_max[1][j] = max(dp_max[0][j-1], dp_max[0][j]) + matrix[j] 
            dp_min[1][j] = min(dp_min[0][j-1], dp_min[0][j]) + matrix[j] 
        
    for j in range(3):
        dp_max[0][j] = dp_max[1][j]
        dp_min[0][j] = dp_min[1][j]

print(max(dp_max[0]), min(dp_min[0]))