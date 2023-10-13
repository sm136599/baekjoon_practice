import sys
def Input_Data():
    readl = sys.stdin.readline
    N, M = map(int, readl().split())
    numbers = list(map(int, readl().split()))
    tests = [list(map(int, readl().split())) for i in range(M)]
    return N, M, numbers, tests

N, M, numbers, tests = Input_Data()

sums = [0 for _ in range(N+1)]
sums[1] = numbers[0]
for i in range(2, N + 1):
    sums[i] = sums[i-1] + numbers[i-1]

for test in tests:
    print(sums[test[1]] - sums[test[0]-1])
