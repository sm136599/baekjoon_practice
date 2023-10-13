import sys

def Input_Data():
    readl = sys.stdin.readline
    N, M = map(int, readl().split())
    numbers = list(map(int, readl().split()))
    return N, M, numbers

N, M, numbers = Input_Data()
numbers = sorted(numbers)
l = [1 for _ in range(M)]

def make(start, depth):
    if depth > M:
        for i in l:
            print(numbers[i-1], end=' ')
        print()
        return
    for i in range(start, N+1):
        l[depth-1] = i
        make(i, depth+1)

make(1, 1)

