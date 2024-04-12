from heapq import heappush, heappop

N = int(input())
stars = [list(map(float, input().split())) for _ in range(N)]

dist = [[0]*N for _ in range(N)]
min_dist = 2000
min_i = -1
min_j = -1
for i in range(N):
    for j in range(i+1, N):
        x1, y1 = stars[i]
        x2, y2 = stars[j]
        d = ((x1-x2)**2 + (y1-y2)**2)**0.5
        dist[i][j] = d
        dist[j][i] = d
        if d < min_dist:
            min_dist = d
            min_i = i
            min_j = j

sett = set([min_i, min_j])
distance = min_dist

while len(sett) < N:
    min_dist = 2000
    min_i = -1
    min_j = -1
    for i in sett:
        for j in range(N):
            if j not in sett:
                if dist[i][j] < min_dist:
                    min_dist = dist[i][j]
                    min_i = i
                    min_j = j
    sett.add(min_j) 
    distance += min_dist

print(f'{distance:.2f}')

