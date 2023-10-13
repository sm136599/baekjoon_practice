import sys
import heapq

def Input_Data():
    readl = sys.stdin.readline
    N = int(readl())
    M = int(readl())
    input = [list(map(int, readl().split())) for _ in range(M)]
    graph = [[] for _ in range(N+1)]
    for u, v, w in input:
        graph[u].append((v, w))
    A, B = map(int, readl().split())
    return N, M, graph, A, B

N, M, graph, A, B = Input_Data()

# N (1 <= N <= 1,000), M (1 <= M <= 100,000), w (0 <= w < 100,000)
inf = 10_000_000_000

def dijkstra_dist(start):
    global graph, N
    dist = [inf for _ in range(N+1)]
    dist[start] = 0
    heap = []
    heapq.heappush(heap, (0, start))

    while heap:
        distance, now = heapq.heappop(heap)

        if dist[now] < distance:
            continue

        for next, weight in graph[now]:
            if distance + weight < dist[next]:
                dist[next] = distance + weight
                heapq.heappush(heap, (distance + weight, next))
    
    return dist

print(dijkstra_dist(A)[B])
