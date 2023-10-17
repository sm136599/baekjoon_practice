import sys
import heapq

readl = sys.stdin.readline

n = int(readl())
m = int(readl())
input = [list(map(int, readl().split())) for _ in range(m)]

inf = 10000000000
graph = [[inf] * (n+1) for _ in range(n+1)]
for a, b, c in input:
    graph[a][b] = min(graph[a][b], c)

for k in range(1, n+1):
    graph[k][k] = 0
    for i in range(1, n+1):
        for j in range(1, n+1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

for i in range(1, n+1):
    for j in range(1, n+1):
        print(0 if graph[i][j] >= inf else graph[i][j], end=' ')
    print()

# graph = [[] for _ in range(n+1)]
# for a, b, c in input:
#     graph[a].append((b, c))

# inf = 10000000000

# def dijkstra_dist(node):
#     dist = [inf] * (n+1)
#     heap = []
#     visited = [False] * (n+1)

#     heapq.heappush(heap, (0, node))
#     dist[node] = 0
    
#     while heap:
#         length, current = heapq.heappop(heap)
#         if visited[current]:
#             continue

#         visited[current] = True

#         for next, weight in graph[current]:
#             if dist[next] > length + weight:
#                 dist[next] = length + weight
#                 heapq.heappush(heap, (length+weight, next))

#     return dist

# for i in range(1, n+1):
#     for j in dijkstra_dist(i)[1:]:
#         print(0 if j >= inf else j, end=' ')
#     print()