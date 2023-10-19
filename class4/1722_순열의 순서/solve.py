import sys

readl = sys.stdin.readline
N = int(readl())
input = list(map(int, readl().split()))

def fact(n):
    f = 1
    for i in range(1,n+1):
        f *= i
    return f

if input[0] == 1:
    k = input[1]
    total_num = fact(N)
    sett = set()
    for i in range(1, N+1):
        sett.add(i)

    while sett:
        n = len(sett)

        current = -1
        for i, num in enumerate(sett, 1):
            if total_num * i // n >= k:
                current = num
                print(current, end=' ')
                k = k - total_num * (i-1) // n
                break
        
        total_num //= n
        sett.remove(current)
else:
    answer = 1
    check = input[1:]
    total_num = fact(N)
    sett = set()
    for i in range(1, N+1):
        sett.add(i)

    i = 0
    while sett:
        n = len(sett)

        current = -1
        for idx, num in enumerate(sett, 1):
            if num == check[i]:
                current = num
                answer += total_num * (idx-1) // n
                break

        total_num //= n
        sett.remove(current)
        i += 1
    
    print(answer)


