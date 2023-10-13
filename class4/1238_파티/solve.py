import sys
from collections import deque   

inf = 1000000

def Input_Data():
    readl = sys.stdin.readline
    N, M, X = map(int, readl().split())
    input = [list(map(int, readl().split())) for _ in range(M)]
    graph = [[] for _ in range(N + 1)]
    for (i, j, t) in input:
        graph[i].append((j, t))
    return N, M, X, graph

N, M, X, graph = Input_Data()

def getDist(s):
    global N, graph
    
    dist = [inf for _ in range(N+1)]

    visited = [False for _ in range(N+1)]

    dist[s] = 0
    current = s

    sett = set()
    while(True):
        visited[current] = True

        for i in range(len(graph[current])):
            to = graph[current][i][0]
            if visited[to]:
                continue

            sett.add(to)
            temp = dist[current] + graph[current][i][1]

            if temp < dist[to]:
                dist[to] = temp

        if current in sett:
            sett.remove(current)
        
        if len(sett) == 0:
            break

        minDist = inf
        index = 0

        for a in sett:
            if dist[a] < minDist:
                minDist = dist[a]
                index = a
        if index == X:
            return dist
        current = index
    
    return dist


# def DFS(node, dist):
#     global stack, visited, minD
#     stack.append(node)

#     if stack[len(stack) - 1] == X:
#         if minD > dist:
#             minD = dist
    
#         return 

#     for next in graph[node]:
#         if not visited[next[0]]:
#             if minD > dist + next[1]:
#                 visited[next[0]] = True
#                 DFS(next[0], dist + next[1])
#                 stack.pop()
#                 visited[next[0]] = False


short = [0 for _ in range(N+1)]

# for i in range(1, N+1):
#     if i == X:
#         continue
#     minD = inf
#     stack = deque()
#     visited = [False for _ in range(N+1)]
#     visited[i] = True

#     DFS(i, 0)
    
#     short[i] = minD

for i in range(1, N+1):
    if i == X:
        continue
    short[i] = getDist(i)[X]

temp = getDist(X)
for i in range(1, N+1):
    short[i] += temp[i]

print(max(short))