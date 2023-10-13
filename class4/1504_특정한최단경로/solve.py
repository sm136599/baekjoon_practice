import sys

inf = 1000000000

def Input_Data():
    readl = sys.stdin.readline
    N, E = map(int, readl().split())
    input = [list(map(int, readl().split())) for _ in range(E)]
    graph = [[] for _ in range(N + 1)]
    for (i, j, t) in input:
        graph[i].append((j, t))
        graph[j].append((i, t))
    v1, v2 = map(int, readl().split())
    return N, graph, v1, v2

N, graph, v1, v2 = Input_Data()

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
        current = index
    
    return dist

dijk_1 = getDist(1)
dijk_v1 = getDist(v1)
dijk_v2 = getDist(v2)

answer1 = dijk_1[v1] + dijk_v1[v2] + dijk_v2[N]
answer2 = dijk_1[v2] + dijk_v2[v1] + dijk_v1[N]

answer = min(answer1, answer2)
if answer >= inf:
    print(-1)
else:
    print(answer)