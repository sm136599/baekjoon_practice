N, M = map(int, input().split())
mapp = [list(map(int, input().split())) for _ in range(N)]
cctvs = []
for i in range(N):
    for j in range(M):
        if mapp[i][j] == 0 or mapp[i][j] == 6:
            continue
        cctvs.append((mapp[i][j], i, j))

di = [-1, 0, 1, 0]
dj = [0, 1, 0, -1]

def see(i, j, dir, plus):
    global cctvs, N, M, mapp
    while True:
        i += di[dir]
        j += dj[dir]
        if 0<=i<N and 0<=j<M:
            if mapp[i][j] == 6:
                break
            if mapp[i][j] <= 0:
                mapp[i][j] += plus
        else:
            break

def count():
    global N, M, mapp
    cnt = 0
    for i in range(N):
        for j in range(M):
            if mapp[i][j] == 0:
                cnt += 1
    return cnt

def cctv5(i, j, dir, plus):
    for k in range(4):
        see(i, j, k, plus)

def cctv4(i, j, dir, plus):
    for k in range(3):
        see(i, j, (dir+k)%4, plus)

def cctv3(i, j, dir, plus):
    for k in range(2):
        see(i, j, (dir+k)%4, plus)

def cctv2(i, j, dir, plus):
    see(i, j, dir, plus)
    see(i, j, (dir+2)%4, plus)

def cctv1(i, j, dir, plus):
    see(i, j, dir, plus)

n = len(cctvs)
answer = 100

# cctv 함수들
# 원하는 방향으로 값을 변환한다.
cctvFunc = [None, cctv1, cctv2, cctv3, cctv4, cctv5]

def dfs(idx):
    global answer, n, stack, cctvs, mapp
    if idx == n:
        cnt = count()
        # print(*mapp, sep='\n')
        # print(cnt)
        # print()
        answer = min(answer, cnt)
        return
    
    num, i, j = cctvs[idx]
    if num == 1 or num == 3 or num == 4:
        # cctv가 1, 3, 4 면 네 방향
        for k in range(4):
            cctvFunc[num](i, j, k, -1)
            dfs(idx+1)
            cctvFunc[num](i, j, k, 1)
    elif num == 2:
        # 2면 두 방향
        for k in range(2):
            cctvFunc[num](i, j, k, -1)
            dfs(idx+1)
            cctvFunc[num](i, j, k, 1)
    elif num == 5:
        # 5면 한 방향
        cctvFunc[num](i, j, 0, -1)
        dfs(idx+1)
        cctvFunc[num](i, j, 0, 1)



stack = []
dfs(0)
print(answer)