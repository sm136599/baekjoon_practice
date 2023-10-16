import sys
import time


readl = sys.stdin.readline

N = int(readl())
t_s = time.time()
cnt = 0
stack = []
visited = [False] * N

def isOk(stack, N, l, m):
    for mm in range(m+1, N*2):
        ll = l + m - mm
        if 0 <= ll < N:
            if stack[ll] == mm or stack[ll] == m*2 - mm:
                return False
    return True

def bt(i, j):
    global cnt, stack, board, N, visited

    if i == N-1:
        cnt += 1
        return 
    
    for k in range(N):
        if not visited[k]:
            if stack[i] == k -1 or stack[i] == k+1:
                continue
            
            if isOk(stack, N, i+1, k):
                stack.append(k)
                visited[k] = True
                bt(i+1, k)
                stack.pop()
                visited[k] = False

    

for i in range(N):
    stack.append(i)
    visited[i] = True
    bt(0, i)
    stack.pop()
    visited[i] = False

print(cnt)
print(time.time() - t_s)