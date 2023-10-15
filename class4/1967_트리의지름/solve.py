import sys
readl = sys.stdin.readline
n = int(readl())
inp = [list(map(int, readl().split())) for _ in range(n-1)]
tree = [[] for _ in range(n+1)]
for u, v, w in inp:
    tree[u].append((v, w))
    tree[v].append((u, w))


sys.setrecursionlimit(10000)

def DFS(node, length):
    global idx, max_len, visited
    visited[node] = True
    if len(tree[node]) == 1:
        if max_len < length:
            max_len = length
            idx = node

    for next, w in tree[node]:
        if not visited[next]:
            DFS(next, length + w)

max_len = 0
idx = 0
visited = [False] * (n+1)
DFS(1, 0)


visited = [False] * (n+1)
DFS(idx, 0)
print(max_len)

