import sys
from collections import deque

def Input_Data():
    readl = sys.stdin.readline
    V = int(readl())
    input = [list(map(int, readl().split())) for _ in range(V)]
    Tree = [[] for _ in range(V+1)]
    for i in range(V):
        for j in range(1, len(input[i]) - 2, 2):
            Tree[input[i][0]].append((input[i][j], input[i][j + 1]))
    return V, Tree

V, Tree = Input_Data()

def BFS(start):
    global max, maxnode
    visited = [False for _ in range(V + 1)]
    q = deque()

    visited[start] = True
    q.append((start, 0))

    while q:
        node, length = q.pop()

        if max < length:
            max = length
            maxnode = node

        for next, nlen in Tree[node]:
            if not visited[next]:
                visited[next] = True
                q.append((next, length + nlen))

# use BFS
max = 0
maxnode = -1
BFS(1)

max = 0
BFS(maxnode)


            
print(max)