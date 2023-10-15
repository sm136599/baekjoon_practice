import sys
import heapq
from collections import deque
readl = sys.stdin.readline
N, K = map(int, readl().split())

min_time = 100_000

if N < K:
    heap = []
    heapq.heappush(heap, (0, N))
    cnt = 0
    visited = [False] * (K*2 + 1)
    visited[N] = True
    while heap:
        cnt += 1
        (time, num) = heapq.heappop(heap)
        if num == K:
            min_time = min(min_time, time)
            
        if min_time > time:
            if num*2 <= K*2:
                if not visited[num*2]:
                    visited[num*2] = True
                    heapq.heappush(heap, (time, num*2))
        if min_time > time + 1:
            if num+1 <= K*2:
                if not visited[num + 1]:
                    visited[num+1] = True
                    heapq.heappush(heap, (time + 1, num + 1))
            if num-1 >= 0:
                if not visited[num - 1]:
                    visited[num-1] = True
                    heapq.heappush(heap, (time + 1, num - 1))
else:
    min_time = N - K

# cnt = 0
# if N < K:
#     graph = [[] for _ in range(K*2 + 1)]
#     for i in range(K*2+1):
#         if i*2 <= K*2:
#             graph[i].append((0, i*2))
#         if i + 1 <= K*2:
#             graph[i].append((1, i + 1))
#         if i - 1 >= 0:
#             graph[i].append((1, i - 1))

#     visited = [False] * (K*2 + 1)
#     heap = []
#     heapq.heappush(heap, (0, N))
#     visited[N] = True
#     while heap:
#         cnt += 1
#         time, num = heapq.heappop(heap)

#         if num == K:
#             min_time = min(time, min_time)

        
#         for weight, next in graph[num]:
#             if not visited[next]:
#                 if min_time > time + weight:
#                     heapq.heappush(heap, (time + weight, next))
#                     visited[next] = True
# else:
#     min_time = N - K
print(min_time)