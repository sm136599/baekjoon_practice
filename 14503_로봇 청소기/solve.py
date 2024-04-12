N, M = map(int, input().split())
x, y, d = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(N)]

di = [-1, 0, 1, 0]
dj = [0, 1, 0, -1]

def check(i, j, dir):
    global room
    for _ in range(4):
        dir = (dir+3) % 4
        ni, nj = i+di[dir], j+dj[dir]
        if room[ni][nj] == 0:
            return ni, nj, dir
    
    return -1, -1, dir
    
cnt = 0
pi, pj = -1, -1
while True:
    if pi == x and pj == y:
        break
    pi, pj = x, y
    if room[x][y] == 0:
        cnt += 1
        room[x][y] = 2

    ni, nj, d = check(x, y, d)
    # 청소 안된 구역이 주변에 없을 경우
    if ni == -1 and nj == -1:
        ni, nj = x + di[(d+2) % 4], y + dj[(d+2) % 4]
        if room[ni][nj] == 1:
            continue
        else:
            x, y = ni, nj
    else:
        x, y = ni, nj

print(cnt)