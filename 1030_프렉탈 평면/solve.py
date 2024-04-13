s, N, K, R1, R2, C1, C2 = map(int, input().split())

cutting = [[0]*4 for _ in range(s+1)]

cutting[s] = [R1, R2, C1, C2]
for i in range(s-1, 0, -1):
    for j in range(4):
        cutting[i][j] = cutting[i+1][j] // N

for i in range(s, 0, -1):
    r1, c1 = cutting[i-1][0], cutting[i-1][2]
    
    cutting[i][0] -= r1*N 
    cutting[i][1] -= r1*N
    cutting[i][2] -= c1*N
    cutting[i][3] -= c1*N

def printArr(arr):
    r, c = len(arr), len(arr[0])
    for i in range(r):
        for j in range(c):
            print(f'{arr[i][j]}', end='')
        print()

def split(arr):
    global N, K
    r, c = len(arr), len(arr[0])
    spl = [[0] * c*N for _ in range(r*N)]
    for i in range(r):
        for j in range(c):
            if arr[i][j] == 0:
                pad = (N-K) // 2
                for k in range(i*N+pad, (i+1)*N-pad):
                    for l in range(j*N+pad, (j+1)*N-pad):
                        spl[k][l] = 1
            else:
                for k in range(i*N, (i+1)*N):
                    for l in range(j*N, (j+1)*N):
                        spl[k][l] = 1
    return spl

def cut(arr, toCut):
    r1, r2, c1, c2 = toCut
    cutted = [[0] * (c2-c1+1) for _ in range(r2-r1+1)]
    for i in range(r1, r2+1):
        for j in range(c1, c2+1):
            cutted[i-r1][j-c1] = arr[i][j]
    return cutted

answer = [[0]]
for i in range(1, s+1):
    answer = split(answer)
    answer = cut(answer, cutting[i])

printArr(answer)