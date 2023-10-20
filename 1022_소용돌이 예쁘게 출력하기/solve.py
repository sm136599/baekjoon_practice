import sys
import time
readl = sys.stdin.readline
r1, c1, r2, c2 = map(int, readl().split())

ts = time.time()

def get(tarI, tarJ):
    r = max(abs(tarI-5000), abs(tarJ-5000))
    curI, curJ = r + 5000, r + 5000
    val = 2*r + 1

    tmp = val**2

    if curI == tarI and curJ == tarJ:
        return tmp
    
    for _ in range(val-1):
        curJ -= 1
        tmp -= 1
        if curI == tarI and curJ == tarJ:
            return tmp
        
    for _ in range(val-1):
        curI -= 1
        tmp -= 1
        if curI == tarI and curJ == tarJ:
            return tmp
        
    for _ in range(val-1):
        curJ += 1
        tmp -= 1
        if curI == tarI and curJ == tarJ:
            return tmp
        
    for _ in range(val-2):
        curI += 1
        tmp -= 1
        if curI == tarI and curJ == tarJ:
            return tmp
        
r1 += 5000
r2 += 5000
c1 += 5000
c2 += 5000
result = []
maxx = 0
for i in range(r1, r2 + 1):
    t = []
    for j in range(c1, c2 + 1):
        num = get(i, j)
        maxx = max(maxx, num)
        t.append(num)
    result.append(t)

length = len(str(maxx))
for i in result:
    for j in i:
        print(f'{j:{length}}', end=' ')
    print()

print(time.time() - ts)

