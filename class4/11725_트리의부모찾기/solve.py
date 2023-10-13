import sys
from collections import deque

def Input_Data():
    readl = sys.stdin.readline
    N = int(readl())
    input = [list(map(int, readl().split())) for _ in range(N-1)]
    tree = [[] for _ in range(N+1)]
    for u, v in input:
        tree[u].append(v)
        tree[v].append(u)
    return N, tree

N, tree = Input_Data()

q = deque()
q.append(1)
visited = [False for _ in range(N+1)]
visited[1] = True

answer = [0] * (N+1)

while q:
    node = q.popleft()

    for next in tree[node]:
        if not visited[next]:
            visited[next] = True
            q.append(next)
            answer[next] = node

print(*answer[2:], sep='\n')
