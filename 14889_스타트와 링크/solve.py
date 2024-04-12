N = int(input())
score = [list(map(int, input().split())) for _ in range(N)]
all = set([i for i in range(N)])

answer = 10000
def dfs(depth, idx):
    global score, N, answer, start
    if depth == N // 2:
        link = list(all.difference(set(start)))
        s, l = 0, 0
        for i in range(N//2):
            for j in range(i+1, N//2):
                s += score[start[i]][start[j]] + score[start[j]][start[i]]
                l += score[link[i]][link[j]] + score[link[j]][link[i]]
        answer = min(answer, abs(s - l))
        return
    
    for i in range(idx, N-((N//2)-depth)+1):
        start.append(i)
        dfs(depth+1, i+1)
        start.pop()

start = [0]
dfs(1, 1)
print(answer)