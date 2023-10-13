import sys
import heapq

def Input_Data():
    readl = sys.stdin.readline
    N = int(readl())
    M = int(readl())
    input = [list(map(int, readl().split())) for _ in range(M)]
    input = sorted(input, key=lambda x: x[2])
    graph = [[] for _ in range(N+1)]
    for u, v, w in input:
        graph[u].append((v, w))
    A, B = map(int, readl().split())
    return N, M, graph, A, B

N, M, graph, A, B = Input_Data()

# N (1 <= N <= 1,000), M (1 <= M <= 100,000), w (0 <= w < 100,000)
inf = 10_000_000_000

answer = inf

def DFS(node, dist):
    global answer, B, visited
    if node == B:
        if answer > dist:
            answer = dist
            return
    
    for next, weight in graph[node]:
        if dist + weight < answer and not visited[next]:
            visited[next] = True
            DFS(next, dist + weight)
            visited[next] = False

visited = [False for _ in range(N+1)]
DFS(A, 0)

print(answer)