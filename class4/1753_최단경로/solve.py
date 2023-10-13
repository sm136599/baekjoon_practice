import sys
import heapq

def Input_Data():
    readl = sys.stdin.readline
    V, E = map(int, readl().split())
    start = int(readl())
    input = [map(int, readl().split()) for _ in range(E)]
    graph = [[] for _ in range(V+1)]
    for (u, v, w) in input:
        graph[u].append((v, w))
    return V, start, graph

inf = 1000000

V, start, graph = Input_Data()

def dijkstra_dist(s):
    global V, graph, inf
    
    dist = [inf for _ in range(V+1)]
    dist[s] = 0
    heap = []
    
    heapq.heappush(heap, (0, s))
    while heap:
        w, current = heapq.heappop(heap)

        if dist[current] < w:
            continue

        for to, weight in graph[current]:
            to_weight = w + weight

            if to_weight < dist[to]:
                dist[to] = to_weight
                heapq.heappush(heap, (to_weight, to))

    return dist

dist = dijkstra_dist(start)
for i in range(1, len(dist)):
    if dist[i] >= inf:
        print('INF')
    else:
        print(dist[i])