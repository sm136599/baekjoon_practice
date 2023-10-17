import sys
import heapq

readl = sys.stdin.readline

n = int(readl())
m = int(readl())
input = [list(map(int, readl().split())) for _ in range(m)]
graph = [[] for _ in range(n+1)]
for a, b, c in input:
    graph[a].append((b, c))

inf = 10000000000

def dijkstra_dist(node):
    dist = [inf] * (n+1)
    heap = []
    visited = [False] * (n+1)

    heapq.heappush(heap, (0, node))
    dist[node] = 0
    
    while heap:
        length, current = heapq.heappop(heap)
        if visited[current]:
            continue

        visited[current] = True

        for next, weight in graph[current]:
            if dist[next] > length + weight:
                dist[next] = length + weight
                heapq.heappush(heap, (length+weight, next))

    return dist

for i in range(1, n+1):
    for j in dijkstra_dist(i)[1:]:
        print(0 if j >= inf else j, end=' ')
    print()