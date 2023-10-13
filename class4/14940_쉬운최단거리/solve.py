import sys
from collections import deque
def Input_Data():
    readl = sys.stdin.readline
    n, m = map(int, readl().split())
    MAP = [list(map(int, readl().split())) for _ in range(n)]
    return n, m, MAP

n, m, MAP = Input_Data()

start = (-1, -1)
for i in range(n):
    for j in range(m):
        if MAP[i][j] == 2:
            start = (i, j)

di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]

visited = [[False]*m for _ in range(n)]
visited[start[0]][start[1]] = True

q = deque()
q.append((start[0], start[1], 0))

result = [[-1] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if MAP[i][j] == 0:
            result[i][j] = 0

while q:
    pi, pj, dist = q.popleft()
    result[pi][pj] = dist

    for i in range(4):
        ii = pi + di[i]
        jj = pj + dj[i]

        if 0 <= ii < n and 0 <= jj < m:
            if not visited[ii][jj] and MAP[ii][jj] == 1:
                visited[ii][jj] = True
                q.append((ii, jj, dist + 1))
                
for i in range(n):
    for j in range(m):
        print(result[i][j], end=" ")
    print()