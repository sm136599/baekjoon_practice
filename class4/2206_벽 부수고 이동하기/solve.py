import sys
from heapq import heappush, heappop
from collections import deque

readl = sys.stdin.readline
n, m = map(int, readl().split())
mapp = [list(map(int, readl().strip())) for _ in range(n)]

di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]
# maxnum = 10000000
# answer = maxnum

# pq = []
# # length, i, j, chance(to break wall)
# heappush(pq, (1, 0, 0, True))
# visited = [[False] * m for _ in range(n)]


# while pq:
#     length, i, j, chance = heappop(pq)
#     visited[i][j] = True
#     if i == n-1 and j == m-1:
#         answer = min(answer, length)

#     for l in range(4):
#         ii = i + di[l]
#         jj = j + dj[l]

        
#         if 0 <= ii < n and 0 <= jj < m:
#             if visited[ii][jj]:
#                 continue
            
#             if chance:
#                 if mapp[ii][jj] == 1:
#                     visited[ii][jj] == True
#                     heappush(pq, (length+1, ii, jj, False))
#                 else:
#                     visited[ii][jj] = True
#                     heappush(pq, (length+1, ii, jj, True))
#             else:
#                 if mapp[ii][jj] == 0:
#                     visited[ii][jj] = True
#                     heappush(pq, (length+1, ii, jj, False))
    

q = deque()
# length, i, j, chance(to break wall)
q.append((0, 0, 0))
visited = [[[0, 0] for _ in range(m)] for _ in range(n)]
visited[0][0][0] = 1
answer = -1

while q:
    i, j, wall = q.popleft()
    if i == n-1 and j == m-1:
        answer = visited[i][j][wall]
        break
    for l in range(4):
        ii = i + di[l]
        jj = j + dj[l]
        
        if 0 <= ii < n and 0 <= jj < m:
            if visited[ii][jj][wall] != 0:
                continue
            
            if mapp[ii][jj] == 0:
                q.append((ii, jj, wall))
                visited[ii][jj][wall] = visited[i][j][wall] + 1
            
            if wall == 0 and mapp[ii][jj] == 1:
                q.append((ii, jj, 1))
                visited[ii][jj][1] = visited[i][j][0] + 1
print(answer)