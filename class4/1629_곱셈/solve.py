import sys
def Input_Data():
    readl = sys.stdin.readline
    a, b, c = map(int, readl().split())
    return a, b, c

a, b, c = Input_Data()

def multi(a, n):
    global c
    if n == 1:
        return a % c
    else:
        temp = multi(a, n // 2)
        if n % 2:
            return (temp * temp * a) % c
        else:
            return (temp * temp) % c
    
print(multi(a, b))