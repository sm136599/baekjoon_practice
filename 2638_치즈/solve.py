import sys
from collections import deque

readl = sys.stdin.readline
N, M = map(int, readl().split())
cheese = [list(map(int, readl().split())) for _ in range(N)]

di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]

def updateOutside():
    global cheese, N, M
    visited = [[False] * M for _ in range(N)]
    q = deque()
    q.append((0, 0))
    visited[0][0] = True

    while q:
        i, j = q.popleft()

        for l in range(4):
            ii = i + di[l]
            jj = j + dj[l]

            if 0 <= ii < N and 0 <= jj < M:
                if visited[ii][jj]:
                    continue
                if cheese[ii][jj] >= 1:
                    cheese[ii][jj] += 1
                else:
                    visited[ii][jj] = True
                    q.append((ii, jj))

def updateCheese():
    global N, M, cheese, cheese_index
    to_remove = []
    for i, j in cheese_index:
        if cheese[i][j] >= 3:
            to_remove.append((i, j))
            cheese[i][j] = 0
        elif cheese[i][j] == 2:
            cheese[i][j] = 1

    for i, j in to_remove:
        cheese_index.remove((i, j))
    # 치즈가 다 없어지면 True 리턴
    return False if cheese_index else True

cheese_index = set()
for i in range(N):
    for j in range(M):
        if cheese[i][j] == 1:
            cheese_index.add((i, j))

t = 0
while True:
    updateOutside()
    done = updateCheese()

    t += 1
    if done:
        break

print(t)