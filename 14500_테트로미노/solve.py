N, M = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]

answer = 0
di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]

def dfs(i, j, depth, score):
    global answer, visited, paper, maxx
    if answer >= score + maxx*(4-depth):
        return
    if depth >= 4:
        answer = max(answer, score)
        return
    
    for k in range(4):
        ni = i + di[k]
        nj = j + dj[k]

        if 0<=ni<N and 0<=nj<M:
            if visited[ni][nj]:
                continue
            visited[ni][nj] = True
            dfs(ni, nj, depth+1, score+paper[ni][nj])
            visited[ni][nj] = False

            if depth == 2:
                visited[ni][nj] = True
                dfs(i, j, depth+1, score+paper[ni][nj])
                visited[ni][nj] = False

maxx = 0
for i in range(N):
    maxx = max(maxx, max(paper[i]))
for i in range(N):
    for j in range(M):
        visited[i][j] = True
        dfs(i, j, 1, paper[i][j])
        visited[i][j] = False

print(answer)