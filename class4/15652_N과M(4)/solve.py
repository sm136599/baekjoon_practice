import sys

def Input_Data():
    readl = sys.stdin.readline
    N, M = map(int, readl().split())
    return N, M

N, M = Input_Data()
l = [1 for _ in range(M)]

def make(start, depth):
    if depth > M:
        print(*l, sep=' ')
        return
    for i in range(start, N+1):
        l[depth-1] = i
        make(i, depth+1)

make(1, 1)

