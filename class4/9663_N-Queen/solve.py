import sys

readl = sys.stdin.readline

N = int(readl())
cnt = 0
board = [0] * N
visited = [False] * N

def isOk(x):
    for i in range(x):
        if board[i] == board[x] or abs(board[i] - board[x]) == abs(i - x):
            return False
    return True

def bt(i):
    global cnt, visited

    if i == N:
        cnt += 1
        return 
    
    for k in range(N):
        if not visited[k]:
            board[i] = k
            if isOk(i):
                visited[k] = True
                bt(i+1)
                visited[k] = False

bt(0)
print(cnt)